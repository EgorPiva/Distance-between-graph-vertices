#ifndef AUTHAPI_H
#define AUTHAPI_H

#include <QObject>
#include <QHttpServer>
#include "../controllers/authcontroller.h"

class AuthAPI : public QObject
{
    Q_OBJECT

public:
    explicit AuthAPI(QObject *parent = nullptr);
    void registerRoutes(QHttpServer &server);

private:
    AuthController *m_authController;

    void handleLogin(QHttpServerRequest &request, QHttpServerResponse &response);
    void handleLogout(QHttpServerResponse &response);
    void handleCheckAdmin(QHttpServerResponse &response);
    void handleSetUserRole(QHttpServerRequest &request, QHttpServerResponse &response, int userId);
};

#endif // AUTHAPI_H 