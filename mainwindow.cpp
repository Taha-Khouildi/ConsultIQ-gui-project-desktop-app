#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    refreshTable();

    ptrNewClient = new NewClient();

    model = new QSqlQueryModel(this);

    // Configure the table to allow row selection
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete ptrNewClient;
}

void MainWindow::refreshTable()
{
    ui->tableView->setModel(Etmp.afficher()); // Fetch and display the updated data
}

void MainWindow::on_pushButton_clicked()
{
    ptrNewClient->exec();
}

void MainWindow::on_btnDelete_clicked()
{
    // Get the selected row from the table
    QItemSelectionModel *selectionModel = ui->tableView->selectionModel();

    if (!selectionModel->hasSelection())
    {
        QMessageBox::warning(this,
                             tr("No Selection"),
                             tr("Please select a client to delete."),
                             QMessageBox::Ok);
        return;
    }

    // Get the ID from the selected row
    QModelIndex selectedIndex = selectionModel->selectedRows(0).first(); // Assuming the ID is in the first column
    int id = selectedIndex.data().toInt();

    // Call the supprimer() method to delete the client
    bool test = Etmp.supprimer(id);

    if (test)
    {
        QMessageBox::information(this,
                                 tr("Success"),
                                 tr("The client was successfully deleted."),
                                 QMessageBox::Ok);
    }
    else
    {
        QMessageBox::critical(this,
                              tr("Error"),
                              tr("Failed to delete the client. Please try again."),
                              QMessageBox::Ok);
    }

    refreshTable(); // Refresh the table view
}
