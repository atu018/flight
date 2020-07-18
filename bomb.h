#ifndef BOMB_H
#define BOMB_H
#include <QPixmap>
#include <QVector>
#include "config.h"


class bomb
{
public:
    bomb();
    void updateinfo();//更新信息
    QVector<QPixmap> m_pic1;//爆炸数组
    int m_x;//坐标
    int m_y;
    bool m_free;//状态
    int m_recorder;//时间间隔
    int m_index;//图片下标


};

#endif // BOMB_H
