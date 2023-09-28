#include "../../includes/cub3d.h"

double    angle_to_rad(double rad)
{
    rad = rad * (PI / 180);
    return (rad);
}

double    rad_to_angle(double angle)
{
    angle = angle * (180 / PI);
    return (angle);
}
