#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDialog>
#include "dialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Dialog * dialog = new Dialog;
    int ret = dialog->exec();
    if(ret == QDialog::Accepted){
        MED <Items> items;
        MED <Price> price;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

