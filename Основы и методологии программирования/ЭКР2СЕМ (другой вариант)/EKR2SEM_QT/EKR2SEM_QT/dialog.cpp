#include "dialog.h"
#include "ui_dialog.h"
#include <fstream>
#include "PROD.h"
#include<sstream>
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_fan_add_clicked()
{
    std::fstream file;
    file.open("C://Users/User/Documents/Visual Studio/EKR2SEM/EKR2SEM/F1.txt", std::ios::app);
    file << "\n" << ui->fa_name_edit->text().toStdString() << "\n";
    file << ui->fan_year_edit->text().toInt();
    file.close();
}

void Dialog::on_arrested_add_clicked()
{
    std::ofstream file;
    file.open("C://Users/User/Documents/Visual Studio/EKR2SEM/EKR2SEM/F2.txt", std::ios::app);
    file << "\n" << ui->arrested_name_edit->text().toStdString() << "\n";
    file << ui->arrested_passport_edit->text().toStdString();
    file.close();
}

void Dialog::on_pushButton_clicked()
{
    accept();
}
