#ifndef WIDGET_H
#define WIDGET_H
#include<QFileDialog>
#include<QColorDialog>
#include <QWidget>
#include<QFontDialog>
#include<QProgressDialog>
#include<QElapsedTimer>
#include<QLineEdit>
#include<QInputDialog>
#include<QMessageBox>
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_Open_File_clicked();

    void on_Open_Files_clicked();

    void on_Save_Files_clicked();

    void on_Existed_Contents_clicked();

    void on_Select_Colors_clicked();

    void on_Select_Font_clicked();

    void on_Process_Dialog_clicked();

    void do_progress_canceled();
    void on_Input_Str_clicked();

    void on_Input_Int_clicked();

    void on_Input_Float_clicked();

    void on_Setting_Selection_Input_clicked();

    void on_Question_Btn_clicked();

    void on_Information_Btn_clicked();

    void on_Warning_Btn_clicked();

    void on_About_Btn_clicked();

    void on_Critical_Btn_clicked();

    void on_AboutQt_Btn_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_Clear_Btn_clicked();

    void on_Exit_Btn_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
