#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QApplication>
#include <QWidget>
#include <QTimer>
#include "map.h"
#include "heroplane1.h"
#include "bullet.h"
#include "config.h"
#include "enemeyplane.h"
#include "bomb.h"
#include "enemy2.h"
class MainScene : public QWidget
{
    Q_OBJECT

public:
    MainScene(QWidget *parent = 0);
    ~MainScene();
    void initscene();//初始化场景
    QTimer Timer;//定时器
    void startgame();//启动该游戏
    void updateposition();//更新坐标
    void paintEvent(QPaintEvent *);//绘制
    map m_map;//地图
    HeroPlane1 m_plane1;//飞机1
    void mouseMoveEvent(QMouseEvent *);//鼠标移动
    void enemy1toscene();//敌机1出场
    void enemy2toscene();//敌机2出场
    EnemeyPlane m_enemy1s[ENEMY1_NUM];//敌机数组
    enemy2 m_enemy2s[ENEMY2_NUM];//敌机2数组
    int m_recorder;//记录间隔
    int m_recorder2;//记录间隔
    void collisiondetection();//碰撞检测
    bomb m_bombs1[BOMB_NUM];//爆炸数组
    QApplication* app;//终止程序






};

#endif // MAINSCENE_H
