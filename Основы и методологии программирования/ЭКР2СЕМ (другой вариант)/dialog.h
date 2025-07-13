#ifndef DIALOG_H
#define DIALOG_H
#include "MED.h"
#include <QDialog>
struct Items {
    char Name[35];
    char myDate[8];
    char Section[10];
    int Count;
    bool operator==(const Items& i) {
        return (Name == i.Name);
    }
};
struct Price {
    char  Name[35];
    char  myDate[8];
    double pr;
    bool operator==(const Price& i) {
        return (Name == i.Name);
    }
};
struct Med {
    char Name[35];
    char myDate[8];
    char Section[10];
    double pr;
    int Count;
    Med& operator=(const Items& a) {
        for (size_t i = 0; i < 35; i++)
        {
            Name[i] = a.Name[i];
        }
        for (size_t i = 0; i < 8; i++)
        {
            myDate[i] = a.myDate[i];
        }
        for (size_t i = 0; i < 10; i++)
        {
            Section[i] = a.Section[i];
        }
        Count = a.Count;
        pr = 0;
        return *this;

    }
    Med& operator=(const Price& a) {
        for (size_t i = 0; i < 35; i++)
        {
            Name[i] = a.Name[i];
        }
        for (size_t i = 0; i < 8; i++)
        {
            myDate[i] = a.myDate[i];
        }
        Section['U', 'n', 'k', 'n', 'o', 'w', 'n'];
        Count = 0;
        pr = a.pr;
        return *this;

    }
    bool operator==(const Med& i) {
        return (Name == i.Name);
    }
};
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_add_items_clicked();

    void on_add_price_clicked();

    void on_pushButton_clicked();

private:
    Ui::Dialog *ui;

};

#endif // DIALOG_H
