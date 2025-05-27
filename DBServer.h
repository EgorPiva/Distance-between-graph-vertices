#ifndef DBSERVER_H
#define DBSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QSqlDatabase>
#include <QCryptographicHash>
#include <QMap>

class DBServer : public QObject
{
    Q_OBJECT
public:
    static DBServer& instance(quint16 port = 5432);

    bool startServer();
    void stopServer();

    DBServer(const DBServer&) = delete;
    DBServer& operator=(const DBServer&) = delete;
    ~DBServer(); // Добавлен деструктор

private:
    explicit DBServer(quint16 port, QObject *parent = nullptr);

    void setupDatabase();
    void processClientRequest(QTcpSocket* clientSocket);
    QString hashPassword(const QString &password);
    bool registerUser(const QString &username, const QString &password);
    bool authenticateUser(const QString &username, const QString &password);

    quint16 m_port;
    QTcpServer* m_tcpServer;
    QSqlDatabase m_db;
    QMap<QTcpSocket*, QString> m_authenticatedUsers;
};

#endif // DBSERVER_H
