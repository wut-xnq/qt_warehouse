#include "network_udp.h"
#include "ui_network_udp.h"

network_udp::network_udp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::network_udp),
    recvFile("D://SoftWares//QT//Code//udpAndChart//udp_chart//recvFile.txt"),
    resultFile("D://SoftWares//QT//Code//udpAndChart//udp_chart//resultFile.txt")
{
    WaveForm_Chart = new MainWindow(this);
    udpSocket = new QUdpSocket(this);
    ui->setupUi(this);
    this->setWindowTitle("UDP通信");
}

network_udp::~network_udp()
{
    delete ui;
}

void network_udp::on_OpenBtn_clicked()
{
    if(    udpSocket->bind(ui->LocalPort->text().toUInt())&&!ui->LocalIP->text().isEmpty())
    {
        connect(udpSocket,SIGNAL(readyRead()),this,SLOT(readRead_slot()));
        QMessageBox::information(this,"tips","Open successfully");
    }
    else
    {
        QMessageBox::information(this,"Tips","Failed to open");
    }

}

void network_udp::readRead_slot()
{
    // 读取收到的数据报
       while (udpSocket->hasPendingDatagrams()) {
           QByteArray datagram;
           datagram.resize(udpSocket->pendingDatagramSize());

           QHostAddress peerAddr;       //获取本地IP
           quint16 peerPort;            //获取本地端口
           udpSocket->readDatagram(datagram.data(), datagram.size(), &peerAddr, &peerPort);

           // 转换数据到十六进制字符串
           for (int i = 0; i < datagram.size(); ++i) {
               HexData += QString::number((datagram.at(i) & 0xF0) >> 4, 16); // 高四位
               HexData += QString::number((datagram.at(i) & 0x0F), 16);       // 低四位
               HexData += ' ';
           }
           // 构建完整的显示字符串
           QString peer = "[From " + peerAddr.toString() + ":" + QString::number(peerPort) + "] ";
           QString completeMessage = peer + HexData;

           // 显示到UI
           ui->RecvtEdit->appendPlainText(completeMessage);
       }

       write_data(HexData);

       read_data();

       process_data(HexData);


       clear_file_data();
}

void network_udp::on_SendBtn_clicked()
{
    QString str = ui->SendEdit->text();     //从sendEdit得到字符串
    int len = str.length();
    if(len%2 == 1)          //如果发送的数据个数为奇数的，则在前面最后落单的字符前添加一个字符0
    {
        str = str.insert(len-1,'0'); //insert(int position, const QString & str)
    }
    QByteArray senddata;

    StringToHex(str,senddata);  //将str字符串转换为16进制的形式

    // 从 AimIP QLineEdit 控件获取IP地址字符串
    QString aimIPText = ui->AimIP->text();
    QHostAddress targetAddr(aimIPText); // 尝试将字符串转换为 QHostAddress 对象

    // 检查IP地址是否有效（非null）
    if(targetAddr.isNull()) {
        // IP地址无效，可以在这里处理错误
        qDebug() << "Invalid IP address.";
    } else {
        // 从 AimPort QLineEdit 控件获取端口字符串
        QString aimPortText = ui->AimPort->text();
        bool ok;
        quint16 targetPort = aimPortText.toUShort(&ok); // 将字符串转换为 quint16

        // 检查端口是否有效
        if(!ok || targetPort == 0) {
            // 端口无效，可以在这里处理错误
            qDebug() << "Invalid port number.";
        } else {
            // 使用获取的地址和端口发送数据报
            udpSocket->writeDatagram(senddata, targetAddr, targetPort);
        }
    }
}

void network_udp::on_ClearBtn_clicked()
{
    ui->RecvtEdit->clear();
}

void network_udp::on_ShowBtn_clicked()
{
    WaveForm_Chart->show();
}

void network_udp::on_ExitBtn_clicked()
{
    // 停止接收数据
    //udpSocket->abort();
    // 关闭套接字
    udpSocket->close();
    QMessageBox::information(this,"tips","Close successfully");

}


//字符串转成十六进制
void network_udp::StringToHex(QString str, QByteArray &senddata)
{
    int hexdata,lowhexdata;
       int hexdatalen = 0;
       int len = str.length();
       senddata.resize(len/2);
       char lstr,hstr;

       for(int i=0; i<len; )
       {
           //char lstr,
           hstr=str[i].toLatin1();
           if(hstr == ' ')
           {
               i++;
               continue;
           }
           i++;
           if(i >= len)
               break;
           lstr = str[i].toLatin1();
           hexdata = ConvertHexChar(hstr);
           lowhexdata = ConvertHexChar(lstr);
           if((hexdata == 16) || (lowhexdata == 16))
               break;
           else
               hexdata = hexdata*16+lowhexdata;
           i++;
           senddata[hexdatalen] = (char)hexdata;
           hexdatalen++;
       }
       senddata.resize(hexdatalen);
}

char network_udp::ConvertHexChar(char ch)
{
    if((ch >= '0') && (ch <= '9'))
        return ch-0x30;
    else if((ch >= 'A') && (ch <= 'F'))
        return ch-'A'+10;
    else if((ch >= 'a') && (ch <= 'f'))
        return ch-'a'+10;
    else return ch-ch;//不在0-f范围内的会发送成0
}

void network_udp::write_data(QString hexData)   //先将16进制的数据转换成二进制，然后写入到文件中去
{
    if(recvFile.open(QFile::WriteOnly | QFile::Append))
    {
        QTextStream out(&recvFile);

        // 假设 hexData 是以十六进制表示的字符串，需要将其转换为字节
        QByteArray bytes = QByteArray::fromHex(hexData.toLatin1());

        // 写入转换后的字节，这里转换为可打印的文本形式
        out << bytes.toHex(' ');  // 以空格分隔十六进制数
        out.flush();  // 确保所有数据都被写入文件
        recvFile.close();  // 关闭文件
    }
    else
    {
        // 输出错误信息
        qDebug() << "Failed to open file for writing:" << recvFile.errorString();
    }
}

void network_udp::save_double_datas_to_file(QVector<double> datas)
{
    if(!resultFile.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "Failed to open file for writing:" << resultFile.errorString();
        return;
    }
     QTextStream out(&resultFile);
     foreach (double double_data, datas) {
         if(double_data > -5.0 ||double_data < 5.0)
         {
          out << double_data << "\n"; // 写入double数据，每个数据后跟一个换行符
         }
         else
         {
             continue;
         }
      }
    resultFile.close(); // 关闭文件
}

void network_udp::clear_file_data()
{
    if (recvFile.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
        // 文件现在为空，因为QIODevice::Truncate会截断文件到0长度
        recvFile.close(); // 关闭文件
    } else {
        // 如果无法打开文件，输出错误信息
        qDebug() << "Failed to open file for clearing:" << recvFile.errorString();
    }
}


void network_udp::process_data(QString hexData)
{
    //使用foreach循环遍历整数向量
   foreach (int value, integers)
   {
       //qDebug()<<"Integer in vector:"<<value;
       if(value>2048)
       {
           qreal a;
           value -= 2048;
           a = 10 * (1.0  * value / 4096) - 5.0;
           if(a<-5.0)
           {
               continue;
           }
           else{
            double_datas.append(a);
           }
       }
       else
       {
           qreal a;
           value += 2048;
           a = 10 * (1.0  * value / 4096) - 5.0;
           if(a>5.0)
           {
               continue;
           }
           else
           {
               double_datas.append(a);
           }
       }
   }
//    foreach(double double_data,double_datas)
//    {
//        qDebug()<<"double_data in double_datas:"<<double_data;
//    }
   save_double_datas_to_file(double_datas);
}

void network_udp::read_data()
{
    if(!recvFile.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        qDebug() << "Failed to open file for reading:" << recvFile.errorString();
        return;
    }

    QTextStream in(&recvFile);

    while(!in.atEnd())
    {
        QString line = in.readLine();
        QStringList hexParts = line.split(" "); // 使用空格作为分隔符

        for (int i = 0; i < hexParts.count(); i += 2) {
            QString hexPart1 = hexParts.at(i);
            QString hexPart2 = hexParts.at(i + 1);

            if (hexPart1.length() == 2 && hexPart2.length() == 2) {
                bool ok;
                int value = hexPart1.toInt(&ok, 16) * 256 + hexPart2.toInt(&ok, 16);
                if (ok) {
                    integers.append(value); // 将转换后的整数添加到向量中
                } else {
                    qDebug() << "Failed to convert hex string to integer.";
                }
            }
        }
    }

    recvFile.close(); // 确保在读取完成后关闭文件

    // 输出数组内容，以便验证
    //qDebug() << "Array contents:" << integers;
}
