#include "../../includes/cub3d.h"

void    normalize_angle_rad(double *angle)
{
    *angle = remainder(*angle, 2 * M_PI);
    if (*angle < 0)
        *angle = (2 * M_PI) + *angle;
}