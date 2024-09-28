#include "widget.h"
#include "ui_widget.h"
#include <QPaintEvent>
#include <QDebug>
#include<QPainter>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setPalette(QPalette(Qt::white));        //设置窗口为白色背景
    setAutoFillBackground(true);
    this->resize(400,300);
}

Widget::~Widget()
{
    delete ui;
}

/*void Widget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
//    painter.setPen(Qt::red);//设置画笔颜色
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setRenderHint(QPainter::TextAntialiasing);
    //自适应获取窗口的宽度和高度
    int W = this->width();  //绘图区宽度
    int H = this->height();//绘图区高度
    QRect rect(W/4,H/2,W/2,H/2);//中间区域矩形

    //设置 画笔
//    QPen pen;
//    pen.setWidth(3);            //线宽
//    pen.setColor(Qt::red);      //线条颜色
//    pen.setStyle(Qt::SolidLine);    //线条样式
//    pen.setCapStyle(Qt::FlatCap);   //线条端点样式
//    pen.setJoinStyle(Qt::BevelJoin);        //线条的连接样式
//    painter.setPen(pen);
    painter.setPen(QPen(Qt::NoPen));


    //设置画刷
//    QPixmap texturePixmap("C:/Users/HP/Desktop/pic/jpg/color_black.jpg");
//    QBrush brush;
//    brush.setColor(Qt::yellow);     //画刷颜色
//    brush.setStyle(Qt::SolidPattern);   //画刷填充样式
//    brush.setStyle(Qt::TexturePattern);
//    brush.setTexture(texturePixmap);

//    painter.setBrush(brush);
    //线性渐变 从左到右
    QLinearGradient linearGrad(rect.left(),rect.top(),rect.right(),rect.bottom());

    linearGrad.setColorAt(0,Qt::blue);//起点颜色
    linearGrad.setColorAt(0.5,Qt::white);   //中间点颜色
    linearGrad.setColorAt(1,Qt::blue);   //终点颜色
    painter.setBrush(linearGrad);
    //绘图
    painter.drawRect(rect);     //绘制矩形
    event->accept();

//    painter.drawLine(80,100,500,500);
//    painter.drawRect(10,10,400,400);
//    painter.setPen(QPen(Qt::blue,5));//设置画笔颜色,宽度
//    painter.drawEllipse(0,0,400,200);
}*/


void Widget::paintEvent(QPaintEvent *event)
{
    QPainter  painter(this);
    int W= this->width();
    int H= this->height();
    QRect  rect(W/4,H/4,W/2,H/2);
    painter.setPen(QPen(Qt::NoPen));
//径向渐变，焦点不同
//设置画笔，不显示线条
    QRadialGradient  radialGrad(W/2,H/2,W/2,3*H/4,H/2);
    radialGrad.setColorAt(0,Qt::yellow);
    radialGrad.setColorAt(0.8,Qt::blue);
    painter.setBrush(radialGrad);
    painter.drawEllipse(rect);
    event->accept();

}
