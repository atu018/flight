#ifndef ENEMY2_H
#define ENEMY2_H
#include "config.h"
#include <QPixmap>
#include <QRect>

class enemy2
{
public:
    enemy2();
    void updatePosition();//更新坐标

    QPixmap m_enemy2;//敌机对象

    int m_x;//坐标
    int m_y;

    QRect m_Rect;//边框

    bool m_free;//状态

    int m_speed;//速度
};

#endif // ENEMY2_H
