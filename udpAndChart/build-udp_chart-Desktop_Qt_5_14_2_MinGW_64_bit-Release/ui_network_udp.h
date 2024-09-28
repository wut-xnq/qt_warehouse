/********************************************************************************
** Form generated from reading UI file 'network_udp.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NETWORK_UDP_H
#define UI_NETWORK_UDP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_network_udp
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QPlainTextEdit *RecvtEdit;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *OpenBtn;
    QSpacerItem *horizontalSpacer;
    QPushButton *ClearBtn;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *ShowBtn;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *ExitBtn;
    QHBoxLayout *horizontalLayout_3;
    QLabel *local;
    QLineEdit *LocalIP;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_3;
    QLineEdit *LocalPort;
    QHBoxLayout *horizontalLayout_2;
    QLabel *Aim;
    QLineEdit *AimIP;
    QSpacerItem *horizontalSpacer_5;
    QLabel *Aim_2;
    QLineEdit *AimPort;
    QHBoxLayout *horizontalLayout;
    QPushButton *SendBtn;
    QLineEdit *SendEdit;

    void setupUi(QDialog *network_udp)
    {
        if (network_udp->objectName().isEmpty())
            network_udp->setObjectName(QString::fromUtf8("network_udp"));
        network_udp->resize(732, 534);
        gridLayout_2 = new QGridLayout(network_udp);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        RecvtEdit = new QPlainTextEdit(network_udp);
        RecvtEdit->setObjectName(QString::fromUtf8("RecvtEdit"));

        gridLayout->addWidget(RecvtEdit, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        OpenBtn = new QPushButton(network_udp);
        OpenBtn->setObjectName(QString::fromUtf8("OpenBtn"));

        horizontalLayout_4->addWidget(OpenBtn);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        ClearBtn = new QPushButton(network_udp);
        ClearBtn->setObjectName(QString::fromUtf8("ClearBtn"));

        horizontalLayout_4->addWidget(ClearBtn);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        ShowBtn = new QPushButton(network_udp);
        ShowBtn->setObjectName(QString::fromUtf8("ShowBtn"));

        horizontalLayout_4->addWidget(ShowBtn);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        ExitBtn = new QPushButton(network_udp);
        ExitBtn->setObjectName(QString::fromUtf8("ExitBtn"));

        horizontalLayout_4->addWidget(ExitBtn);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        local = new QLabel(network_udp);
        local->setObjectName(QString::fromUtf8("local"));

        horizontalLayout_3->addWidget(local);

        LocalIP = new QLineEdit(network_udp);
        LocalIP->setObjectName(QString::fromUtf8("LocalIP"));

        horizontalLayout_3->addWidget(LocalIP);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        label_3 = new QLabel(network_udp);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        LocalPort = new QLineEdit(network_udp);
        LocalPort->setObjectName(QString::fromUtf8("LocalPort"));

        horizontalLayout_3->addWidget(LocalPort);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        Aim = new QLabel(network_udp);
        Aim->setObjectName(QString::fromUtf8("Aim"));

        horizontalLayout_2->addWidget(Aim);

        AimIP = new QLineEdit(network_udp);
        AimIP->setObjectName(QString::fromUtf8("AimIP"));

        horizontalLayout_2->addWidget(AimIP);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        Aim_2 = new QLabel(network_udp);
        Aim_2->setObjectName(QString::fromUtf8("Aim_2"));

        horizontalLayout_2->addWidget(Aim_2);

        AimPort = new QLineEdit(network_udp);
        AimPort->setObjectName(QString::fromUtf8("AimPort"));

        horizontalLayout_2->addWidget(AimPort);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        SendBtn = new QPushButton(network_udp);
        SendBtn->setObjectName(QString::fromUtf8("SendBtn"));

        horizontalLayout->addWidget(SendBtn);

        SendEdit = new QLineEdit(network_udp);
        SendEdit->setObjectName(QString::fromUtf8("SendEdit"));

        horizontalLayout->addWidget(SendEdit);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout, 1, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(network_udp);

        QMetaObject::connectSlotsByName(network_udp);
    } // setupUi

    void retranslateUi(QDialog *network_udp)
    {
        network_udp->setWindowTitle(QCoreApplication::translate("network_udp", "Dialog", nullptr));
        OpenBtn->setText(QCoreApplication::translate("network_udp", "\346\211\223\345\274\200", nullptr));
        ClearBtn->setText(QCoreApplication::translate("network_udp", "\346\270\205\345\261\217", nullptr));
        ShowBtn->setText(QCoreApplication::translate("network_udp", "\346\230\276\347\244\272", nullptr));
        ExitBtn->setText(QCoreApplication::translate("network_udp", "\345\205\263\351\227\255", nullptr));
        local->setText(QCoreApplication::translate("network_udp", "\346\234\254\345\234\260IP", nullptr));
        label_3->setText(QCoreApplication::translate("network_udp", "\346\234\254\345\234\260\347\253\257\345\217\243", nullptr));
        Aim->setText(QCoreApplication::translate("network_udp", "\347\233\256\346\240\207IP", nullptr));
        Aim_2->setText(QCoreApplication::translate("network_udp", "\347\233\256\346\240\207\347\253\257\345\217\243", nullptr));
        SendBtn->setText(QCoreApplication::translate("network_udp", "\345\217\221\351\200\201\346\266\210\346\201\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class network_udp: public Ui_network_udp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NETWORK_UDP_H
