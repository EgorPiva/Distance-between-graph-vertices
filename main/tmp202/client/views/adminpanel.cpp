#include "adminpanel.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QHeaderView>
#include <QMessageBox>
#include <QInputDialog>
#include <QDateTime>

AdminPanel::AdminPanel(QWidget *parent)
    : QWidget(parent)
    , m_networkManager(new QNetworkAccessManager(this))
{
    setupUI();
    setupConnections();
    loadUsers();
    loadCalculations();
    loadStatistics();
}

void AdminPanel::setupUI()
{
    // Main layout
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    // Create tab widget
    m_tabWidget = new QTabWidget(this);
    
    // Users tab
    QWidget *usersTab = new QWidget();
    QVBoxLayout *usersLayout = new QVBoxLayout(usersTab);
    
    // User table
    m_userTable = new QTableWidget();
    m_userTable->setColumnCount(5);
    m_userTable->setHorizontalHeaderLabels({"ID", "Username", "Role", "Last Login", "Status"});
    m_userTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    usersLayout->addWidget(m_userTable);

    // User buttons
    QHBoxLayout *userButtonsLayout = new QHBoxLayout();
    m_addUserButton = new QPushButton("Add User");
    m_editUserButton = new QPushButton("Edit User");
    m_deleteUserButton = new QPushButton("Delete User");
    userButtonsLayout->addWidget(m_addUserButton);
    userButtonsLayout->addWidget(m_editUserButton);
    userButtonsLayout->addWidget(m_deleteUserButton);
    usersLayout->addLayout(userButtonsLayout);

    // Calculations tab
    QWidget *calculationsTab = new QWidget();
    QVBoxLayout *calculationsLayout = new QVBoxLayout(calculationsTab);
    
    // Calculation table
    m_calculationTable = new QTableWidget();
    m_calculationTable->setColumnCount(4);
    m_calculationTable->setHorizontalHeaderLabels({"ID", "User", "Date", "Status"});
    m_calculationTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    calculationsLayout->addWidget(m_calculationTable);

    // Calculation buttons
    QHBoxLayout *calcButtonsLayout = new QHBoxLayout();
    m_deleteCalculationButton = new QPushButton("Delete Calculation");
    calcButtonsLayout->addWidget(m_deleteCalculationButton);
    calculationsLayout->addLayout(calcButtonsLayout);

    // Add tabs
    m_tabWidget->addTab(usersTab, "Users");
    m_tabWidget->addTab(calculationsTab, "Calculations");

    // Statistics section
    QWidget *statsWidget = new QWidget();
    QHBoxLayout *statsLayout = new QHBoxLayout(statsWidget);
    
    m_totalUsersLabel = new QLabel("Total Users: 0");
    m_activeUsersLabel = new QLabel("Active Users: 0");
    m_totalCalculationsLabel = new QLabel("Total Calculations: 0");
    m_lastUpdateLabel = new QLabel("Last Update: Never");
    
    statsLayout->addWidget(m_totalUsersLabel);
    statsLayout->addWidget(m_activeUsersLabel);
    statsLayout->addWidget(m_totalCalculationsLabel);
    statsLayout->addWidget(m_lastUpdateLabel);

    // Refresh button
    m_refreshButton = new QPushButton("Refresh");
    
    // Add all components to main layout
    mainLayout->addWidget(m_tabWidget);
    mainLayout->addWidget(statsWidget);
    mainLayout->addWidget(m_refreshButton);
}

void AdminPanel::setupConnections()
{
    connect(m_tabWidget, &QTabWidget::currentChanged, this, &AdminPanel::onUserTabChanged);
    connect(m_refreshButton, &QPushButton::clicked, this, &AdminPanel::onRefreshClicked);
    connect(m_addUserButton, &QPushButton::clicked, this, &AdminPanel::onAddUserClicked);
    connect(m_editUserButton, &QPushButton::clicked, this, &AdminPanel::onEditUserClicked);
    connect(m_deleteUserButton, &QPushButton::clicked, this, &AdminPanel::onDeleteUserClicked);
    connect(m_deleteCalculationButton, &QPushButton::clicked, this, &AdminPanel::onDeleteCalculationClicked);
    connect(m_networkManager, &QNetworkAccessManager::finished, this, &AdminPanel::onNetworkReply);
}

void AdminPanel::loadUsers()
{
    QNetworkRequest request(QUrl("http://localhost:8080/api/admin/users"));
    m_networkManager->get(request);
}

void AdminPanel::loadCalculations()
{
    QNetworkRequest request(QUrl("http://localhost:8080/api/admin/calculations"));
    m_networkManager->get(request);
}

void AdminPanel::loadStatistics()
{
    QNetworkRequest request(QUrl("http://localhost:8080/api/admin/statistics"));
    m_networkManager->get(request);
}

void AdminPanel::updateUserTable(const QJsonArray &users)
{
    m_userTable->setRowCount(0);
    for (const QJsonValue &userValue : users) {
        QJsonObject user = userValue.toObject();
        int row = m_userTable->rowCount();
        m_userTable->insertRow(row);
        
        m_userTable->setItem(row, 0, new QTableWidgetItem(QString::number(user["id"].toInt())));
        m_userTable->setItem(row, 1, new QTableWidgetItem(user["username"].toString()));
        m_userTable->setItem(row, 2, new QTableWidgetItem(user["role"].toString()));
        m_userTable->setItem(row, 3, new QTableWidgetItem(user["lastLogin"].toString()));
        m_userTable->setItem(row, 4, new QTableWidgetItem(user["active"].toBool() ? "Active" : "Inactive"));
    }
}

void AdminPanel::updateCalculationTable(const QJsonArray &calculations)
{
    m_calculationTable->setRowCount(0);
    for (const QJsonValue &calcValue : calculations) {
        QJsonObject calc = calcValue.toObject();
        int row = m_calculationTable->rowCount();
        m_calculationTable->insertRow(row);
        
        m_calculationTable->setItem(row, 0, new QTableWidgetItem(QString::number(calc["id"].toInt())));
        m_calculationTable->setItem(row, 1, new QTableWidgetItem(calc["username"].toString()));
        m_calculationTable->setItem(row, 2, new QTableWidgetItem(calc["date"].toString()));
        m_calculationTable->setItem(row, 3, new QTableWidgetItem(calc["status"].toString()));
    }
}

void AdminPanel::updateStatistics(const QJsonObject &stats)
{
    m_totalUsersLabel->setText(QString("Total Users: %1").arg(stats["total_users"].toInt()));
    m_activeUsersLabel->setText(QString("Active Users: %1").arg(stats["active_users"].toInt()));
    m_totalCalculationsLabel->setText(QString("Total Calculations: %1").arg(stats["total_calculations"].toInt()));
    m_lastUpdateLabel->setText(QString("Last Update: %1").arg(QDateTime::currentDateTime().toString()));
}

void AdminPanel::onUserTabChanged(int index)
{
    if (index == 0) {
        loadUsers();
    }
}

void AdminPanel::onCalculationTabChanged(int index)
{
    if (index == 1) {
        loadCalculations();
    }
}

void AdminPanel::onRefreshClicked()
{
    loadUsers();
    loadCalculations();
    loadStatistics();
}

void AdminPanel::onAddUserClicked()
{
    bool ok;
    QString username = QInputDialog::getText(this, "Add User", "Username:", QLineEdit::Normal, "", &ok);
    if (ok && !username.isEmpty()) {
        QJsonObject user;
        user["username"] = username;
        user["role"] = "user";
        user["active"] = true;

        QNetworkRequest request(QUrl("http://localhost:8080/api/admin/users"));
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
        m_networkManager->post(request, QJsonDocument(user).toJson());
    }
}

void AdminPanel::onEditUserClicked()
{
    QList<QTableWidgetItem*> selectedItems = m_userTable->selectedItems();
    if (selectedItems.isEmpty()) {
        QMessageBox::warning(this, "Warning", "Please select a user to edit");
        return;
    }

    int row = selectedItems.first()->row();
    int userId = m_userTable->item(row, 0)->text().toInt();
    QString currentUsername = m_userTable->item(row, 1)->text();

    bool ok;
    QString newUsername = QInputDialog::getText(this, "Edit User", "New username:", 
                                              QLineEdit::Normal, currentUsername, &ok);
    if (ok && !newUsername.isEmpty()) {
        QJsonObject user;
        user["id"] = userId;
        user["username"] = newUsername;

        QNetworkRequest request(QUrl(QString("http://localhost:8080/api/admin/users/%1").arg(userId)));
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
        m_networkManager->put(request, QJsonDocument(user).toJson());
    }
}

void AdminPanel::onDeleteUserClicked()
{
    QList<QTableWidgetItem*> selectedItems = m_userTable->selectedItems();
    if (selectedItems.isEmpty()) {
        QMessageBox::warning(this, "Warning", "Please select a user to delete");
        return;
    }

    int row = selectedItems.first()->row();
    int userId = m_userTable->item(row, 0)->text().toInt();

    QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirm Delete",
        "Are you sure you want to delete this user?",
        QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        QNetworkRequest request(QUrl(QString("http://localhost:8080/api/admin/users/%1").arg(userId)));
        m_networkManager->deleteResource(request);
    }
}

void AdminPanel::onDeleteCalculationClicked()
{
    QList<QTableWidgetItem*> selectedItems = m_calculationTable->selectedItems();
    if (selectedItems.isEmpty()) {
        QMessageBox::warning(this, "Warning", "Please select a calculation to delete");
        return;
    }

    int row = selectedItems.first()->row();
    int calcId = m_calculationTable->item(row, 0)->text().toInt();

    QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirm Delete",
        "Are you sure you want to delete this calculation?",
        QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        QNetworkRequest request(QUrl(QString("http://localhost:8080/api/admin/calculations/%1").arg(calcId)));
        m_networkManager->deleteResource(request);
    }
}

void AdminPanel::onNetworkReply(QNetworkReply *reply)
{
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray data = reply->readAll();
        QJsonDocument doc = QJsonDocument::fromJson(data);
        
        QString path = reply->request().url().path();
        if (path.contains("/api/admin/users")) {
            if (reply->operation() == QNetworkAccessManager::GetOperation) {
                updateUserTable(doc.array());
            }
        } else if (path.contains("/api/admin/calculations")) {
            if (reply->operation() == QNetworkAccessManager::GetOperation) {
                updateCalculationTable(doc.array());
            }
        } else if (path.contains("/api/admin/statistics")) {
            updateStatistics(doc.object());
        }
    } else {
        QMessageBox::critical(this, "Error", "Network error: " + reply->errorString());
    }
    
    reply->deleteLater();
} 