#include "DBServer.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QStringList>

DBServer& DBServer::instance(quint16 port)
{
    static DBServer inst(port);
    return inst;
}

DBServer::DBServer(quint16 port, QObject *parent)
    : QObject(parent), m_port(port), m_tcpServer(nullptr)
{
    setupDatabase();
}

DBServer::~DBServer()
{
    stopServer();
    qDebug() << "DBServer destroyed";
}

void DBServer::setupDatabase()
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("user_database.db");

    if (!m_db.open()) {
        qCritical() << "Failed to open database:" << m_db.lastError().text();
    } else {
        QSqlQuery query;
        query.exec("CREATE TABLE IF NOT EXISTS users ("
                   "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                   "username TEXT UNIQUE NOT NULL, "
                   "password_hash TEXT NOT NULL)");
    }
}

QString DBServer::hashPassword(const QString &password)
{
    return QCryptographicHash::hash(password.toUtf8(),
                                    QCryptographicHash::Sha256).toHex();
}

bool DBServer::registerUser(const QString &username, const QString &password)
{
    QSqlQuery query;
    query.prepare("INSERT INTO users (username, password_hash) VALUES (?, ?)");
    query.addBindValue(username);
    query.addBindValue(hashPassword(password));
    return query.exec();
}

bool DBServer::authenticateUser(const QString &username, const QString &password)
{
    QSqlQuery query;
    query.prepare("SELECT password_hash FROM users WHERE username = ?");
    query.addBindValue(username);

    if (query.exec() && query.next()) {
        return query.value(0).toString() == hashPassword(password);
    }
    return false;
}

bool DBServer::startServer()
{
    if (m_tcpServer) return true;

    m_tcpServer = new QTcpServer(this);
    if (!m_tcpServer->listen(QHostAddress::Any, m_port)) {
        qCritical() << "Server start failed:" << m_tcpServer->errorString();
        return false;
    }

    connect(m_tcpServer, &QTcpServer::newConnection, this, [this]() {
        QTcpSocket* client = m_tcpServer->nextPendingConnection();
        connect(client, &QTcpSocket::readyRead, this, [this, client]() {
            processClientRequest(client);
        });
        connect(client, &QTcpSocket::disconnected, this, [this, client]() {
            m_authenticatedUsers.remove(client);
            client->deleteLater();
        });
    });

    qInfo() << "Server started on port" << m_port;
    return true;
}

void DBServer::stopServer()
{
    if (m_tcpServer) {
        m_tcpServer->close();
        delete m_tcpServer;
        m_tcpServer = nullptr;
    }
    if (m_db.isOpen()) {
        m_db.close();
    }
}

void DBServer::processClientRequest(QTcpSocket* clientSocket)
{
    QString request = QString::fromUtf8(clientSocket->readAll()).trimmed();
    QString response;
    QStringList parts = request.split(' ');

    if (parts.isEmpty()) {
        response = "ERROR Empty request";
    }
    else if (parts[0] == "REGISTER" && parts.size() == 3) {
        if (registerUser(parts[1], parts[2])) {
            response = "OK Registration successful";
        } else {
            response = "ERROR Registration failed (user may exist)";
        }
    }
    else if (parts[0] == "LOGIN" && parts.size() == 3) {
        if (authenticateUser(parts[1], parts[2])) {
            m_authenticatedUsers[clientSocket] = parts[1];
            response = "OK Login successful";
        } else {
            response = "ERROR Invalid credentials";
        }
    }
    else if (parts[0] == "LOGOUT") {
        m_authenticatedUsers.remove(clientSocket);
        response = "OK Logged out";
    }
    else if (m_authenticatedUsers.contains(clientSocket)) {
        if (parts[0] == "WHOAMI") {
            response = "OK You are: " + m_authenticatedUsers[clientSocket];
        }
        else {
            response = "OK Command received (authenticated)";
        }
    }
    else {
        response = "ERROR Unknown command or not authenticated\n"
                   "Available commands:\n"
                   "REGISTER <username> <password>\n"
                   "LOGIN <username> <password>\n"
                   "LOGOUT\n"
                   "WHOAMI";
    }

    clientSocket->write(response.toUtf8());
    clientSocket->flush();
}
