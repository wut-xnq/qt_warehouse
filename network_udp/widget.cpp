#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    UdpSocket = new QUdpSocket(this);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::readyRead_Slot()
{
    while(UdpSocket->hasPendingDatagrams())
    {
        QByteArray  array;
        array.resize(UdpSocket->pendingDatagramSize()) ; //调整大小
        UdpSocket->readDatagram(array.data(),array.size());

        QString buf;

        ui->RecvEdit->appendPlainText(buf);

    }
}

void Widget::on_OpenBt_clicked()
{
   if( UdpSocket->bind(ui->LocalPort->text().toInt())==true)
   {
        QMessageBox::information(this,"提示","成功");
   }
   else
   {
        QMessageBox::information(this,"提示","失败");
   }
   connect(UdpSocket, &QUdpSocket::readyRead,
               this, &Widget::readyRead_Slot);
}


void Widget::on_SendBt_clicked()
{
    quint16 port;
    QString sendbuff;
    QHostAddress address;

    address.setAddress(ui->AipIp->text());
}
