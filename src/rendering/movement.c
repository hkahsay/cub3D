/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 16:56:58 by ckarl             #+#    #+#             */
/*   Updated: 2023/10/10 18:03:07 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	check_direction(t_player *player)
{
	if (player->dir > 0 && player->dir < M_PI)
	{
		if (player->dir == M_PI / 2)
			player->dir_field = N;
		else if (player->dir > M_PI / 2 && player->dir < M_PI)
			player->dir_field = N_W;
		else
			player->dir_field = N_E;
	}
	else if (player->dir > M_PI && player->dir < 2 * M_PI)
	{
		if (player->dir == 3 * M_PI / 2)
			player->dir_field = S;
		else if (player->dir > M_PI && player->dir < 3 * M_PI / 2)
			player->dir_field = S_W;
		else
			player->dir_field = S_E;
	}
	else if (player->dir == M_PI)
		player->dir_field = W;
	else if (player->dir == 0 && player->dir == 2 * M_PI)
		player->dir_field = E;
}

void	straight_directions(t_coord *update, t_game *game)
{
	if (game->player.dir_field == N)
	{
		update->y = game->player.pos.y - 0.2;
		update->x = game->player.pos.x;
	}
	if (game->player.dir_field == E)
	{
		update->y = game->player.pos.y;
		update->x = game->player.pos.x - 0.2;
	}
	if (game->player.dir_field == S)
	{
		update->y = game->player.pos.y + 0.2;
		update->x = game->player.pos.x;
	}
	if (game->player.dir_field == E)
	{
		update->y = game->player.pos.y;
		update->x = game->player.pos.x + 0.2;
	}
}

/*
for north angle & forward motion: flag == 1
for north angle & backward motion: flag == 0
for south angle & forward motion: flag == 0
for south angle & backward motion: flag == 1

dir: already the beta angle depending on direction for sin/cos
*/
void	move_in_angle(t_coord *update, t_player *player, int flag, double dir)
{
	if ((player->dir_field == N_E || player->dir_field == S_W) && flag)
	{
		update->x = player->pos.x + sin(dir) * 0.2;
		update->y = player->pos.y - cos(dir) * 0.2;
	}
	else if ((player->dir_field == N_W || player->dir_field == S_E) && flag)
	{
		update->x = player->pos.x - cos(dir) * 0.2;
		update->y = player->pos.y - sin(dir) * 0.2;
	}
	else if ((player->dir_field == N_E || player->dir_field == S_W) && !flag)
	{
		update->x = player->pos.x - sin(dir) * 0.2;
		update->y = player->pos.y + cos(dir) * 0.2;
	}
	else if ((player->dir_field == N_W || player->dir_field == S_E) && !flag)
	{
		update->x = player->pos.x + cos(dir) * 0.2;
		update->y = player->pos.y + sin(dir) * 0.2;
	}
}

// void	south_angle(t_coord *update, t_game *game, int flag, double dir)
// {
// 	if (check_direction(game->player.dir) == S_W && flag) //south east
// 	{
// 		update->x = game->player.pos.x - sin(south - game->player.dir) * 0.2;
// 		update->y = game->player.pos.y + cos(south - game->player.dir) * 0.2;
// 	}
// 	else if (check_direction(game->player.dir) == S_E && flag) //south west
// 	{
// 		update->x = game->player.pos.x + cos(east - game->player.dir) * 0.2;
// 		update->y = game->player.pos.y + sin(east - game->player.dir) * 0.2;
// 	}
// 	else if (check_direction(game->player.dir) == S_W && !flag) //south east
// 	{
// 		update->x = game->player.pos.x + sin(south - game->player.dir) * 0.2;
// 		update->y = game->player.pos.y - cos(south - game->player.dir) * 0.2;
// 	}
// 	else if (check_direction(game->player.dir) == S_E && !flag) //south west
// 	{
// 		update->x = game->player.pos.x - cos(east - game->player.dir) * 0.2;
// 		update->y = game->player.pos.y - sin(east - game->player.dir) * 0.2;
// 	}

// }

void	move_forward(t_game *game)
{
	t_coord	update;

	check_direction(&(game->player));
	if (game->player.dir_field == N_E) //north east
		move_in_angle(&update, &(game->player), 1, north - game->player.dir);
	// {
	// 	update.x = game->player.pos.x + sin(north - game->player.dir) * 0.2;
	// 	update.y = game->player.pos.y - cos(north - game->player.dir) * 0.2;
	// }
	else if (game->player.dir_field == N_W) //north west
		move_in_angle(&update, &(game->player), 1, west - game->player.dir);
	// {
	// 	update.x = game->player.pos.x - cos(west - game->player.dir) * 0.2;
	// 	update.y = game->player.pos.y - sin(west - game->player.dir) * 0.2;
	// }
	else if (game->player.dir_field == S_W) //south east
		move_in_angle(&update, &(game->player), 0, south - game->player.dir);
	// {
	// 	update.x = game->player.pos.x - sin(south - game->player.dir) * 0.2;
	// 	update.y = game->player.pos.y + cos(south - game->player.dir) * 0.2;
	// }
	else if (game->player.dir_field == S_E) //south west
		move_in_angle(&update, &(game->player), 0, east - game->player.dir);
	// {
	// 	update.x = game->player.pos.x + cos(east - game->player.dir) * 0.2;
	// 	update.y = game->player.pos.y + sin(east - game->player.dir) * 0.2;
	// }
	else
		straight_directions(&update, game);
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

	update.y = game->player.pos.y + 1;
	update.x = game->player.pos.x;

	// update.y = game->player.pos.y - game->player.delta.y;
	// update.x = game->player.pos.x - game->player.delta.x;
	// update = &game->player.pos;
	// update->x -= cos(game->player.dir) * game->player.moveSpeed;
	// update->y -= sin(game->player.dir) * game->player.moveSpeed;
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

	update.y = game->player.pos.y;
	update.x = game->player.pos.x - 1;
	// game->player.dir -= angle_to_rad(5);
	// if (game->player.dir < 0)
	// 	game->player.dir += 2 * PI;
	// game->player.delta.x = cos(game->player.dir) * 5;
	// game->player.delta.y = sin(game->player.dir) * 5;

	// Get a pointer to the player's current position
	// update = &game->player.pos;
	//  // Calculate the new position based on moving left 90 degrees
	// update->x += cos(game->player.dir + angle_to_rad(-90))\
	//  * game->player.moveSpeed;
	// update->y += sin(game->player.dir + angle_to_rad(-90))\
	// * game->player.moveSpeed;
	// Check if the new position is valid within the map

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
