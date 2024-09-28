#ifndef DATACONFIG_H
#define DATACONFIG_H

#include <QObject>
#include <QMap>
#include <QVector>

class dataConfig : public QObject
{
    Q_OBJECT
public:
    explicit dataConfig(QObject *parent = 0);

public:

    //容器map：键值对
    //key是int类型，代表的关卡数
    //value相当于一个二维数组，对应每一个硬币的位置
    QMap<int, QVector< QVector<int> > >mData;//双端数组 int 相当于关卡



signals:

public slots:
};

#endif // DATACONFIG_H
