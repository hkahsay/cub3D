/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 16:57:44 by ckarl             #+#    #+#             */
/*   Updated: 2023/10/02 18:45:55 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	put_player_pixel(t_game *game)
{
	get_player(game);
	draw_player(game);
}

void	get_player(t_game *game)
{
	// generate_img(&game->img, &game->mlx, 4, 4);
	game->player.dir.x = 0;
	game->player.dir.y = 0;
	game->player.moveSpeed = 0.15;
	game->player.rotSpeed = angle_to_rad(4);
	get_starting_position(&game->player, game->data->map_data.map);
}

void	get_starting_position(t_player *player, char **grid)
{
	int	i;
	int	j;

	i = -1;
	while (grid[++i])
	{
		j = -1;
		while (grid[i][++j])
		{
			if (ft_strchr("NSWE", grid[i][j]))
			{
				player->pos.x = j * SCALE_MINI_MAP + 5;
				player->pos.y = i * SCALE_MINI_MAP + 5;
				player->rotAngle = starting_angle(grid[i][j]);
				grid[i][j] = '0';
			}
		}
	}
}

double	starting_angle(char c)
{
	double	radian;

	radian = 0;
	if (c == 'N')
		radian = angle_to_rad(270); //a negative Y direction represents "up" or "North,"
	else if (c == 'S')
		radian = angle_to_rad(90); //a positive Y direction represents "down" or "South,"
	else if (c == 'W')
		radian = angle_to_rad(180); //a negative X direction represents "left" or "West,"
	else if (c == 'E')
		radian = angle_to_rad(0); //a positive X direction represents "right" or "East,"
	return (radian);
}

void	move_mini(t_game *game)
{
	if (game->keys.w)
		game->player.pos.y -= 5; // Move up
	else if (game->keys.s)
		game->player.pos.y += 5; // Move down
	else if (game->keys.a)
		game->player.pos.x -= 5; // Move left
	else if (game->keys.d)
		game->player.pos.x += 5; // Move right
	else if (game->keys.esc)
		exit_game(game);
	mlx_clear_window(game->mlx.mlx_ptr, game->mlx.win_mlx);
}

void	draw_player(t_game *game)
{
	int	y;
	int	x;
	int	start_x;
	int	start_y;

	start_x = (int)game->player.pos.x;
	start_y = (int)game->player.pos.y;
	if (start_x < 0)
		start_x = 0;
	if (start_y < 0)
		start_y = 0;
	x = start_x;
	while (x <= start_x + 5 && x <= game->data->map_data.m_width * 64)
	{
		y = start_y;
		while (y <= start_y + 5 && y <= game->data->map_data.m_height * 64)
		{
			my_mlx_pixel_put(&game->img, x, y, 0x00FF0000);
			y++;
		}
		x++;
	}
}
