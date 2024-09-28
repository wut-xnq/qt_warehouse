#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QtCharts>
#include <QMainWindow>
#include <QChartView>
#include <QTimer>
/*光添加头文件QChartView还不够，还需要引入QChart的命名空间。*/

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

private:
    Ui::MainWindow *ui;

    /* 用于模拟生成实时数据的定时器 */
    QTimer* m_timer;

    /* 图表对象 */
    QChart* m_chart;

    /* 横纵坐标轴对象 */
    QValueAxis *m_axisX, *m_axisY;

    /* 曲线图对象 */
    QLineSeries* m_lineSeries;

    /* 横纵坐标最大显示范围 */
    const int AXIS_MAX_X = 10, AXIS_MAX_Y = 10;

    /* 用来记录数据点数 */
    int pointCount = 0;



private slots:
    void slotBtnClear();
    void slotBtnStartAndStop();
    void slotTimeout();
};
#endif // MAINWINDOW_H
