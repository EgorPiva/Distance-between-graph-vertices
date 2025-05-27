#include <QCoreApplication>
#include "DBServer.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    DBServer& server = DBServer::instance(12345);
    if (!server.startServer()) {
        return 1;
    }

    return a.exec();
}
