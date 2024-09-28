#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "network_udp.h"
bool shouldStartTimer = true;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    ,output_file("D://SoftWares//QT//Code//udpAndChart//udp_chart//resultFile.txt")
{
    ui->setupUi(this);
    this->setWindowTitle("Waveform Interface Diagram");
    loadDataFromFile(); // 加载数据
    m_timer = new QTimer(this);
    m_timer->setSingleShot(false);       //setSingleShot方法的作用是设置计时器是否只发出一次信号。
    QObject::connect(m_timer, SIGNAL(timeout()), this, SLOT(slotTimeout()));
    QObject::connect(ui->ClearBtn, SIGNAL(clicked(bool)), this, SLOT(slotBtnClear()));
    QObject::connect(ui->Timer, SIGNAL(clicked(bool)), this, SLOT(slotTimer()));
    CreatChart();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::CreatChart()
{
    //创建横纵坐标轴并设置显示范围
    m_axisX = new QValueAxis();
    m_axisY = new QValueAxis();
    m_axisX->setTitleText("X-label");
    m_axisY->setTitleText("Y-label");
    m_axisX->setMin(0);
    m_axisY->setMin(-5);
    m_axisX->setMax(2000);
    m_axisY->setMax(5);

    m_lineSeries = new QLineSeries();
    m_lineSeries->setPointsVisible(false);       //设置数据点可见
    m_lineSeries->setName("Square Wave Curve");

    m_chart = new QChart();
    QChart::ChartTheme darkTheme = QChart::ChartTheme::ChartThemeDark;
    QChart::AnimationOptions seriesAnimations = QChart::AnimationOption::AllAnimations;
    m_chart->setAnimationOptions(seriesAnimations);
    m_chart->setTheme(darkTheme) ;
    m_chart->addAxis(m_axisY, Qt::AlignLeft);     //将x轴添加到图表
    m_chart->addAxis(m_axisX,Qt::AlignBottom);
    m_chart->addSeries(m_lineSeries);
    m_chart->setAnimationOptions(QChart::SeriesAnimations);     // 动画：能使曲线绘制显示的更平滑，过渡效果更好看

    m_lineSeries->attachAxis(m_axisX);
    m_lineSeries->attachAxis(m_axisY);

    ui->graphicsView->setChart(m_chart);                        // 将图表对象设置到graphicsView上进行显示
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);    // 设置渲染：抗锯齿，如果不设置那么曲线就显得不平滑


}

void MainWindow::slotBtnClear()
{
    m_lineSeries->clear();
    m_chart->axisX()->setMin(0);
    m_chart->axisX()->setMax(2000);
    pointCount = 0;
}

void MainWindow::slotTimer()
{
    if(shouldStartTimer)
    {
        m_timer->start(interval);
        shouldStartTimer = false;
        ui->Timer->setText("停止定时器");
    }
    else
    {
        m_timer->stop();
        shouldStartTimer = true;
        ui->Timer->setText("启动定时器");
    }
}


//生成随机数曲线
//void MainWindow::slotTimeout()
//{
//    if(pointCount > 1000)
//    {
//        m_lineSeries->remove(0);//从数据序列的开始（第一个元素）移除一个点。通常这是为了确保图表中显示的点数不会超过X轴的最大限制。
//        m_chart->axisX()->setMin(pointCount - 1000);
//        m_chart->axisX()->setMax(pointCount);                    // 更新X轴范围
//    }
//    m_lineSeries->append(QPointF(pointCount, rand() % 10));  // 更新显示（随机生成10以内的一个数）
//    pointCount++;
//}

//生成曲线图
void MainWindow::slotTimeout()
{
    if(pointCount > 2000)
    {
        m_lineSeries->remove(0); // 从数据序列的开始（第一个元素）移除一个点
        m_chart->axisX()->setMin(pointCount - 2000);
        m_chart->axisX()->setMax(pointCount); // 更新X轴范围
    }

    // 确保我们有足够的点可以显示
    if (pointCount < double_datas.size()) {
        // 使用double_datas中的值
        m_lineSeries->append(QPointF(pointCount, double_datas[pointCount]));
    } else {
        // 如果double_datas中的数据用完了，可以选择填充一个默认值或者停止定时器
        m_lineSeries->append(QPointF(pointCount, 0.0)); // 填充默认值0.0
        // 或者可以选择停止定时器
        //m_timer->stop();
    }
    pointCount++;
}

QVector<double> MainWindow:: Read_Datas(QFile& file)
{

    // 尝试打开文件
    if (!output_file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "无法打开文件";
        return double_datas; // 返回空向量
    }

    QTextStream in(&output_file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        bool ok;
        double value = line.toDouble(&ok); // 尝试将读取的行转换为double类型

        if (ok) {
            double_datas.append(value); // 如果转换成功，则添加到向量中
        } else {
            qDebug() << "无法转换行到double" << line;
        }
    }

    output_file.close(); // 关闭文件
    return double_datas; // 返回读取的数据
}

// 在MainWindow类的构造函数或其他适当的位置调用此函数来加载数据
void MainWindow::loadDataFromFile() {
    // 确保filePath指向了包含数据的文件
    double_datas = Read_Datas(output_file);

    // 检查是否读取了数据
    if (double_datas.isEmpty()) {
        qDebug() << "没有从文件中读取到数据";
    } else {
        qDebug() << "从文件中读取了" << double_datas.size() << "个数据点";
    }
}
