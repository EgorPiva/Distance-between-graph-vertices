#include "mainwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , m_adminPanel(nullptr)
    , m_isAdmin(false)
{
    // Создаем центральный виджет
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    // Создаем главный layout
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);

    // Создаем кнопку админ-панели
    m_adminButton = new QPushButton("Админ-панель", this);
    m_adminButton->setEnabled(false); // Изначально отключена
    mainLayout->addWidget(m_adminButton);

    // Подключаем сигналы
    connect(m_adminButton, &QPushButton::clicked, this, &MainWindow::onAdminPanelClicked);

    // Проверяем права доступа при запуске
    checkAdminAccess();

    // Устанавливаем размер окна
    resize(800, 600);
}

void MainWindow::checkAdminAccess()
{
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QNetworkRequest request(QUrl("http://localhost:8080/api/auth/check-admin"));
    
    // Добавляем заголовок с токеном авторизации (если есть)
    // request.setRawHeader("Authorization", "Bearer " + token.toUtf8());

    QNetworkReply *reply = manager->get(request);

    connect(reply, &QNetworkReply::finished, [this, reply]() {
        if (reply->error() == QNetworkReply::NoError) {
            QByteArray data = reply->readAll();
            QJsonDocument doc = QJsonDocument::fromJson(data);
            QJsonObject obj = doc.object();
            
            m_isAdmin = obj["isAdmin"].toBool();
            m_adminButton->setEnabled(m_isAdmin);
        } else {
            QMessageBox::warning(this, "Ошибка", "Не удалось проверить права доступа");
        }
        
        reply->deleteLater();
    });
}

void MainWindow::onAdminPanelClicked()
{
    if (!m_isAdmin) {
        QMessageBox::warning(this, "Доступ запрещен", 
            "У вас нет прав для доступа к админ-панели");
        return;
    }

    if (!m_adminPanel) {
        m_adminPanel = new AdminPanel(this);
    }

    // Показываем админ-панель в отдельном окне
    m_adminPanel->setWindowModality(Qt::ApplicationModal);
    m_adminPanel->show();
} 