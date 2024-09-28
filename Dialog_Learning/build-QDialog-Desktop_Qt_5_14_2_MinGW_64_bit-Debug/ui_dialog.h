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
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QPushButton *Open_File;
    QPlainTextEdit *plainTextEdit;
    QPushButton *Open_Files;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(800, 600);
        Open_File = new QPushButton(Dialog);
        Open_File->setObjectName(QString::fromUtf8("Open_File"));
        Open_File->setGeometry(QRect(20, 40, 181, 31));
        plainTextEdit = new QPlainTextEdit(Dialog);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(60, 210, 421, 111));
        Open_Files = new QPushButton(Dialog);
        Open_Files->setObjectName(QString::fromUtf8("Open_Files"));
        Open_Files->setGeometry(QRect(220, 40, 201, 31));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        Open_File->setText(QCoreApplication::translate("Dialog", "\346\211\223\345\274\200\344\270\200\344\270\252\346\226\207\344\273\266", nullptr));
        Open_Files->setText(QCoreApplication::translate("Dialog", "\346\211\223\345\274\200\345\244\232\344\270\252\346\226\207\344\273\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
