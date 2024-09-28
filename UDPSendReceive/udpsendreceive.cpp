#include "udpsendreceive.h"
#include "ui_udpsendreceive.h"

udpsendreceive::udpsendreceive(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::udpsendreceive)
{
    ui->setupUi(this);
    initNetwork(5555);
    this->setWindowTitle("UdpSendReveive");
}


void udpsendreceive::initNetwork(quint16 port)
{
    udpSocket=new QUdpSocket(this);//用于与连接的客户端通讯的QTcpSocket
    connect(udpSocket,SIGNAL(readyRead()),this,SLOT(onSocketReadyRead()));
    if (udpSocket->bind(port))//绑定监听端口成功
          ui->plainTextEdit->appendPlainText("***已成功绑定端口："+QString::number(udpSocket->localPort()));
      else
          ui->plainTextEdit->appendPlainText("***绑定失败***");
}

udpsendreceive::~udpsendreceive()
{
    delete ui;
}

void udpsendreceive::onSocketReadyRead()
{
    //读取收到的数据报
        while(udpSocket->hasPendingDatagrams())
        {
            QByteArray   datagram;
            datagram.resize(udpSocket->pendingDatagramSize());

            QHostAddress peerAddr;
            quint16 peerPort;
            udpSocket->readDatagram(datagram.data(),datagram.size(),&peerAddr,&peerPort);
            QString str=datagram.data();
            QString peer="[From "+peerAddr.toString()+":"+QString::number(peerPort)+"] ";

            ui->plainTextEdit->appendPlainText(peer+str);
        }
}

void udpsendreceive::stopnetwork()
{
    udpSocket->abort(); //不能解除绑定
    ui->plainTextEdit->appendPlainText("***已解除绑定***");
    delete udpSocket;
}

QString udpsendreceive::getLocalIP()
{
    QString ipString = Q_NULLPTR;
    QHostInfo hostInfo = QHostInfo::fromName(QHostInfo::localHostName());   //从本地主机名称获取主机信息
    QList<QHostAddress> listAddr = hostInfo.addresses();    //本地主机ip地址列表(IPV4/IPV6)
    foreach (auto addr, listAddr)
    {
        if((addr.isNull() == false) && (addr.protocol() == QAbstractSocket::IPv4Protocol)
                && (addr != QHostAddress::LocalHost))
        {
            ipString = addr.toString();   //根据条件筛选出本地IPV4地址
        }
    }
    return ipString;
}

void udpsendreceive::on_pushButton_clicked()
{
    QString  msg=ui->lineEdit->text();//发送的消息内容
    QByteArray  str=msg.toUtf8();

    QString     targetIP="192.168.0.3"; //目标IP!!!!
    QHostAddress    targetAddr(targetIP);

    quint16     targetPort=5555;//目标port（同一计算机上运行需要绑定不同的端口，确保ip+port唯一）


    udpSocket->writeDatagram(str,targetAddr,targetPort); //发出数据报

    ui->lineEdit->setFocus();
    if(ui->lineEdit->text().isEmpty())return;
    ui->lineEdit->clear();

    ui->plainTextEdit->appendPlainText("[发送] "+msg);

}
