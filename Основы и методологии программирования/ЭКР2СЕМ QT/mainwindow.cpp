#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include "abs_fanat.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    Dialog * dialog = new Dialog;
    int ret = dialog->exec();
    ABS_Fanat* A1, * A2, * A3;
    ifstream in1("C://Users/User/Documents/Visual Studio/EKR8GR2SEM/EKR8GR2SEM_QT/output_1.txt");
    ifstream in2("C://Users/User/Documents/Visual Studio/EKR8GR2SEM/EKR8GR2SEM_QT/output_2.txt");
    BF M1;
    BADBOY K1;
    F18 R1;
    A1 = &M1;
    A2 = &K1;
    A1->GetFanats(in1);
    ui->fan_table->setRowCount(M1.GetCount());
    ui->fan_table->setColumnCount(3);
    QTableWidgetItem *name = new QTableWidgetItem("Name");
    QTableWidgetItem *nationality = new QTableWidgetItem("Nationality");
    QTableWidgetItem *year = new QTableWidgetItem("Year");
    QTableWidgetItem *n = new QTableWidgetItem("Arrests");
    ui->fan_table->setHorizontalHeaderItem(0, name);
    ui->fan_table->setHorizontalHeaderItem(1, nationality);
    ui->fan_table->setHorizontalHeaderItem(2, year);
    ui->fan_table->setHorizontalHeaderItem(3, n);
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

