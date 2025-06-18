#include "admincontroller.h"
#include <QDebug>

AdminController::AdminController(QObject *parent)
    : QObject(parent)
{
}

QList<User> AdminController::getAllUsers() const
{
    return m_users;
}

User AdminController::getUserById(int userId) const
{
    for (const auto &user : m_users) {
        if (user.getId() == userId) {
            return user;
        }
    }
    return User();
}

bool AdminController::updateUser(const User &user)
{
    for (int i = 0; i < m_users.size(); ++i) {
        if (m_users[i].getId() == user.getId()) {
            m_users[i] = user;
            return true;
        }
    }
    return false;
}

bool AdminController::deleteUser(int userId)
{
    for (int i = 0; i < m_users.size(); ++i) {
        if (m_users[i].getId() == userId) {
            m_users.removeAt(i);
            return true;
        }
    }
    return false;
}

bool AdminController::createUser(const User &user)
{
    // Check if user with same username already exists
    for (const auto &existingUser : m_users) {
        if (existingUser.getUsername() == user.getUsername()) {
            return false;
        }
    }
    m_users.append(user);
    return true;
}

QList<Calculation> AdminController::getAllCalculations() const
{
    return m_calculations;
}

Calculation AdminController::getCalculationById(int calculationId) const
{
    for (const auto &calc : m_calculations) {
        if (calc.getId() == calculationId) {
            return calc;
        }
    }
    return Calculation();
}

bool AdminController::deleteCalculation(int calculationId)
{
    for (int i = 0; i < m_calculations.size(); ++i) {
        if (m_calculations[i].getId() == calculationId) {
            m_calculations.removeAt(i);
            return true;
        }
    }
    return false;
}

QList<CalculationResult> AdminController::getCalculationResults(int calculationId) const
{
    QList<CalculationResult> results;
    for (const auto &result : m_results) {
        if (result.getCalculationId() == calculationId) {
            results.append(result);
        }
    }
    return results;
}

QMap<QString, int> AdminController::getUserStatistics() const
{
    QMap<QString, int> stats;
    stats["total_users"] = m_users.size();
    
    int activeUsers = 0;
    for (const auto &user : m_users) {
        if (user.isActive()) {
            activeUsers++;
        }
    }
    stats["active_users"] = activeUsers;
    
    return stats;
}

QMap<QString, int> AdminController::getCalculationStatistics() const
{
    QMap<QString, int> stats;
    stats["total_calculations"] = m_calculations.size();
    stats["total_results"] = m_results.size();
    return stats;
}

QMap<QString, QDateTime> AdminController::getSystemStatus() const
{
    QMap<QString, QDateTime> status;
    status["last_update"] = QDateTime::currentDateTime();
    return status;
} 