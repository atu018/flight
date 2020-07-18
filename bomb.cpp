#include "bomb.h"

bomb::bomb()
{
    for(int i = 1;i<=BOMB_PICMAX;i++)
    {
        QString str = QString( BOMB_PATH).arg(i);
        m_pic1.push_back(QPixmap(str));
    }//加载图片
    m_x = -100;
    m_y = -100;
    m_free = true;
    m_index = 0;
    m_recorder = 0;

}

void bomb::updateinfo()
{
    if(m_free)
    {
        return;
    }
    m_recorder++;
    if(m_recorder<BOMB_INTERVAL)
    {
        return;
    }
    m_recorder = 0;
    m_index++;
    if(m_index>BOMB_PICMAX-1)
    {
        m_index = 0;
        m_free = true;
    }
}
