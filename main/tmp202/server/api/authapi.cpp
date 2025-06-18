#include "authapi.h"
#include <QJsonDocument>
#include <QJsonObject>

AuthAPI::AuthAPI(QObject *parent)
    : QObject(parent)
    , m_authController(new AuthController(this))
{
}

void AuthAPI::registerRoutes(QHttpServer &server)
{
    server.route("/api/auth/login", QHttpServerRequest::Method::Post,
                 [this](QHttpServerRequest &request, QHttpServerResponse &response) {
                     handleLogin(request, response);
                 });

    server.route("/api/auth/logout", QHttpServerRequest::Method::Post,
                 [this](QHttpServerResponse &response) {
                     handleLogout(response);
                 });

    server.route("/api/auth/check-admin", QHttpServerRequest::Method::Get,
                 [this](QHttpServerResponse &response) {
                     handleCheckAdmin(response);
                 });

    server.route("/api/auth/users/<arg>/role", QHttpServerRequest::Method::Put,
                 [this](QHttpServerRequest &request, QHttpServerResponse &response, int userId) {
                     handleSetUserRole(request, response, userId);
                 });
}

void AuthAPI::handleLogin(QHttpServerRequest &request, QHttpServerResponse &response)
{
    QJsonDocument doc = QJsonDocument::fromJson(request.body());
    QJsonObject loginData = doc.object();

    QString username = loginData["username"].toString();
    QString password = loginData["password"].toString();

    if (m_authController->login(username, password)) {
        QJsonObject responseObj;
        responseObj["success"] = true;
        responseObj["token"] = m_authController->getCurrentToken();
        responseObj["isAdmin"] = m_authController->isCurrentUserAdmin();

        response.setHeader("Content-Type", "application/json");
        response.write(QJsonDocument(responseObj).toJson());
    } else {
        response.setStatusCode(QHttpServerResponse::StatusCode::Unauthorized);
    }
}

void AuthAPI::handleLogout(QHttpServerResponse &response)
{
    m_authController->logout();
    response.setStatusCode(QHttpServerResponse::StatusCode::Ok);
}

void AuthAPI::handleCheckAdmin(QHttpServerResponse &response)
{
    QJsonObject responseObj;
    responseObj["isAdmin"] = m_authController->isCurrentUserAdmin();

    response.setHeader("Content-Type", "application/json");
    response.write(QJsonDocument(responseObj).toJson());
}

void AuthAPI::handleSetUserRole(QHttpServerRequest &request, QHttpServerResponse &response, int userId)
{
    // Проверяем, что текущий пользователь - администратор
    if (!m_authController->isCurrentUserAdmin()) {
        response.setStatusCode(QHttpServerResponse::StatusCode::Forbidden);
        return;
    }

    QJsonDocument doc = QJsonDocument::fromJson(request.body());
    QJsonObject roleData = doc.object();

    QString newRole = roleData["role"].toString();
    if (newRole.isEmpty()) {
        response.setStatusCode(QHttpServerResponse::StatusCode::BadRequest);
        return;
    }

    if (m_authController->setUserRole(userId, newRole)) {
        response.setStatusCode(QHttpServerResponse::StatusCode::Ok);
    } else {
        response.setStatusCode(QHttpServerResponse::StatusCode::BadRequest);
    }
} 