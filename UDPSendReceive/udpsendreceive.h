#ifndef UDPSENDRECEIVE_H
#define UDPSENDRECEIVE_H

#include <QWidget>
#include <QUdpSocket>
#include <QtNetwork>
QT_BEGIN_NAMESPACE
namespace Ui { class udpsendreceive; }
QT_END_NAMESPACE

class udpsendreceive : public QWidget
{
    Q_OBJECT

public:
    udpsendreceive(QWidget *parent = nullptr);
    ~udpsendreceive();
    void initNetwork(quint16 port);
    void stopnetwork();

private:
    Ui::udpsendreceive *ui;
    QUdpSocket  *udpSocket;//
    QString getLocalIP();//获取本机IP地址
private slots:
    //自定义槽函数
    void onSocketReadyRead();   //  读取socket传入的数据

    void on_pushButton_clicked();
};
#endif // UDPSENDRECEIVE_H
