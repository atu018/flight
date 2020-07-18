#ifndef HEROPLANE1_H
#define HEROPLANE1_H
#include <QPixmap>
#include <QRect>
#include "bullet.h"
#include "config.h"

class HeroPlane1
{
public:
    HeroPlane1();
    void shoot();//发射子弹
    void setPosition(int x,int y);//飞机坐标
    QPixmap m_plane1;//飞机对象
    int m_x1;//飞机坐标
    int m_y1;//飞机坐标
    QRect m_Rect1;//判断边框
    bullet m_bullets1[HERO_BULLET_NUM];//弹夹
    int m_recorder1;//发射间隔


};

#endif // HEROPLANE1_H
