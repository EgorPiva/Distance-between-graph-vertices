#ifndef ADMINCONTROLLER_H
#define ADMINCONTROLLER_H

#include <QObject>
#include <QMap>
#include <QDateTime>
#include "../models/user.h"
#include "../models/calculation.h"
#include "../models/calculationresult.h"

class AdminController : public QObject
{
    Q_OBJECT

public:
    explicit AdminController(QObject *parent = nullptr);

    // User management
    QList<User> getAllUsers() const;
    User getUserById(int userId) const;
    bool updateUser(const User &user);
    bool deleteUser(int userId);
    bool createUser(const User &user);

    // Calculation management
    QList<Calculation> getAllCalculations() const;
    Calculation getCalculationById(int calculationId) const;
    bool deleteCalculation(int calculationId);
    QList<CalculationResult> getCalculationResults(int calculationId) const;

    // Statistics
    QMap<QString, int> getUserStatistics() const;
    QMap<QString, int> getCalculationStatistics() const;
    QMap<QString, QDateTime> getSystemStatus() const;

private:
    QList<User> m_users;
    QList<Calculation> m_calculations;
    QList<CalculationResult> m_results;
};

#endif // ADMINCONTROLLER_H 