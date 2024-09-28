#ifndef NETWORK_UDP_H
#define NETWORK_UDP_H
#include "mainwindow.h"
#include<QUdpSocket>
#include <QDialog>
#include<QMessageBox>
#include<QFile>


namespace Ui {
class network_udp;
}

class network_udp : public QDialog
{
    Q_OBJECT

public:
    explicit network_udp(QWidget *parent = nullptr);
    ~network_udp();

    void StringToHex(QString str, QByteArray &senddata);

    char ConvertHexChar(char ch);

    void clear_file_data();

    void write_data(QString hexData);   //先将16进制的数据转换成二进制，然后写入到文件中去

    void save_double_datas_to_file(QVector<double> datas);

    void process_data(QString hexData);
    void read_data();
private slots:
    void on_OpenBtn_clicked();

    void readRead_slot();

    void on_SendBtn_clicked();

    void on_ClearBtn_clicked();

    void on_ShowBtn_clicked();

    void on_ExitBtn_clicked();

private:
    Ui::network_udp *ui;
    MainWindow * WaveForm_Chart;
    QUdpSocket  *udpSocket;//
    QString HexData;    //十六位的数据

    QVector<double>  double_datas;//创建一个浮点数向量。
    QFile recvFile;
    QFile resultFile;
    QVector<int> integers; // 创建一个整数向量，从myfile.txt文件里面读出来的整数。

};

#endif // NETWORK_UDP_H
