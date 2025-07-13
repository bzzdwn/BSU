#include "dialog2.h"
#include "ui_dialog2.h"
#include "PROD.h"
Dialog2::Dialog2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog2)
{
    ui->setupUi(this);
    std::ifstream in1("C://Users/User/Documents/Visual Studio/EKR2SEM/EKR2SEM/F1.txt");
    std::ifstream in2("C://Users/User/Documents/Visual Studio/EKR2SEM/EKR2SEM/F2.txt");
    PROD<Prod> M1;
    PROD<Bag> K1;
    M1.ReadData(in1);
    K1.ReadData(in2);
    PROD <Market> R(M1.GetCount());
    R.function(M1, K1);
    ui->tableWidget->setRowCount(R.GetCount());
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    QTableWidgetItem *name = new QTableWidgetItem("Name");
    QTableWidgetItem *price = new QTableWidgetItem("Price");
    QTableWidgetItem *sect = new QTableWidgetItem("Section");
    ui->tableWidget->setHorizontalHeaderItem(0, name);
    ui->tableWidget->setHorizontalHeaderItem(1, price);
    ui->tableWidget->setHorizontalHeaderItem(2, sect);
    for (int i = 0; i < R.GetCount(); ++i) {
        QTableWidgetItem *itm = new QTableWidgetItem(R[i].Name.c_str());
         QTableWidgetItem *itm_2 = new QTableWidgetItem(R[i].Section.c_str());
        QTableWidgetItem *itm_3 = new QTableWidgetItem(tr("%1").arg(R[i].Price));
        ui->tableWidget->setItem(i, 0, itm);
        ui->tableWidget->setItem(i, 1, itm_2);
        ui->tableWidget->setItem(i, 2, itm_3);

    }
}

Dialog2::~Dialog2()
{
    delete ui;
}
