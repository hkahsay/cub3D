/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 16:56:58 by ckarl             #+#    #+#             */
/*   Updated: 2023/10/11 13:57:10 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"


void	move_forward(t_game *game)
{
	t_coord	update;

	check_direction(&(game->player));
	if (game->player.dir_field == N_E) //north east
		move_in_angle(&update, &(game->player), 1, north - game->player.dir);
	else if (game->player.dir_field == N_W) //north west
		move_in_angle(&update, &(game->player), 1, west - game->player.dir);
	else if (game->player.dir_field == S_W) //south east
		move_in_angle(&update, &(game->player), 0, south - game->player.dir);
	else if (game->player.dir_field == S_E) //south west
		move_in_angle(&update, &(game->player), 0, east - game->player.dir);
	else
		move_straight(&update, game, forward);
	if (game->data->map_data.map[(int)update.y]\
	[(int)(update.x)] == '0')
	{
		game->player.pos.x = update.x;
		game->player.pos.y = update.y;
	}
}

void	move_backward(t_game *game)
{
	t_coord	update;

	check_direction(&(game->player));
	if (game->player.dir_field == N_E) //north east
		move_in_angle(&update, &(game->player), 0, north - game->player.dir);
	else if (game->player.dir_field == N_W) //north west
		move_in_angle(&update, &(game->player), 0, west - game->player.dir);
	else if (game->player.dir_field == S_W) //south east
		move_in_angle(&update, &(game->player), 1, south - game->player.dir);
	else if (game->player.dir_field == S_E) //south west
		move_in_angle(&update, &(game->player), 1, east - game->player.dir);
	else
		move_straight(&update, game, backward);
	if (game->data->map_data.map[(int)update.y]\
	[(int)(update.x)] == '0')
	{
		game->player.pos.x = update.x;
		game->player.pos.y = update.y;
	}
}

void	move_left(t_game *game)
{
	t_coord	update;

	check_direction(&(game->player));
	if (game->player.dir_field == N)
		game->player.dir_field = W;
	else if (game->player.dir_field == N_E)
		game->player.dir_field = N_W;
	else
		game->player.dir_field -= 1;



	if (game->player.dir_field == N_E) //north east
		move_in_angle(&update, &(game->player), 1, north - game->player.dir);
	else if (game->player.dir_field == N_W) //north west
		move_in_angle(&update, &(game->player), 1, west - game->player.dir);
	else if (game->player.dir_field == S_W) //south east
		move_in_angle(&update, &(game->player), 0, south - game->player.dir);
	else if (game->player.dir_field == S_E) //south west
		move_in_angle(&update, &(game->player), 0, east - game->player.dir);
	else
		move_straight(&update, game, forward);
	if (game->data->map_data.map[(int)update.y]\
	[(int)(update.x)] == '0')
	{
		game->player.pos.x = update.x;
		game->player.pos.y = update.y;
	}
}

void	move_right(t_game *game)
{
	t_coord	update;

	update.y = game->player.pos.y;
	update.x = game->player.pos.x + 1;
	// game->player.dir -= angle_to_rad(5);
	// if (game->player.dir > 2 * PI)
	// 	game->player.dir -= 2 * PI;
	// game->player.delta.x = cos(game->player.dir) * 5;
	// game->player.delta.y = sin(game->player.dir) * 5;

	// update = &game->player.pos;
	// update->x += cos(game->player.dir + angle_to_rad(90))\
	// * game->player.moveSpeed;
	// update->y += sin(game->player.dir + angle_to_rad(90))\
	// * game->player.moveSpeed;
	// if (game->data->map_data.map[pixel_to_coord(update.y)]\
	// [pixel_to_coord(update.x)] == '0')

	if (game->data->map_data.map[(int)update.y]\
	[(int)(update.x)] == '0')
	{
		game->player.pos.x = update.x;
		game->player.pos.y = update.y;
	}
}
