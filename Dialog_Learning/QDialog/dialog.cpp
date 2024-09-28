#include "dialog.h"
#include "ui_dialog.h"
#include<QFileDialog>
Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_Open_Files_clicked()
{
    //选择单个文件
    QString curPath = QDir::currentPath();      //获取系统当前目录
    QString dlgTitle = "选择一个文件";        //对话框标题
    QString filter = "文本文件(*.txt);;图片文件(*.jpg *.gif *.png);;所有文件(*.*)";
    QString fileName = QFileDialog::getOpenFileName(this,dlgTitle,curPath,filter);
    if(!fileName.isEmpty())
    {
        ui->plainTextEdit->appendPlainText(fileName);
    }
}
