#include "../../includes/cub3d.h"

void init_time(t_time *time)
{
	time->time = 0;
	time->oldTime = 0;
}

void get_deltaSide(double deltaSide)
{
	if (deltaSide == 0)
		deltaSide = 1e30;
	else
		deltaSide = fabs(1 / deltaSide);
}

void calculate_step_sideDist(t_ray *ray)
{
	if (ray->rayDir.x < 0)
	{
		ray->step.x = -1;
		ray->sideDist.x = (ray->player->pos.x - ray->tileSize.x) * ray->deltaDist.x;
	}
	else
	{
		ray->step.x = 1;
		ray->sideDist.x = (ray->tileSize.x + 1.0f - ray->player->pos.x) *ray->deltaDist.x;
	}
	if (ray->rayDir.y < 0)
	{
		ray->step.y = -1;
		ray->sideDist.y = (ray->player->pos.y - ray->tileSize.y) * ray->deltaDist.y;
	}
	else
	{
		ray->step.y = 1;
		ray->sideDist.y = (ray->tileSize.y + 1.0f - ray->player->pos.y) * ray->deltaDist.y;
	}
}
