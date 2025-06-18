#include "user.h"
#include <QCryptographicHash>
#include <QRegularExpression>

User::User() : m_role(Role::Regular), m_isActive(true) {
}

User::User(const QString &username, const QString &password, Role role)
    : m_username(username)
    , m_password(hashPassword(password))
    , m_role(role)
    , m_isActive(true)
{
}

QString User::getUsername() const {
    return m_username;
}

QString User::getPassword() const {
    return m_password;
}

User::Role User::getRole() const {
    return m_role;
}

QDateTime User::getLastLogin() const {
    return m_lastLogin;
}

bool User::isActive() const {
    return m_isActive;
}

void User::setUsername(const QString &username) {
    m_username = username;
}

void User::setPassword(const QString &password) {
    m_password = hashPassword(password);
}

void User::setRole(Role role) {
    m_role = role;
}

void User::setLastLogin(const QDateTime &time) {
    m_lastLogin = time;
}

void User::setActive(bool active) {
    m_isActive = active;
}

bool User::validatePassword(const QString &password) {
    // Минимум 8 символов, хотя бы одна буква и одна цифра
    QRegularExpression regex("^(?=.*[A-Za-z])(?=.*\\d)[A-Za-z\\d]{8,}$");
    return regex.match(password).hasMatch();
}

QString User::hashPassword(const QString &password) {
    QByteArray data = password.toUtf8();
    QByteArray hash = QCryptographicHash::hash(data, QCryptographicHash::Sha256);
    return hash.toHex();
}

bool User::verifyPassword(const QString &password, const QString &hash) {
    return hashPassword(password) == hash;
} 