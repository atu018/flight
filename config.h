#ifndef CONFIG_H
#define CONFIG_H
#define CONFIG_H
#define GAME_WIDTH 480 //宽
#define GAME_HEIGHT 700 //高
#define GAME_TITLE "super flight war" //游戏名
#define GAME_ICON ":/resource/app.jpg"//游戏图标
#define MAP_SPEED 2//地图滚动速度
#define RCC_PATH "./plane.rcc" //rcc路径

#define MAP_PATH ":/resource/background.png"//地图图片
#define GAME_RATE 10 //帧率

#define HERO1_PATH ":/resource/me1.png"//玩家1飞机

#define HERO_BULLET_NUM 100 //玩家子弹数目
#define HERO_BULLET_INTERVAL 20//玩家子弹间隔

#define BULLET_PATH ":/resource/bullet1.png"//子弹1
#define BULLEY_SPEED 5//子弹速度

#define ENEMY1_PATH ":/resource/enemy1.png"//敌机1图片
#define ENEMY1_NUM 20//敌机1数量
#define ENEMY1_SPEED 3//敌机1速度
#define ENEMY1_INTERVAL 30//敌机1间隔

#define ENEMY2_PATH ":/resource/enemy2.png"//敌机2图片
#define ENEMY2_NUM 6//敌机2数量
#define ENEMY2_SPEED 15//敌机2速度
#define ENEMY2_INTERVAL 150//敌机2间隔

#define BOMB_PATH ":/resource/enemy1_down%1.png" //爆炸1图片
#define BOMB_NUM 30 //爆炸数量
#define BOMB_PICMAX 4//爆炸图片最大量
#define BOMB_INTERVAL 5//爆炸切图间隔

#define SOUND_BACK ":/resource/music.mp3"//背景音乐
#define SOUND_VOL 100//背景音量
#define BOMB_VOL 100//爆炸音量
#define SHOOT_VOL 100//射击音量




#endif // CONFIG_H
