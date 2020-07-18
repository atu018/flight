#ifndef MAP_H
#define MAP_H
#include <QPixmap>


class map
{
public:
    map();
    void mapPosition();//地图计算
    QPixmap map1;//地图图片
    QPixmap map2;//地图图片
    int map1_y;//地图坐标1
    int map2_y;//地图坐标2
    int map_speed;//地图滚动速度

};

#endif // MAP_H
