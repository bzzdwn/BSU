#include "dialog.h"
#include "ui_dialog.h"
#include "MED.h"
#include <fstream>
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

void Dialog::on_add_items_clicked()
{
    std::ofstream file;
    file.open("C://Users/User/Documents/EKR2sem/F1.bin", std::ios::binary);
    Items item;
    strcpy(item.Name, ui->line_name_items->text().toStdString().c_str());
    int i = 0;
    while(i < sizeof(item.Name)){
    file.write((char*)item.Name[i], sizeof(item.Name));
    }
    strcpy(item.myDate, ui->line_date_items->text().toStdString().c_str());
    file.write((char*)item.myDate, sizeof(item.myDate));
    strcpy(item.Section, ui->line_section_items->text().toStdString().c_str());
    file.write((char*)item.Section, sizeof(item.Section));
    item.Count = ui->line_count_items->text().toInt();
    file.write((char*)item.Count, sizeof(item.Count)/sizeof(int));
    file.close();
}

void Dialog::on_add_price_clicked()
{
    std::ofstream file;
    file.open("C://Users/User/Documents/EKR2sem/F2.bin", std::ios::binary);
    Price item;
    strcpy(item.Name, ui->line_name_price->text().toStdString().c_str());
    file.write((char*)item.Name, sizeof(item.Name));
    strcpy(item.myDate, ui->line_date_price->text().toStdString().c_str());
    file.write((char*)item.myDate, sizeof(item.myDate));
    item.pr = ui->line_price_price->text().toDouble();
    char* buff = new char[10];
    sprintf (buff, "%f", item.pr);
    file.write(buff, 10);
    file.close();
}

void Dialog::on_pushButton_clicked()
{
    accept();
}
