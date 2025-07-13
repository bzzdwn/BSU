/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QHBoxLayout *horizontalLayout;
    QFormLayout *formLayout;
    QWidget *widget;
    QLabel *fan_name;
    QLabel *label;
    QLineEdit *fa_name_edit;
    QLabel *label_4;
    QLineEdit *fan_year_edit;
    QPushButton *fan_add;
    QPushButton *pushButton;
    QFormLayout *formLayout_2;
    QLabel *label_2;
    QLabel *label_7;
    QLineEdit *arrested_name_edit;
    QLabel *label_9;
    QLineEdit *arrested_passport_edit;
    QPushButton *arrested_add;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(678, 169);
        horizontalLayout = new QHBoxLayout(Dialog);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        widget = new QWidget(Dialog);
        widget->setObjectName(QString::fromUtf8("widget"));

        formLayout->setWidget(0, QFormLayout::SpanningRole, widget);

        fan_name = new QLabel(Dialog);
        fan_name->setObjectName(QString::fromUtf8("fan_name"));

        formLayout->setWidget(1, QFormLayout::FieldRole, fan_name);

        label = new QLabel(Dialog);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label);

        fa_name_edit = new QLineEdit(Dialog);
        fa_name_edit->setObjectName(QString::fromUtf8("fa_name_edit"));

        formLayout->setWidget(2, QFormLayout::FieldRole, fa_name_edit);

        label_4 = new QLabel(Dialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        fan_year_edit = new QLineEdit(Dialog);
        fan_year_edit->setObjectName(QString::fromUtf8("fan_year_edit"));

        formLayout->setWidget(3, QFormLayout::FieldRole, fan_year_edit);

        fan_add = new QPushButton(Dialog);
        fan_add->setObjectName(QString::fromUtf8("fan_add"));
        QFont font;
        font.setFamily(QString::fromUtf8("Old English Text MT"));
        font.setPointSize(14);
        fan_add->setFont(font);

        formLayout->setWidget(4, QFormLayout::FieldRole, fan_add);


        horizontalLayout->addLayout(formLayout);

        pushButton = new QPushButton(Dialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Old English Text MT"));
        font1.setPointSize(17);
        pushButton->setFont(font1);

        horizontalLayout->addWidget(pushButton);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, label_2);

        label_7 = new QLabel(Dialog);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_7);

        arrested_name_edit = new QLineEdit(Dialog);
        arrested_name_edit->setObjectName(QString::fromUtf8("arrested_name_edit"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, arrested_name_edit);

        label_9 = new QLabel(Dialog);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_9);

        arrested_passport_edit = new QLineEdit(Dialog);
        arrested_passport_edit->setObjectName(QString::fromUtf8("arrested_passport_edit"));

        formLayout_2->setWidget(2, QFormLayout::FieldRole, arrested_passport_edit);

        arrested_add = new QPushButton(Dialog);
        arrested_add->setObjectName(QString::fromUtf8("arrested_add"));
        arrested_add->setFont(font);

        formLayout_2->setWidget(3, QFormLayout::FieldRole, arrested_add);


        horizontalLayout->addLayout(formLayout_2);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        fan_name->setText(QCoreApplication::translate("Dialog", "<html><head/><body><p align=\"center\"><span style=\" font-size:11pt; font-weight:600;\">Prod</span></p></body></html>", nullptr));
        label->setText(QCoreApplication::translate("Dialog", "<html><head/><body><p align=\"center\"><span style=\" font-size:9pt; font-weight:600; text-decoration: underline;\">Name:</span></p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("Dialog", "<html><head/><body><p align=\"center\"><span style=\" font-size:9pt; font-weight:600; text-decoration: underline;\">Price:</span></p></body></html>", nullptr));
        fan_add->setText(QCoreApplication::translate("Dialog", "Add Button", nullptr));
        pushButton->setText(QCoreApplication::translate("Dialog", "OK", nullptr));
        label_2->setText(QCoreApplication::translate("Dialog", "<html><head/><body><p align=\"center\"><span style=\" font-size:11pt; font-weight:600;\">Bag</span></p></body></html>", nullptr));
        label_7->setText(QCoreApplication::translate("Dialog", "<html><head/><body><p align=\"center\"><span style=\" font-size:9pt; font-weight:600; text-decoration: underline;\">Name:</span></p></body></html>", nullptr));
        label_9->setText(QCoreApplication::translate("Dialog", "<html><head/><body><p align=\"center\"><span style=\" font-size:9pt; font-weight:600; text-decoration: underline;\">Section:</span></p></body></html>", nullptr));
        arrested_add->setText(QCoreApplication::translate("Dialog", "Add Button", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
