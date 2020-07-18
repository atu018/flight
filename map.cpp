#include "map.h"
#include "config.h"

map::map()
{
    map1.load(MAP_PATH);
    map2.load(MAP_PATH);//加载地图
    map1_y = -GAME_HEIGHT;
    map2_y = 0;
    map_speed = MAP_SPEED;
}

void map::mapPosition()
{
    map1_y = map1_y+map_speed;
    if(map1_y>=0)
    {
        map1_y=-GAME_HEIGHT;
    }
    map2_y = map2_y+map_speed;
    if(map2_y>=GAME_HEIGHT)
    {
        map2_y=0;
    }

}
