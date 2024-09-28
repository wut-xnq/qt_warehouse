#include "udpsendreceive.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    udpsendreceive w;
    w.show();
    return a.exec();
}
