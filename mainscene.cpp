#include "mainscene.h"
#include "config.h"
#include <QIcon>
#include <QPainter>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QDebug>
#include <ctime>
#include <QtCore>
#include <QtMultimedia>
#include <QMediaPlaylist>
#include <QMessageBox>
MainScene::MainScene(QWidget *parent)
    : QWidget(parent)
{
    initscene();//初始化场景

    startgame();//启动游戏
}
MainScene::~MainScene()
{

}
void MainScene::initscene()
{
    setFixedSize(GAME_WIDTH,GAME_HEIGHT);//设置窗口

    setWindowTitle(GAME_TITLE);//设置标题

    setWindowIcon(QIcon(GAME_ICON));//初始化图标

    Timer.setInterval(GAME_RATE);//初始化定时器

    m_recorder = 0;//初始化敌机出场时间间隔

    m_recorder2 = 0;//初始化敌机2出场时间间隔

    srand( (unsigned int)time(NULL) );//随机数种子



}



void MainScene::startgame()
{
    QMediaPlayer * player1 = new QMediaPlayer;
    QMediaPlaylist *list1 = new QMediaPlaylist;
    list1->addMedia(QUrl("qrc:/resource/music.mp3"));
    list1->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);//循环播放
    player1->setVolume(SOUND_VOL);
    player1->setPlaylist(list1);
    player1->play();//背景音乐

    Timer.start();
    connect(&Timer, &QTimer::timeout, [=](){
        updateposition();//更新元素坐标
        update();//绘制
        enemy1toscene();//敌机出场
        enemy2toscene();//敌机2出场
        collisiondetection();//碰撞检测

    });
}



void MainScene::updateposition()
{
    m_map.mapPosition();//更新地图坐标
    m_plane1.shoot();//发射子弹
    for(int i= 0;i<HERO_BULLET_NUM;i++)
    {
        if(m_plane1.m_bullets1[i].m_free == false)
        {
            m_plane1.m_bullets1[i].updatePosition();
        }
    }//更新子弹坐标
    for(int i = 0;i<ENEMY1_NUM;i++)
    {
        if(m_enemy1s[i].m_free == false)
        {
            m_enemy1s[i].updatePosition();
        }
    }//更新敌机1坐标
    for(int i = 0;i<ENEMY2_NUM;i++)
    {
        if(m_enemy2s[i].m_free == false)
        {
            m_enemy2s[i].updatePosition();
        }
    }//更新敌机2坐标



    for(int i=0;i<BOMB_NUM;i++)
    {
        if(m_bombs1[i].m_free == false)
        {
            m_bombs1[i].updateinfo();
        }
    }//更新爆炸
}



void MainScene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.drawPixmap(0,m_map.map1_y,m_map.map1);//绘制地图

    painter.drawPixmap(0,m_map.map2_y,m_map.map2);//绘制地图

    painter.drawPixmap(m_plane1.m_x1,m_plane1.m_y1,m_plane1.m_plane1);//绘制飞机1



    for(int i= 0;i<HERO_BULLET_NUM;i++)//绘制飞机1的子弹
    {
        if(m_plane1.m_bullets1[i].m_free == false)
        {
            painter.drawPixmap(m_plane1.m_bullets1[i].m_x,m_plane1.m_bullets1[i].m_y,m_plane1.m_bullets1[i].m_bullet);
        }
    }



    for(int i = 0;i<ENEMY1_NUM;i++)//绘制敌机1
    {
        if(m_enemy1s[i].m_free == false)
        {
            painter.drawPixmap(m_enemy1s[i].m_x,m_enemy1s[i].m_y,m_enemy1s[i].m_enemy);
        }
    }



    for(int i = 0;i<ENEMY2_NUM;i++)//绘制敌机2
    {
        if(m_enemy2s[i].m_free == false)
        {
            painter.drawPixmap(m_enemy2s[i].m_x,m_enemy2s[i].m_y,m_enemy2s[i].m_enemy2);
        }
    }



    for(int i=0;i<BOMB_NUM;i++)//绘制爆炸
    {
        if(m_bombs1[i].m_free == false)
        {
           painter.drawPixmap(m_bombs1[i].m_x,m_bombs1[i].m_y,m_bombs1[i].m_pic1[m_bombs1[i].m_index]);
        }
    }

}

void MainScene::mouseMoveEvent(QMouseEvent *event)//鼠标控制飞机1移动
{
    int x = event -> x() - m_plane1.m_Rect1.width()*0.5;
    int y = event -> y() - m_plane1.m_Rect1.height()*0.5;
    if(x<=0)
    {
        x=0;
    }
    if(x>=GAME_WIDTH-m_plane1.m_Rect1.width())
    {
        x=GAME_WIDTH-m_plane1.m_Rect1.width();
    }
    if(y<=0)
    {
        y=0;
    }
    if(y>=GAME_HEIGHT-m_plane1.m_Rect1.height())
    {
        y=GAME_HEIGHT-m_plane1.m_Rect1.height();
    }

    m_plane1.setPosition(x,y);
}

void MainScene::enemy1toscene()
{
    m_recorder++;
    if(m_recorder<ENEMY1_INTERVAL)
    {
        return;
    }//不出场
    m_recorder = 0;
    for(int i = 0;i<ENEMY1_NUM;i++)
    {
        if(m_enemy1s[i].m_free )
        {
            m_enemy1s[i].m_free = false;
            m_enemy1s[i].m_x = rand()%(GAME_WIDTH-m_enemy1s[i].m_Rect.width()+1);
            m_enemy1s[i].m_y = m_enemy1s[i].m_enemy.height();
            break;
        }
    }
}

void MainScene::enemy2toscene()
{
    m_recorder2++;
    if(m_recorder2<ENEMY2_INTERVAL)
    {
        return;
    }//不出场
    m_recorder2 = 0;
    for(int i = 0;i<ENEMY2_NUM;i++)
    {
        if(m_enemy2s[i].m_free )
        {
            m_enemy2s[i].m_free = false;
            m_enemy2s[i].m_x = rand()%(GAME_WIDTH-m_enemy2s[i].m_Rect.width()+1);
            m_enemy2s[i].m_y = m_enemy2s[i].m_enemy2.height();
            break;
        }
    }
}

void MainScene::collisiondetection()//碰撞检测
{
    for(int i= 0;i<ENEMY1_NUM;i++)
    {
        if(m_enemy1s[i].m_free)
        {
            continue;
        }
        //跳过空闲
        for(int j=0;j<HERO_BULLET_NUM;j++)
        {
            if(m_plane1.m_bullets1[j].m_free)
            {
                continue;
            }
            if(m_enemy1s[i].m_Rect.intersects(m_plane1.m_bullets1[j].m_Rect))
            {
                m_enemy1s[i].m_free = true;
                m_plane1.m_bullets1[j].m_free = true;
                for(int k = 0;k<BOMB_NUM;k++)
                {
                    if(m_bombs1[k].m_free)
                    {
                        m_bombs1[k].m_free = false;
                        m_bombs1[k].m_x = m_enemy1s[i].m_x;//爆炸坐标
                        m_bombs1[k].m_y = m_enemy1s[i].m_y;//爆炸坐标
                        break;
                    }
                }
                QApplication::beep();//敌机爆炸发声
            }
        }     
    }//敌机1



    for(int i= 0;i<ENEMY2_NUM;i++)
    {
        if(m_enemy2s[i].m_free)
        {
            continue;
        }
        //跳过空闲
        for(int j=0;j<HERO_BULLET_NUM;j++)
        {
            if(m_plane1.m_bullets1[j].m_free)
            {
                continue;
            }
            if(m_enemy2s[i].m_Rect.intersects(m_plane1.m_bullets1[j].m_Rect))
            {
                m_enemy2s[i].m_free = true;
                m_plane1.m_bullets1[j].m_free = true;
                for(int k = 0;k<BOMB_NUM;k++)
                {
                    if(m_bombs1[k].m_free)
                    {
                        m_bombs1[k].m_free = false;
                        m_bombs1[k].m_x = m_enemy2s[i].m_x;//爆炸坐标
                        m_bombs1[k].m_y = m_enemy2s[i].m_y;//爆炸坐标
                        break;
                    }
                }
                QApplication::beep();//敌机爆炸发声
            }
        }
    }//敌机2


    for(int i= 0;i<ENEMY1_NUM;i++)
    {
        if(m_enemy1s[i].m_free)
        {
            continue;
        }
        if(m_enemy1s[i].m_Rect.intersects(m_plane1.m_Rect1))
        {
           if(!(QMessageBox::information(this,tr("GAME OVER"),tr("EXIT!!!!"),tr("yes"),tr("try yes"))))
           {
               app->exit(0);
           }
        }
    }//碰撞敌机1终止



    for(int i= 0;i<ENEMY2_NUM;i++)
    {
        if(m_enemy2s[i].m_free)
        {
            continue;
        }
        if(m_enemy2s[i].m_Rect.intersects(m_plane1.m_Rect1))
        {
            if(!(QMessageBox::information(this,tr("GAME OVER"),tr("EXIT!!!!"),tr("yes"),tr("try yes"))))
            {
                app->exit(0);
            }
        }
    }//碰撞敌机2终止
}




