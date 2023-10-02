#include "../../includes/cub3d.h"

double    angle_to_rad(double rad)
{
    rad = rad * (PI / 180);
    return (rad);
}

double    rad_to_angle(double angle)
{
    angle = angle * (180 / M_PI);
    return (angle);
}

int pixel_to_coord(float n)
{
    int res;

    res = n / SCALE_MINI_MAP;
    return (res);
}

//check_north is returns 1 if the angle is between 180 and 360 degrees that is the player is facing north
//else it returns 0 thats is the player is facing south
int check_south(double angle)
{
    if (angle > 0 && angle < M_PI)
        return (1);
    else
        return (0);
}

//check_west is returns 1 if the angle is between 90 and 270 degrees that is the player is facing west 
//else it returns 0 thats is the player is facing east

int check_west(double angle)
{
    if (angle > M_PI / 2 && angle < 3 * M_PI / 2)
        return (1);
    else
        return (0);
}