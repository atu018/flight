#include "enemy2.h"
#include "config.h"


enemy2::enemy2()
{
    m_enemy2.load(ENEMY2_PATH);//加载敌机资源
    m_x=0;//敌机位置
    m_y=0;
    m_free = true;//敌机状态
    m_speed = ENEMY2_SPEED;//敌机速度
    m_Rect.setWidth(m_enemy2.width());//设置敌机边框
    m_Rect.setHeight(m_enemy2.height());
    m_Rect.moveTo(m_x,m_y);//位置

}

void enemy2::updatePosition()
{
    if(m_free)
    {
        return;
    }
    m_y+=ENEMY2_SPEED;
    m_Rect.moveTo(m_x,m_y);
    if(m_y>=GAME_HEIGHT)
    {
        m_free = true;
    }
}
