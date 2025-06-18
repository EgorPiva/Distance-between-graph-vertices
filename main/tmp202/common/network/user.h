#ifndef USER_H
#define USER_H

#include <QString>
#include <QDateTime>

class User {
public:
    enum class Role {
        Regular,
        Admin
    };

    User();
    User(const QString &username, const QString &password, Role role = Role::Regular);

    QString getUsername() const;
    QString getPassword() const;
    Role getRole() const;
    QDateTime getLastLogin() const;
    bool isActive() const;

    void setUsername(const QString &username);
    void setPassword(const QString &password);
    void setRole(Role role);
    void setLastLogin(const QDateTime &time);
    void setActive(bool active);

    // Статические методы для работы с пользователями
    static bool validatePassword(const QString &password);
    static QString hashPassword(const QString &password);
    static bool verifyPassword(const QString &password, const QString &hash);

private:
    QString m_username;
    QString m_password; // Хранится в хэшированном виде
    Role m_role;
    QDateTime m_lastLogin;
    bool m_isActive;
};

#endif // USER_H 