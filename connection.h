#ifndef CONNECTION_H
#define CONNECTION_H

#include <QSqlDatabase>

class Connection {
    QSqlDatabase db;
public:
    Connection();
    bool createConnection();
    bool updateConnection();
    void closeConnection();

};

#endif // CONNECTION_H
