#include "mainscene.h"
#include "ui_mainscene.h"
#include "mypushbutton.h"
#include<QPainter>
#include <QMainWindow>
#include<QPaintEvent>
#include<QDebug>
#include"chooselevelscene.h"
#include<QTimer>
#include<QSound>
MainScene::MainScene(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainScene)
{
    ui->setupUi(this);

    //配置主场景

    //设置固定大小
    setFixedSize(600,800);

    //设置图标
    setWindowIcon(QIcon(":/res/Coin.png"));

    //设置标题
    setWindowTitle("爆金币主场景");

    //退出
    connect(ui->actionquit,&QAction::triggered,[=]()
    {
        this->close();
    });

    //准备开始按钮的音效
    QSound * startSound = new QSound(":/res/TapButtonSound.wav");
//    startSound->setLoops(-1);       //设置循环 如果是-1 代表无限循环
//    startSound->play();


    //开始的按钮
    MyPushButton * startBtn = new MyPushButton(":/res/MenuSceneStartButton.png");
    startBtn->setParent(this);
    startBtn->move(this->width()*0.5 - startBtn->width() * 0.5,this->height() * 0.7);

    //实例化选择关卡场景
    chooseScene = new ChooseLevelScene(this);

    //监听选择关卡的返回按钮的信号
    connect(chooseScene,&ChooseLevelScene::chooseSceneBack,this,[=]
    {
        this->setGeometry(chooseScene->geometry());
        chooseScene->hide();        //将选择关卡场景 隐藏掉
        this->show();       //重新显示主场景
    });
    connect(startBtn,&MyPushButton::clicked,[=]()
    {
        //qDebug()<<"点击了开始";

        //播放开始音效资源
        startSound->play();

        //做弹起特效
        startBtn->zoom1();
        //startBtn->zoom2();

        //延时进入选择关卡场景中
        QTimer::singleShot(500,this,[=]()
        {
            //设置chooseScene场景的位置
            chooseScene->setGeometry(this->geometry());
            //自身隐藏
            this->hide();
            //显示选择关卡场景
            chooseScene->show();
        });

    });
}

MainScene::~MainScene()
{
    delete ui;
}

void MainScene::paintEvent(QPaintEvent * event)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
    //画背景上图标
    pix.load(":/res/Title.png");

    pix.scaled(pix.width() * 0.5,pix.height() * 0.5);


    painter.drawPixmap(10,30,pix);
}
