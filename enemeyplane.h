#ifndef ENEMEYPLANE_H
#define ENEMEYPLANE_H
#include <QPixmap>
#include <QRect>


class EnemeyPlane
{
public:
    EnemeyPlane();

    void updatePosition();//更新坐标

    QPixmap m_enemy;//敌机对象

    int m_x;//坐标
    int m_y;

    QRect m_Rect;//边框

    bool m_free;//状态

    int m_speed;//速度

};

#endif // ENEMEYPLANE_H
