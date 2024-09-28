#include "widget.h"
#include "ui_widget.h"
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("标准对话框");
    // 设置窗口的最小大小为800x600像素
    this->setMinimumSize(QSize(940, 759));

    // 设置窗口的最大大小为800x600像素
    this->setMaximumSize(QSize(940, 759));

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_Open_File_clicked()
{
    //选择单个文件
       QString curPath= QDir::currentPath();                  //获取系统当前目录
       QString dlgTitle= "选择一个文件";                        //对话框标题
       QString filter= "文本文件(*.txt);;图片文件(*.jpg *.gif *.png);;所有文件(*.*)";
       QString fileName= QFileDialog::getOpenFileName(this,dlgTitle,curPath,filter);
       if (!fileName.isEmpty())
           ui->plainTextEdit->appendPlainText(fileName);
}

void Widget::on_Open_Files_clicked()
{
    //选择打开多个文件
        QString curPath= QDir::currentPath();
        QString dlgTitle= "打开多个文件";
        QString filter= "文本文件(*.txt);;图片文件(*.jpg *.gif *.png);;所有文件(*.*)";
        QStringList fileList= QFileDialog::getOpenFileNames(this,dlgTitle,curPath,filter);
        for (int i=0; i<fileList.size(); i++)
             ui->plainTextEdit->appendPlainText(fileList.at(i));
}

void Widget::on_Save_Files_clicked()
{//保存文件
    QString curPath= QCoreApplication::applicationDirPath();
    QString dlgTitle= "保存文件";
    QString filter= "文本文件(*.txt);;h 文件(*.h);;C++文件(.cpp);;所有文件(*.*)";
    QString fileName= QFileDialog::getSaveFileName(this,dlgTitle,curPath,filter);
    if (!fileName.isEmpty())
        ui->plainTextEdit->appendPlainText(fileName);
}

void Widget::on_Existed_Contents_clicked()
{
    QString curPath= QCoreApplication::applicationDirPath();
    QString dlgTitle= "选择一个目录";
    QString selectedDir= QFileDialog::getExistingDirectory(this, dlgTitle, curPath);
    if (!selectedDir.isEmpty())
        ui->plainTextEdit->appendPlainText(selectedDir);
}

void Widget::on_Select_Colors_clicked()
{
    QPalette pal= ui->plainTextEdit->palette();
       QColor  iniColor= pal.color(QPalette::Text);     //现有的文字颜色
       QColor color= QColorDialog::getColor(iniColor,this,"选择颜色");
       if (color.isValid())   //选择有效
       {
           pal.setColor(QPalette::Text,color);          //设置选择的颜色
           ui->plainTextEdit->setPalette(pal);          //设置 palette
       }
}

void Widget::on_Select_Font_clicked()
{
    QFont iniFont= ui->plainTextEdit->font();        //获取文本框的字体
    bool   ok= false;                                //作为返回值
    QFont font= QFontDialog::getFont(&ok,iniFont);   //选择字体
    if (ok)                                          //选择有效
        ui->plainTextEdit->setFont(font);
}

void Widget::on_Process_Dialog_clicked()
{
    QString labText= "正在复制文件...";
     QString btnText= "取消";
     int   minV=0, maxV=200;
     QProgressDialog dlgProgress(labText,btnText, minV, maxV, this);
     connect(&dlgProgress, SIGNAL(canceled()),this,SLOT(do_progress_canceled()));
     dlgProgress.setWindowTitle("复制文件");
     dlgProgress.setWindowModality(Qt::WindowModal);         //以模态方式显示对话框
     dlgProgress.setAutoReset(true);              //value()达到最大值时自动调用reset()
     dlgProgress.setAutoClose(true);                         //调用 reset()时隐藏窗口
     QElapsedTimer msCounter;                                //计时器
     for(int i=minV; i<=maxV; i++)                           //用循环表示操作进度
     {  dlgProgress.setValue(i);
         dlgProgress.setLabelText(QString::asprintf("正在复制文件,第 %d 个",i));
         msCounter.start();
         while(true)
         {
             if (msCounter.elapsed()>30)                     //运行时间 30ms
                 break;
         }
         if (dlgProgress.wasCanceled())                      //中途取消
             break;
     }
}

void Widget::do_progress_canceled()
{//与进度对话框canceled()信号关联的槽函数
    ui->plainTextEdit->appendPlainText("**进度对话框被取消了**");
}

void Widget::on_Input_Str_clicked()
{
    //输入字符串
        QString dlgTitle= "输入文字对话框";
        QString txtLabel= "请输入文件名";
        QString iniInput= "新建文件.txt";
        QLineEdit::EchoMode echoMode= QLineEdit::Normal;                  //正常文字输入
        bool ok= false;
        QString text = QInputDialog::getText(this, dlgTitle, txtLabel, echoMode, iniInput, &ok);
        if (ok && !text.isEmpty())
            ui->plainTextEdit->appendPlainText(text);
}

void Widget::on_Input_Int_clicked()
{
    QString dlgTitle= "输入整数对话框";
        QString txtLabel= "设置文本框字体大小";
        int defaultValue= ui->plainTextEdit->font().pointSize();          //现有字体大小
        int minValue= 6, maxValue= 50, stepValue= 1;                      //范围、步长
        bool ok= false;
        int inputValue = QInputDialog::getInt(this, dlgTitle,txtLabel,
                                       defaultValue, minValue,maxValue,stepValue,&ok);
        if (ok)
        {
            QString str= QString("文本框字体大小被设置为:%1").arg(inputValue);
            ui->plainTextEdit->appendPlainText(str);
            QFont   font= ui->plainTextEdit->font();
            font.setPointSize(inputValue);
            ui->plainTextEdit->setFont(font);
        }
}

void Widget::on_Input_Float_clicked()
{
    QString dlgTitle= "输入浮点数对话框";
       QString txtLabel= "输入一个浮点数";
       float defaultValue= 3.13;
       float minValue= 0, maxValue= 10000;           //范围
       int decimals= 2;                              //小数点位数
       bool ok= false;
       float inputValue = QInputDialog::getDouble(this, dlgTitle,txtLabel,
                                     defaultValue, minValue,maxValue,decimals,&ok);
       if (ok)
       {
           QString str= QString::asprintf("输入了一个浮点数:%.2f",inputValue);
           ui->plainTextEdit->appendPlainText(str);
       }
}

void Widget::on_Setting_Selection_Input_clicked()
{
    QStringList items;
        items<<"优秀"<<"良好"<<"合格"<<"不合格";
        QString dlgTitle= "条目选择对话框";
        QString txtLabel= "请选择级别";
        int    curIndex= 0;                        //初始选择项
        bool   editable= true;                     //是否可编辑
        bool   ok= false;
        QString text = QInputDialog::getItem(this, dlgTitle, txtLabel,items, curIndex, editable, &ok);

        if (ok && !text.isEmpty())
                 ui->plainTextEdit->appendPlainText(text);
}

void Widget::on_Question_Btn_clicked()
{
    QString dlgTitle= "Question 消息框";
        QString strInfo = "文件已被修改，是否保存修改？";

        QMessageBox::StandardButton  defaultBtn= QMessageBox::NoButton;    //默认按钮
        QMessageBox::StandardButton result;                           //返回选择的按钮内容
        result=QMessageBox::question(this, dlgTitle, strInfo,
                                QMessageBox::Yes|QMessageBox::No |QMessageBox::Cancel,
                                defaultBtn);
        if (result == QMessageBox::Yes)
            ui->plainTextEdit->appendPlainText("Question 消息框: Yes 被选择");
        else if(result == QMessageBox::No)
            ui->plainTextEdit->appendPlainText("Question 消息框: No 被选择");
        else if(result == QMessageBox::Cancel)
            ui->plainTextEdit->appendPlainText("Question 消息框: Cancel 被选择");
        else
            ui->plainTextEdit->appendPlainText("Question 消息框: 无选择");
}

void Widget::on_Information_Btn_clicked()
{
    //information
        QString dlgTitle= "information 消息框";
        QString strInfo = "文件已经打开，请检查";
        QMessageBox::information(this, dlgTitle, strInfo,
                                 QMessageBox::Ok, QMessageBox::NoButton);

}

void Widget::on_Warning_Btn_clicked()
{
    QString dlgTitle= "warning 消息框";
    QString strInfo = "文件内容已经被修改";
    QMessageBox::warning(this, dlgTitle, strInfo);
}

void Widget::on_About_Btn_clicked()
{
    QString dlgTitle= "about 消息框";
    QString strInfo = "SEGY 文件查看软件 V1.0 \nDesigned by wwb";
    QMessageBox::about(this, dlgTitle, strInfo);
}

void Widget::on_Critical_Btn_clicked()
{
    QString dlgTitle= "critical 消息框";
       QString strInfo = "有不明程序访问网络";
       QMessageBox::critical(this, dlgTitle, strInfo);
}

void Widget::on_AboutQt_Btn_clicked()
{
    QString dlgTitle= "about 消息框";
    QString strInfo = "SEGY 文件查看软件 V1.0 \nDesigned by wwb";
    QMessageBox::about(this, dlgTitle, strInfo);
}

void Widget::on_pushButton_clicked()
{

}

void Widget::on_pushButton_2_clicked()
{

}

void Widget::on_Clear_Btn_clicked()
{
    ui->plainTextEdit->clear();
}

void Widget::on_Exit_Btn_clicked()
{
    close();
}
