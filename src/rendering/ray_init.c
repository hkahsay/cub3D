/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 11:14:21 by ckarl             #+#    #+#             */
/*   Updated: 2023/10/24 21:25:38 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

//general ray data: FOV, angle steps between rays (sub_ray_angle)
void	get_ray_data(t_game *game)
{
	game->ray_data.view_angle = angle_to_rad((double)FOV_ANGLE);
	game->ray_data.sub_ray_angle = angle_to_rad((double)FOV_ANGLE \
				/ (double)MAX_WIDTH);
}

//cast all rays & draw for minimap or draw wall slice for game
void	draw_all_rays(t_game *game)
{
	t_ray	*rays;
	double	ray_angle;
	int		i;

	ray_angle = game->player.dir + (M_PI / 6);
	if (ray_angle > 2 * M_PI)
		ray_angle -= 2 * M_PI;
	rays = malloc(sizeof(t_ray) * MAX_WIDTH);
	if (!rays)
		ft_error_msg(RED"Error\nMalloc failed\n"RESET);
	i = -1;
	while (++i < MAX_WIDTH)
	{
		rays[i].ray_pos = game->player.pos;
		rays[i].player.dir = ray_angle;
		draw_single_ray(&rays[i], game);
		if (game->data->mini_map == 0)
			draw_wall_slice(game, &rays[i], i);
		ray_angle -= game->ray_data.sub_ray_angle;
		if (ray_angle < 0)
			ray_angle += 2 * M_PI;
	}
	free(rays);
}

/*cast horizontal & vertical ray in same direction,
determine which one hits wall sooner to get x position on texture
 + wall height + which texture to use depending on direction*/
void	draw_single_ray(t_ray *ray, t_game *game)
{
	check_direction(&ray->player);
	beta_angle_calc(&ray->player);
	get_horizontal_ray(ray, game);
	get_vertical_ray(ray, game);
	if (ray->eucl_dist.hz < ray->eucl_dist.vt)
	{
		get_wall_height(ray, game, ray->eucl_dist.hz);
		if (check_north(ray->player.dir) == 1)
			ray->texture = &game->data->south_texture;
		else
			ray->texture = &game->data->north_texture;
	}
	else
	{
		get_vertical_wall_xpos(ray);
		get_wall_height(ray, game, ray->eucl_dist.vt);
		if (check_west(ray->player.dir) == 1)
			ray->texture = &game->data->east_texture;
		else
			ray->texture = &game->data->west_texture;
	}
}

//draw the wall slice for game, takes one ray as argument
void	draw_wall_slice(t_game *game, t_ray *ray, int x)
{
	int			y_start;
	t_texel		texel;
	int			color;
	double		offset;

	texel.x = ray->wall_pos_x * ray->texture->img->width;
	texel.y = 0;
	offset = ray->texture->img->height / ray->wallheight;
	if (ray->wallheight > MAX_HEIGHT)
	{
		texel.y = (int)(ray->wallheight / 2) - MAX_HEIGHT / 2;
		ray->wallheight = MAX_HEIGHT;
	}
	y_start = MAX_HEIGHT / 2 - (int)ray->wallheight / 2;
	while (y_start < (MAX_HEIGHT / 2 + (int)(ray->wallheight / 2)))
	{
		color = *(int *)(ray->texture->img->addr + (texel.x * \
			(ray->texture->img->bits_per_pixel / 8)) + \
			((int)(texel.y * offset) * ray->texture->img->line_length));
		my_mlx_pixel_put(&game->img, x, y_start, color);
		y_start++;
		texel.y++;
	}
}

/*get wall height on screen depending on distance between player and wall
get real distance (perpwalldist) from angle ray-camera plane (perwallangle)
wallheight = screen height * perpwalldist*/
void	get_wall_height(t_ray *ray, t_game *game, double distance)
{
	if (game->player.dir < ray->player.dir)
	{
		if ((ray->player.dir_field == S_E || ray->player.dir_field == E) \
		&& game->player.dir_field == N_E)
			ray->perpwallangle = M_PI / 2 - (game->player.dir + 2 * M_PI - \
			ray->player.dir);
		else
			ray->perpwallangle = M_PI / 2 - (ray->player.dir - game->player.dir);
	}
	else
	{
		if ((game->player.dir_field == S_E || game->player.dir_field == E) \
		&& ray->player.dir_field == N_E)
			ray->perpwallangle = M_PI / 2 - (ray->player.dir + 2 * M_PI - \
			game->player.dir);
		else
			ray->perpwallangle = M_PI / 2 - (game->player.dir - ray->player.dir);
	}
	ray->perpwalldist = fabs(distance * sin(ray->perpwallangle));
	ray->wallheight = MAX_HEIGHT / ray->perpwalldist;
}
