#include "adminapi.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

AdminAPI::AdminAPI(QObject *parent)
    : QObject(parent)
    , m_adminController(new AdminController(this))
{
}

void AdminAPI::registerRoutes(QHttpServer &server)
{
    // User management routes
    server.route("/api/admin/users", QHttpServerRequest::Method::Get,
                 [this](QHttpServerResponse &response) {
                     handleGetUsers(response);
                 });

    server.route("/api/admin/users/<arg>", QHttpServerRequest::Method::Get,
                 [this](QHttpServerResponse &response, int userId) {
                     handleGetUser(response, userId);
                 });

    server.route("/api/admin/users", QHttpServerRequest::Method::Post,
                 [this](QHttpServerRequest &request, QHttpServerResponse &response) {
                     handleCreateUser(request, response);
                 });

    server.route("/api/admin/users/<arg>", QHttpServerRequest::Method::Put,
                 [this](QHttpServerRequest &request, QHttpServerResponse &response, int userId) {
                     handleUpdateUser(request, response, userId);
                 });

    server.route("/api/admin/users/<arg>", QHttpServerRequest::Method::Delete,
                 [this](QHttpServerResponse &response, int userId) {
                     handleDeleteUser(response, userId);
                 });

    // Calculation management routes
    server.route("/api/admin/calculations", QHttpServerRequest::Method::Get,
                 [this](QHttpServerResponse &response) {
                     handleGetCalculations(response);
                 });

    server.route("/api/admin/calculations/<arg>", QHttpServerRequest::Method::Get,
                 [this](QHttpServerResponse &response, int calculationId) {
                     handleGetCalculation(response, calculationId);
                 });

    server.route("/api/admin/calculations/<arg>", QHttpServerRequest::Method::Delete,
                 [this](QHttpServerResponse &response, int calculationId) {
                     handleDeleteCalculation(response, calculationId);
                 });

    // Statistics route
    server.route("/api/admin/statistics", QHttpServerRequest::Method::Get,
                 [this](QHttpServerResponse &response) {
                     handleGetStatistics(response);
                 });
}

void AdminAPI::handleGetUsers(QHttpServerResponse &response)
{
    QList<User> users = m_adminController->getAllUsers();
    QJsonArray usersArray;

    for (const auto &user : users) {
        QJsonObject userObj;
        userObj["id"] = user.getId();
        userObj["username"] = user.getUsername();
        userObj["role"] = user.getRole();
        userObj["lastLogin"] = user.getLastLogin().toString();
        userObj["active"] = user.isActive();
        usersArray.append(userObj);
    }

    response.setHeader("Content-Type", "application/json");
    response.write(QJsonDocument(usersArray).toJson());
}

void AdminAPI::handleGetUser(QHttpServerResponse &response, int userId)
{
    User user = m_adminController->getUserById(userId);
    if (user.getId() == 0) {
        response.setStatusCode(QHttpServerResponse::StatusCode::NotFound);
        return;
    }

    QJsonObject userObj;
    userObj["id"] = user.getId();
    userObj["username"] = user.getUsername();
    userObj["role"] = user.getRole();
    userObj["lastLogin"] = user.getLastLogin().toString();
    userObj["active"] = user.isActive();

    response.setHeader("Content-Type", "application/json");
    response.write(QJsonDocument(userObj).toJson());
}

void AdminAPI::handleCreateUser(QHttpServerRequest &request, QHttpServerResponse &response)
{
    QJsonDocument doc = QJsonDocument::fromJson(request.body());
    QJsonObject userObj = doc.object();

    User user;
    user.setUsername(userObj["username"].toString());
    user.setRole(userObj["role"].toString());
    user.setActive(userObj["active"].toBool());

    if (m_adminController->createUser(user)) {
        response.setStatusCode(QHttpServerResponse::StatusCode::Created);
    } else {
        response.setStatusCode(QHttpServerResponse::StatusCode::BadRequest);
    }
}

void AdminAPI::handleUpdateUser(QHttpServerRequest &request, QHttpServerResponse &response, int userId)
{
    QJsonDocument doc = QJsonDocument::fromJson(request.body());
    QJsonObject userObj = doc.object();

    User user = m_adminController->getUserById(userId);
    if (user.getId() == 0) {
        response.setStatusCode(QHttpServerResponse::StatusCode::NotFound);
        return;
    }

    if (userObj.contains("username")) {
        user.setUsername(userObj["username"].toString());
    }
    if (userObj.contains("role")) {
        user.setRole(userObj["role"].toString());
    }
    if (userObj.contains("active")) {
        user.setActive(userObj["active"].toBool());
    }

    if (m_adminController->updateUser(user)) {
        response.setStatusCode(QHttpServerResponse::StatusCode::Ok);
    } else {
        response.setStatusCode(QHttpServerResponse::StatusCode::BadRequest);
    }
}

void AdminAPI::handleDeleteUser(QHttpServerResponse &response, int userId)
{
    if (m_adminController->deleteUser(userId)) {
        response.setStatusCode(QHttpServerResponse::StatusCode::Ok);
    } else {
        response.setStatusCode(QHttpServerResponse::StatusCode::NotFound);
    }
}

void AdminAPI::handleGetCalculations(QHttpServerResponse &response)
{
    QList<Calculation> calculations = m_adminController->getAllCalculations();
    QJsonArray calcArray;

    for (const auto &calc : calculations) {
        QJsonObject calcObj;
        calcObj["id"] = calc.getId();
        calcObj["userId"] = calc.getUserId();
        calcObj["date"] = calc.getDate().toString();
        calcObj["status"] = calc.getStatus();
        calcArray.append(calcObj);
    }

    response.setHeader("Content-Type", "application/json");
    response.write(QJsonDocument(calcArray).toJson());
}

void AdminAPI::handleGetCalculation(QHttpServerResponse &response, int calculationId)
{
    Calculation calc = m_adminController->getCalculationById(calculationId);
    if (calc.getId() == 0) {
        response.setStatusCode(QHttpServerResponse::StatusCode::NotFound);
        return;
    }

    QJsonObject calcObj;
    calcObj["id"] = calc.getId();
    calcObj["userId"] = calc.getUserId();
    calcObj["date"] = calc.getDate().toString();
    calcObj["status"] = calc.getStatus();

    response.setHeader("Content-Type", "application/json");
    response.write(QJsonDocument(calcObj).toJson());
}

void AdminAPI::handleDeleteCalculation(QHttpServerResponse &response, int calculationId)
{
    if (m_adminController->deleteCalculation(calculationId)) {
        response.setStatusCode(QHttpServerResponse::StatusCode::Ok);
    } else {
        response.setStatusCode(QHttpServerResponse::StatusCode::NotFound);
    }
}

void AdminAPI::handleGetStatistics(QHttpServerResponse &response)
{
    QJsonObject stats;
    
    // User statistics
    QMap<QString, int> userStats = m_adminController->getUserStatistics();
    stats["total_users"] = userStats["total_users"];
    stats["active_users"] = userStats["active_users"];

    // Calculation statistics
    QMap<QString, int> calcStats = m_adminController->getCalculationStatistics();
    stats["total_calculations"] = calcStats["total_calculations"];
    stats["total_results"] = calcStats["total_results"];

    // System status
    QMap<QString, QDateTime> systemStatus = m_adminController->getSystemStatus();
    stats["last_update"] = systemStatus["last_update"].toString();

    response.setHeader("Content-Type", "application/json");
    response.write(QJsonDocument(stats).toJson());
} 