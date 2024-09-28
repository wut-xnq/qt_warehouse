#include "mainwindow.h"
#include <QApplication>
#include <network_udp.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    network_udp w2;
    if(w2.exec()==QDialog::Accepted)
    {
    w.show();
    return a.exec();
    }
    else
    {
        return 0;
    }
}
