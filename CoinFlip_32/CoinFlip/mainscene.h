#ifndef MAINSCENE_H
#define MAINSCENE_H
#include<QPainter>
#include <QMainWindow>
#include<QPaintEvent>
#include<QDebug>
#include"chooselevelscene.h"
#include<QTimer>
QT_BEGIN_NAMESPACE
namespace Ui { class MainScene; }
QT_END_NAMESPACE

class MainScene : public QMainWindow
{
    Q_OBJECT

public:
    MainScene(QWidget *parent = nullptr);
    ~MainScene();

    //重写paintEvent时间 画背景图
    void paintEvent(QPaintEvent *);
    ChooseLevelScene * chooseScene =  NULL;
private:
    Ui::MainScene *ui;
};
#endif // MAINSCENE_H
