#include "connection.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>
#include <QMessageBox> // Keep this if you want popups from here (though usually better in UI code)
// #include <QSqlQuery> // Not needed in this specific file

Connection::Connection() {}

bool Connection::createConnection()
{
    // Use a connection name to avoid conflicts if you ever need multiple connections
    // If you only have one, the default name is usually fine.
    db = QSqlDatabase::addDatabase("QODBC");// Add connection to Qt's list
    qDebug() << "Attempting to connect via ODBC Source:" << "Source_Projet2A";
    db.setDatabaseName("Source_Projet2A"); // ODBC Data Source Name (DSN)
    db.setUserName("consultiq");
    db.setPassword(""); // TODO: set your DB password here — do not commit real credentials


    db.setConnectOptions("SQL_ATTR_NOSCAN=1");
    qDebug() << "Set DB Connect Options:" << db.connectOptions();
    if (db.open()) {
        qDebug() << "Connection SUCCESSFUL using" << db.driverName() << "to" << db.databaseName();
        return true;
    } else {
        // Provide more context in the error message
        qDebug() << "Database Error: Failed to open database connection.";
        qDebug() << "Driver:" << db.driverName();
        qDebug() << "Database Name (DSN):" << db.databaseName();
        qDebug() << "Username:" << db.userName();
        qDebug() << "Error:" << db.lastError().text();

        // You might show a message box here, but it's generally better to
        // return false and let the calling code (like main.cpp) handle the UI alert.
        // QMessageBox::critical(nullptr, "Database Error", "Connection failed: " + db.lastError().text());

        return false;
    }
}

// updateConnection might not be necessary if you establish connection once in main.
// If you need it, it's okay.
bool Connection::updateConnection()
{
    if (!db.isOpen()) {
        qDebug() << "Database connection was closed. Attempting to reopen...";
        return createConnection(); // Try to reopen
    }
    return true; // Already open
}

void Connection::closeConnection() {
    // Important: Use the connection name if you specified one in addDatabase
    QString connectionName = db.connectionName();
    db.close(); // Close the connection associated with this instance
    qDebug() << "Closed database connection:" << connectionName;
    QSqlDatabase::removeDatabase(connectionName); // Remove it from Qt's list
    qDebug() << "Removed database connection:" << connectionName;
}
