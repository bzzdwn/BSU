#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include "PROD.h"
#include "dialog2.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Dialog * dialog = new Dialog;
    int ret = dialog->exec();
    std::ifstream in1("C://Users/User/Documents/Visual Studio/EKR2SEM/EKR2SEM/F1.txt");
    std::ifstream in2("C://Users/User/Documents/Visual Studio/EKR2SEM/EKR2SEM/F2.txt");
    PROD<Prod> M1;
    PROD<Bag> K1;
    M1.ReadData(in1);
    K1.ReadData(in2);
    ui->tableWidget->setRowCount(M1.GetCount());
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    QTableWidgetItem *name = new QTableWidgetItem("Name");
    QTableWidgetItem *price = new QTableWidgetItem("Price");
    ui->tableWidget->setHorizontalHeaderItem(0, name);
    ui->tableWidget->setHorizontalHeaderItem(1, price);
    Prod tmp;
    for (int i = 0; i < M1.GetCount(); ++i) {
        in1.seekg(0);
        in1 >> tmp;
        QTableWidgetItem *itm = new QTableWidgetItem(M1[i].Name.c_str());
        QTableWidgetItem *itm_3 = new QTableWidgetItem(tr("%1").arg(M1[i].Price));
        ui->tableWidget->setItem(i, 0, itm);
        ui->tableWidget->setItem(i, 1, itm_3);

    }
    ui->tableWidget_2->setRowCount(K1.GetCount());
    ui->tableWidget_2->setColumnCount(2);
    ui->tableWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget_2->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    QTableWidgetItem *section = new QTableWidgetItem("Section");
    ui->tableWidget_2->setHorizontalHeaderItem(0, name);
    ui->tableWidget_2->setHorizontalHeaderItem(1, section);
    for (int i = 0; i < K1.GetCount(); ++i) {
        QTableWidgetItem *itm = new QTableWidgetItem(K1[i].Name.c_str());
        QTableWidgetItem *itm_3 = new QTableWidgetItem(K1[i].Section.c_str());
        ui->tableWidget_2->setItem(i, 0, itm);
        ui->tableWidget_2->setItem(i, 1, itm_3);
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_sortup_clicked()
{

}

void MainWindow::on_pushButton_3_clicked()
{
    Dialog2 * dialog_2 = new Dialog2;
    int ret = dialog_2->exec();
}

void MainWindow::on_pushButton_clicked()
{
    ui->tableWidget->sortByColumn(0,Qt::DescendingOrder);
    ui->tableWidget_2->sortByColumn(0,Qt::DescendingOrder);
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->tableWidget->sortByColumn(0,Qt::AscendingOrder);
    ui->tableWidget_2->sortByColumn(1,Qt::DescendingOrder);
    ui->tableWidget_2->sortByColumn(0,Qt::AscendingOrder);
}


