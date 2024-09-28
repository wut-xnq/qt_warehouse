/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPlainTextEdit *plainTextEdit;
    QGroupBox *Standard_Dialog;
    QPushButton *Open_File;
    QPushButton *Open_Files;
    QPushButton *Select_Colors;
    QPushButton *Select_Font;
    QPushButton *Save_Files;
    QPushButton *Existed_Contents;
    QPushButton *Process_Dialog;
    QGroupBox *Standard_Input_Dialog;
    QPushButton *Input_Int;
    QPushButton *Input_Str;
    QPushButton *Input_Float;
    QPushButton *Setting_Selection_Input;
    QGroupBox *groupBox;
    QPushButton *Critical_Btn;
    QPushButton *AboutQt_Btn;
    QPushButton *About_Btn;
    QPushButton *Question_Btn;
    QPushButton *Information_Btn;
    QPushButton *Warning_Btn;
    QPushButton *Clear_Btn;
    QPushButton *Exit_Btn;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(940, 759);
        QFont font;
        font.setStyleStrategy(QFont::PreferDefault);
        Widget->setFont(font);
        Widget->setAutoFillBackground(false);
        Widget->setStyleSheet(QString::fromUtf8("border-bottom-color: rgb(0, 0, 0);\n"
"border-top-color: rgb(255, 0, 0);"));
        plainTextEdit = new QPlainTextEdit(Widget);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(10, 610, 851, 131));
        QFont font1;
        font1.setBold(false);
        font1.setWeight(50);
        font1.setStyleStrategy(QFont::PreferDefault);
        plainTextEdit->setFont(font1);
        plainTextEdit->setReadOnly(true);
        Standard_Dialog = new QGroupBox(Widget);
        Standard_Dialog->setObjectName(QString::fromUtf8("Standard_Dialog"));
        Standard_Dialog->setGeometry(QRect(10, 10, 441, 351));
        Standard_Dialog->setAutoFillBackground(false);
        Open_File = new QPushButton(Standard_Dialog);
        Open_File->setObjectName(QString::fromUtf8("Open_File"));
        Open_File->setGeometry(QRect(20, 40, 191, 61));
        QFont font2;
        font2.setBold(true);
        font2.setWeight(75);
        font2.setKerning(true);
        font2.setStyleStrategy(QFont::PreferDefault);
        Open_File->setFont(font2);
        Open_File->setAcceptDrops(false);
        Open_Files = new QPushButton(Standard_Dialog);
        Open_Files->setObjectName(QString::fromUtf8("Open_Files"));
        Open_Files->setGeometry(QRect(240, 40, 191, 61));
        QFont font3;
        font3.setBold(true);
        font3.setWeight(75);
        font3.setStyleStrategy(QFont::PreferDefault);
        Open_Files->setFont(font3);
        Select_Colors = new QPushButton(Standard_Dialog);
        Select_Colors->setObjectName(QString::fromUtf8("Select_Colors"));
        Select_Colors->setGeometry(QRect(20, 200, 191, 61));
        Select_Colors->setFont(font3);
        Select_Font = new QPushButton(Standard_Dialog);
        Select_Font->setObjectName(QString::fromUtf8("Select_Font"));
        Select_Font->setGeometry(QRect(240, 200, 191, 61));
        Select_Font->setFont(font3);
        Save_Files = new QPushButton(Standard_Dialog);
        Save_Files->setObjectName(QString::fromUtf8("Save_Files"));
        Save_Files->setGeometry(QRect(240, 120, 191, 61));
        Save_Files->setFont(font3);
        Existed_Contents = new QPushButton(Standard_Dialog);
        Existed_Contents->setObjectName(QString::fromUtf8("Existed_Contents"));
        Existed_Contents->setGeometry(QRect(20, 120, 191, 61));
        Existed_Contents->setFont(font3);
        Process_Dialog = new QPushButton(Standard_Dialog);
        Process_Dialog->setObjectName(QString::fromUtf8("Process_Dialog"));
        Process_Dialog->setGeometry(QRect(20, 280, 191, 61));
        Process_Dialog->setFont(font3);
        Standard_Input_Dialog = new QGroupBox(Widget);
        Standard_Input_Dialog->setObjectName(QString::fromUtf8("Standard_Input_Dialog"));
        Standard_Input_Dialog->setGeometry(QRect(10, 380, 461, 221));
        Standard_Input_Dialog->setAutoFillBackground(true);
        Standard_Input_Dialog->setStyleSheet(QString::fromUtf8("border-left-color: rgb(85, 170, 255);"));
        Standard_Input_Dialog->setFlat(false);
        Input_Int = new QPushButton(Standard_Input_Dialog);
        Input_Int->setObjectName(QString::fromUtf8("Input_Int"));
        Input_Int->setGeometry(QRect(230, 50, 191, 61));
        Input_Int->setFont(font3);
        Input_Int->setAutoFillBackground(false);
        Input_Str = new QPushButton(Standard_Input_Dialog);
        Input_Str->setObjectName(QString::fromUtf8("Input_Str"));
        Input_Str->setGeometry(QRect(10, 50, 191, 61));
        Input_Str->setFont(font3);
        Input_Str->setCursor(QCursor(Qt::ArrowCursor));
        Input_Str->setFocusPolicy(Qt::StrongFocus);
        Input_Str->setLayoutDirection(Qt::LeftToRight);
        Input_Float = new QPushButton(Standard_Input_Dialog);
        Input_Float->setObjectName(QString::fromUtf8("Input_Float"));
        Input_Float->setGeometry(QRect(10, 130, 191, 61));
        Input_Float->setFont(font3);
        Setting_Selection_Input = new QPushButton(Standard_Input_Dialog);
        Setting_Selection_Input->setObjectName(QString::fromUtf8("Setting_Selection_Input"));
        Setting_Selection_Input->setGeometry(QRect(230, 130, 191, 61));
        Setting_Selection_Input->setFont(font3);
        groupBox = new QGroupBox(Widget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(460, 10, 451, 351));
        Critical_Btn = new QPushButton(groupBox);
        Critical_Btn->setObjectName(QString::fromUtf8("Critical_Btn"));
        Critical_Btn->setGeometry(QRect(240, 140, 191, 61));
        Critical_Btn->setFont(font3);
        AboutQt_Btn = new QPushButton(groupBox);
        AboutQt_Btn->setObjectName(QString::fromUtf8("AboutQt_Btn"));
        AboutQt_Btn->setGeometry(QRect(240, 250, 191, 61));
        AboutQt_Btn->setFont(font3);
        About_Btn = new QPushButton(groupBox);
        About_Btn->setObjectName(QString::fromUtf8("About_Btn"));
        About_Btn->setGeometry(QRect(20, 250, 191, 61));
        About_Btn->setFont(font3);
        Question_Btn = new QPushButton(groupBox);
        Question_Btn->setObjectName(QString::fromUtf8("Question_Btn"));
        Question_Btn->setGeometry(QRect(20, 30, 191, 61));
        Question_Btn->setFont(font3);
        Information_Btn = new QPushButton(groupBox);
        Information_Btn->setObjectName(QString::fromUtf8("Information_Btn"));
        Information_Btn->setGeometry(QRect(240, 30, 191, 61));
        Information_Btn->setFont(font3);
        Warning_Btn = new QPushButton(groupBox);
        Warning_Btn->setObjectName(QString::fromUtf8("Warning_Btn"));
        Warning_Btn->setGeometry(QRect(20, 140, 191, 61));
        Warning_Btn->setFont(font3);
        Clear_Btn = new QPushButton(Widget);
        Clear_Btn->setObjectName(QString::fromUtf8("Clear_Btn"));
        Clear_Btn->setGeometry(QRect(500, 470, 191, 71));
        Clear_Btn->setFont(font3);
        QIcon icon;
        icon.addFile(QString::fromUtf8("C:/Users/HP/Desktop/pic/icon/Clear.ico"), QSize(), QIcon::Normal, QIcon::Off);
        Clear_Btn->setIcon(icon);
        Exit_Btn = new QPushButton(Widget);
        Exit_Btn->setObjectName(QString::fromUtf8("Exit_Btn"));
        Exit_Btn->setGeometry(QRect(709, 470, 191, 71));
        Exit_Btn->setFont(font3);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("C:/Users/HP/Desktop/pic/png/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        Exit_Btn->setIcon(icon1);
        Exit_Btn->setAutoDefault(false);
        Exit_Btn->setFlat(false);

        retranslateUi(Widget);

        Input_Str->setDefault(false);
        Exit_Btn->setDefault(false);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        Standard_Dialog->setTitle(QCoreApplication::translate("Widget", "\346\240\207\345\207\206\345\257\271\350\257\235\346\241\206", nullptr));
        Open_File->setText(QCoreApplication::translate("Widget", "\346\211\223\345\274\200\345\215\225\344\270\252\346\226\207\344\273\266", nullptr));
        Open_Files->setText(QCoreApplication::translate("Widget", "\346\211\223\345\274\200\345\244\232\344\270\252\346\226\207\344\273\266", nullptr));
        Select_Colors->setText(QCoreApplication::translate("Widget", "\351\200\211\346\213\251\351\242\234\350\211\262", nullptr));
        Select_Font->setText(QCoreApplication::translate("Widget", "\351\200\211\346\213\251\345\255\227\344\275\223", nullptr));
        Save_Files->setText(QCoreApplication::translate("Widget", "\344\277\235\345\255\230\346\226\207\344\273\266", nullptr));
        Existed_Contents->setText(QCoreApplication::translate("Widget", "\351\200\211\346\213\251\345\267\262\346\234\211\347\233\256\345\275\225", nullptr));
        Process_Dialog->setText(QCoreApplication::translate("Widget", "\350\277\233\345\272\246\345\257\271\350\257\235\346\241\206", nullptr));
        Standard_Input_Dialog->setTitle(QCoreApplication::translate("Widget", "\346\240\207\345\207\206\350\276\223\345\205\245\345\257\271\350\257\235\346\241\206QIputDialog", nullptr));
        Input_Int->setText(QCoreApplication::translate("Widget", "\350\276\223\345\205\245\346\225\264\346\225\260", nullptr));
        Input_Str->setText(QCoreApplication::translate("Widget", "\350\276\223\345\205\245\345\255\227\347\254\246\344\270\262", nullptr));
        Input_Float->setText(QCoreApplication::translate("Widget", "\350\276\223\345\205\245\346\265\256\347\202\271\346\225\260", nullptr));
        Setting_Selection_Input->setText(QCoreApplication::translate("Widget", "\346\235\241\347\233\256\351\200\211\346\213\251\350\276\223\345\205\245", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Widget", "\346\240\207\345\207\206\346\266\210\346\201\257\346\241\206 QMessageBox", nullptr));
        Critical_Btn->setText(QCoreApplication::translate("Widget", "critical", nullptr));
        AboutQt_Btn->setText(QCoreApplication::translate("Widget", "aboutQt", nullptr));
        About_Btn->setText(QCoreApplication::translate("Widget", "about", nullptr));
        Question_Btn->setText(QCoreApplication::translate("Widget", "question", nullptr));
        Information_Btn->setText(QCoreApplication::translate("Widget", "information", nullptr));
        Warning_Btn->setText(QCoreApplication::translate("Widget", "warning", nullptr));
        Clear_Btn->setText(QCoreApplication::translate("Widget", "\346\270\205\351\231\244\346\226\207\346\234\254\346\241\206\345\206\205\345\256\271", nullptr));
        Exit_Btn->setText(QCoreApplication::translate("Widget", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
