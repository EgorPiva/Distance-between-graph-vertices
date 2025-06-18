#ifndef ADMINAPI_H
#define ADMINAPI_H

#include <QObject>
#include <QHttpServer>
#include "../controllers/admincontroller.h"

class AdminAPI : public QObject
{
    Q_OBJECT

public:
    explicit AdminAPI(QObject *parent = nullptr);
    void registerRoutes(QHttpServer &server);

private:
    AdminController *m_adminController;

    // User management endpoints
    void handleGetUsers(QHttpServerResponse &response);
    void handleGetUser(QHttpServerResponse &response, int userId);
    void handleCreateUser(QHttpServerRequest &request, QHttpServerResponse &response);
    void handleUpdateUser(QHttpServerRequest &request, QHttpServerResponse &response, int userId);
    void handleDeleteUser(QHttpServerResponse &response, int userId);

    // Calculation management endpoints
    void handleGetCalculations(QHttpServerResponse &response);
    void handleGetCalculation(QHttpServerResponse &response, int calculationId);
    void handleDeleteCalculation(QHttpServerResponse &response, int calculationId);

    // Statistics endpoints
    void handleGetStatistics(QHttpServerResponse &response);
};

#endif // ADMINAPI_H 