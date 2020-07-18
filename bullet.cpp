#include "bullet.h"
#include "enemeyplane.h"

bullet::bullet()
{
    m_bullet.load(BULLET_PATH);//子弹资源加载
    m_x = GAME_WIDTH * 0.5 - m_bullet.width()*0.5;//坐标
    m_y = GAME_HEIGHT;//坐标
    m_free = true;//子弹状态空闲
    m_speed = BULLEY_SPEED;//子弹速度
    m_Rect.setWidth(m_bullet.width());//子弹边框
    m_Rect.setHeight(m_bullet.height());//子弹边框
    m_Rect.moveTo(m_x,m_y);//子弹移动
}

void bullet::updatePosition()
{
    //空闲
    if(m_free)
    {
        return;
    }
    //非空闲
    m_y -= m_speed;
    m_Rect.moveTo(m_x,m_y);

    if(m_y<m_bullet.height()+48)
    {
        m_free = true;
    }
}
