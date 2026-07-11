#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QItemSelectionModel>
#include "newclient.h"
#include "client.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void on_btnDelete_clicked(); // Slot for the delete button

public slots:
    void refreshTable();


private:
    Ui::MainWindow *ui;
    NewClient *ptrNewClient;
    QSqlQueryModel *model; // Model to manage data in the QTableView
    Client Etmp;           // Instance of the Client class
};

#endif // MAINWINDOW_H
