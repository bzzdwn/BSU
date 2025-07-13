#include "dialog.h"
#include "ui_dialog.h"
#include <fstream>
#include "abs_fanat.h"
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
    Fanat1 fan;
    std::ofstream file;
    file.open("C://Users/User/Documents/Visual Studio/EKR8GR2SEM/EKR8GR2SEM_QT/output_1.txt", ios::app);
    file << ui->fa_name_edit->text().toStdString() << "\n";
    file << ui->fan_nat_edit->text().toStdString() << "\n";
    file << ui->fan_year_edit->text().toInt() << "\n";
    file << ui->fan_arrests_edit->text().toInt() << "\n";
    file.close();
}

void Dialog::on_arrested_add_clicked()
{
    Fanat2 fan;
    std::ofstream file;
    file.open("C://Users/User/Documents/Visual Studio/EKR8GR2SEM/EKR8GR2SEM_QT/output_2.txt", ios::app);
    file << ui->arrested_name_edit->text().toStdString() << "\n";
    file << ui->arrested_passport_edit->text().toInt() << "\n";
    file << ui->arrested_arrests_edit->text().toInt() << "\n";
    file.close();
}

void Dialog::on_pushButton_clicked()
{
    accept();
}
