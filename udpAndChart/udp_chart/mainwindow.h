#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QChart>
#include <QChartView>
#include <QLineSeries>
#include <QValueAxis>
#include <QtCharts>
#include <QFile>
/*光添加头文件QChartView还不够，还需要引入QChart的命名空间*/
QT_CHARTS_USE_NAMESPACE

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void CreatChart();

    void loadDataFromFile();

    QVector<double> Read_Datas(QFile& file);

private slots:
    void slotBtnClear();
    void slotTimer();
    void slotTimeout();

private:
    Ui::MainWindow *ui;

    /*用于从Output.txt文件中获取采集的数*/
    QVector<double>  double_datas;//创建一个浮点数向量。

    /* 用于模拟生成实时数据的定时器 */
    QTimer* m_timer;

    /* 图表对象 */
    QChart* m_chart;

    /* 横纵坐标轴对象 */
    QValueAxis *m_axisX, *m_axisY;

    /* 曲线图对象 */
    QLineSeries* m_lineSeries;

    /* 横纵坐标最大显示范围 */
    const int AXIS_MAX_X = 10000000, AXIS_MAX_Y = 10;

    /* 用来记录数据点数 */
    int pointCount = 0;

    /*假设我们希望每秒处理1000个数据点*/
    const int dataPointsPerSecond = 1000;

    const int interval = 1000 / dataPointsPerSecond; // 计算每个数据点需要的间隔时间

    /*设置output.txt文件*/
    QFile output_file;


};
#endif // MAINWINDOW_H
