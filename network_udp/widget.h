#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QUdpSocket>
#include<QString>
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    QUdpSocket  *UdpSocket;
private slots:
    void on_OpenBt_clicked();
    void readyRead_Slot();
    void on_SendBt_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
