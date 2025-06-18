#include "authcontroller.h"
#include <QCryptographicHash>
#include <QDateTime>

AuthController::AuthController(QObject *parent)
    : QObject(parent)
{
    // Создаем тестового администратора
    User admin;
    admin.setId(1);
    admin.setUsername("admin");
    admin.setPassword("admin123"); // В реальном приложении должен быть хэш
    admin.setRole("admin");
    admin.setActive(true);
    m_users[1] = admin;
}

bool AuthController::login(const QString &username, const QString &password)
{
    // В реальном приложении здесь должна быть проверка в базе данных
    for (const auto &user : m_users) {
        if (user.getUsername() == username && user.getPassword() == password) {
            m_currentUser = user;
            m_currentToken = QString::number(QDateTime::currentMSecsSinceEpoch());
            return true;
        }
    }
    return false;
}

void AuthController::logout()
{
    m_currentUser = User();
    m_currentToken.clear();
}

bool AuthController::isLoggedIn() const
{
    return !m_currentToken.isEmpty();
}

QString AuthController::getCurrentToken() const
{
    return m_currentToken;
}

bool AuthController::isCurrentUserAdmin() const
{
    return m_currentUser.getRole() == "admin";
}

bool AuthController::setUserRole(int userId, const QString &role)
{
    // Проверяем, что текущий пользователь - администратор
    if (!isCurrentUserAdmin()) {
        return false;
    }

    // Проверяем, что роль валидна
    if (role != "admin" && role != "user") {
        return false;
    }

    // Находим пользователя
    if (!m_users.contains(userId)) {
        return false;
    }

    // Обновляем роль
    User user = m_users[userId];
    user.setRole(role);
    m_users[userId] = user;

    return true;
}

bool AuthController::isUserAdmin(int userId) const
{
    if (!m_users.contains(userId)) {
        return false;
    }
    return m_users[userId].getRole() == "admin";
}

QList<User> AuthController::getAllUsers() const
{
    return m_users.values();
}

User AuthController::getCurrentUser() const
{
    return m_currentUser;
} 