#ifndef BULLET_H
#define BULLET_H
#include <QPixmap>
#include <QRect>
#include "config.h"

class bullet
{
public:
    bullet();
    void updatePosition();//更新子弹坐标
    QPixmap m_bullet;//子弹对象
    int m_x;//子弹x坐标
    int m_y;//子弹y坐标
    int m_speed;//子弹速度
    bool m_free;//子弹是否空闲
    QRect m_Rect;//子弹边框
};

#endif // BULLET_H
