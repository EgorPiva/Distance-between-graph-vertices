#ifndef AUTHCONTROLLER_H
#define AUTHCONTROLLER_H

#include <QObject>
#include <QString>
#include <QMap>
#include "../models/user.h"

class AuthController : public QObject
{
    Q_OBJECT

public:
    explicit AuthController(QObject *parent = nullptr);

    // Аутентификация
    bool login(const QString &username, const QString &password);
    void logout();
    bool isLoggedIn() const;
    QString getCurrentToken() const;
    bool isCurrentUserAdmin() const;

    // Управление ролями
    bool setUserRole(int userId, const QString &role);
    bool isUserAdmin(int userId) const;
    QList<User> getAllUsers() const;
    User getCurrentUser() const;

private:
    User m_currentUser;
    QString m_currentToken;
    QMap<int, User> m_users; // Временное хранилище пользователей
};

#endif // AUTHCONTROLLER_H 