#include "heroplane1.h"
#include "config.h"
#include <QtMultimedia>
#include <QMediaPlaylist>

HeroPlane1::HeroPlane1()
{
    m_plane1.load(HERO1_PATH);
    m_x1 = (GAME_WIDTH - m_plane1.width())*0.3;
    m_y1 = (GAME_HEIGHT- m_plane1.height());
    m_Rect1.setWidth(m_plane1.width());
    m_Rect1.setHeight(m_plane1.height());
    m_Rect1.moveTo(m_x1,m_y1);
}

void HeroPlane1::shoot()
{
    m_recorder1++;//累加时间间隔
    if(m_recorder1 < HERO_BULLET_INTERVAL )
    {
        return;
    }
    m_recorder1 = 0;
    for(int i = 0;i<HERO_BULLET_NUM;i++)
    {
        if(m_bullets1[i].m_free)
        {
            m_bullets1[i].m_free = false;
            m_bullets1[i].m_x = m_x1 + m_Rect1.width()*0.5 ;//子弹发射坐标
            m_bullets1[i].m_y = m_y1 - 15;

            break;
        }
        QMediaPlayer * player = new QMediaPlayer;
        player->setMedia(QUrl("qrc:/resource/fire2.mp3"));
        player->setVolume(SHOOT_VOL);
        player->play();
    }
}

void HeroPlane1::setPosition(int x, int y)
{
    m_x1 = x;
    m_y1 = y;
    m_Rect1.moveTo(m_x1,m_y1);
}
