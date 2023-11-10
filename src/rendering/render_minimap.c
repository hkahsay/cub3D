/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 10:50:22 by ckarl             #+#    #+#             */
/*   Updated: 2023/11/10 11:26:35 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	render_mini_map(t_game *game)
{
	if (game->data->map_data.m_height * 15 < MAX_HEIGHT && \
	game->data->map_data.m_width * 15 < MAX_WIDTH)
	{
		generate_img(&game->img, &game->mlx, MAX_WIDTH, MAX_HEIGHT);
		render_2dmap_wall(game);
		draw_2dgrid(game);
		draw_player_minimap(game);
		key_event(game);
		draw_all_rays(game);
		mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_mlx, \
								game->img.img, 0, 0);
		mlx_destroy_image(game->mlx.mlx_ptr, game->img.img);
	}
	return (0);
}

void	draw_wall(t_game *game, t_wall_coordinate wall_coord)
{
	int	x;
	int	y;

	y = 0;
	while (y < SCALE_MINI_MAP)
	{
		x = 0;
		while (x < SCALE_MINI_MAP)
		{
			my_mlx_pixel_put(&game->img, wall_coord.x * SCALE_MINI_MAP + x, \
							wall_coord.y * SCALE_MINI_MAP + y, 0x00FFFFFF);
			x++;
		}
		y++;
	}
}

void	render_2dmap_wall(t_game *game)
{
	int					i;
	int					j;
	t_wall_coordinate	coord_wall;

	j = 0;
	while (j < game->data->map_data.m_height)
	{
		i = 0;
		while (i < game->data->map_data.m_width)
		{
			if (game->data->map_data.map[j][i] == '1')
			{
				coord_wall.x = i;
				coord_wall.y = j;
				draw_wall(game, coord_wall);
			}
			i++;
		}
		j++;
	}
}

void	draw_2dgrid(t_game *game)
{
	double	i;
	double	j;
	double	cellsize_x;
	double	cellsize_y;

	cellsize_x = SCALE_MINI_MAP;
	cellsize_y = SCALE_MINI_MAP;
	i = 0;
	while (i <= game->data->map_data.m_width * SCALE_MINI_MAP)
	{
		j = -1;
		while (++j <= game->data->map_data.m_height * SCALE_MINI_MAP)
			my_mlx_pixel_put(&game->img, i, j, 0x0000FF);
		i += cellsize_x;
	}
	j = cellsize_y;
	while (j <= game->data->map_data.m_height * SCALE_MINI_MAP)
	{
		i = -1;
		while (++i <= game->data->map_data.m_width * SCALE_MINI_MAP)
			my_mlx_pixel_put(&game->img, i, j, 0x0000FF);
		j += cellsize_y;
	}
}

//draw little red square on minimap
void	draw_player_minimap(t_game *game)
{
	double	y;
	double	x;
	double	start_x;
	double	start_y;

	start_x = (game->player.pos.x) * SCALE_MINI_MAP;
	start_y = (game->player.pos.y) * SCALE_MINI_MAP;
	if (start_x < 0)
		start_x = 0;
	if (start_y < 0)
		start_y = 0;
	x = start_x;
	while (x <= start_x + 2 && x <= game->data->map_data.m_width * 15)
	{
		y = start_y;
		while (y <= start_y + 2 && y <= game->data->map_data.m_height * 15)
		{
			my_mlx_pixel_put(&game->img, x, y, 0x00FF0000);
			y++;
		}
		x++;
	}
}
