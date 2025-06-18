#ifndef ADMINPANEL_H
#define ADMINPANEL_H

#include <QWidget>
#include <QTabWidget>
#include <QTableWidget>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QDateTime>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

class AdminPanel : public QWidget
{
    Q_OBJECT

public:
    explicit AdminPanel(QWidget *parent = nullptr);

private slots:
    void onUserTabChanged(int index);
    void onCalculationTabChanged(int index);
    void onRefreshClicked();
    void onAddUserClicked();
    void onEditUserClicked();
    void onDeleteUserClicked();
    void onDeleteCalculationClicked();
    void onNetworkReply(QNetworkReply *reply);

private:
    void setupUI();
    void setupConnections();
    void loadUsers();
    void loadCalculations();
    void loadStatistics();
    void updateUserTable(const QJsonArray &users);
    void updateCalculationTable(const QJsonArray &calculations);
    void updateStatistics(const QJsonObject &stats);

    // UI Components
    QTabWidget *m_tabWidget;
    QTableWidget *m_userTable;
    QTableWidget *m_calculationTable;
    QPushButton *m_refreshButton;
    QPushButton *m_addUserButton;
    QPushButton *m_editUserButton;
    QPushButton *m_deleteUserButton;
    QPushButton *m_deleteCalculationButton;
    QLabel *m_totalUsersLabel;
    QLabel *m_activeUsersLabel;
    QLabel *m_totalCalculationsLabel;
    QLabel *m_lastUpdateLabel;

    // Network
    QNetworkAccessManager *m_networkManager;
};

#endif // ADMINPANEL_H 