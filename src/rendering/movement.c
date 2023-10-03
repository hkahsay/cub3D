/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 16:56:58 by ckarl             #+#    #+#             */
/*   Updated: 2023/10/03 17:37:43 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	move_forward(t_game *game)
{
	t_ray_coord	update;

	update.y = game->player.pos.y - 1;
	update.x = game->player.pos.x;

	// update.y = game->player.pos.y + game->player.delta.y;
	// update.x = game->player.pos.x + game->player.delta.x;
	// update->x += cos(game->player.rotAngle) * game->player.moveSpeed;
	// update->y += sin(game->player.rotAngle) * game->player.moveSpeed;
	// if (game->data->map_data.map[pixel_to_coord(update.y)]\
	// [pixel_to_coord(update.x)] == '0')
	// {
	if (game->data->map_data.map[(int)update.y]\
	[(int)(update.x)] == '0')
	{
		game->player.pos.x = update.x;
		game->player.pos.y = update.y;
	}
}

void	move_backward(t_game *game)
{
	t_ray_coord	update;

	update.y = game->player.pos.y + 1;
	update.x = game->player.pos.x;

	// update.y = game->player.pos.y - game->player.delta.y;
	// update.x = game->player.pos.x - game->player.delta.x;
	// update = &game->player.pos;
	// update->x -= cos(game->player.rotAngle) * game->player.moveSpeed;
	// update->y -= sin(game->player.rotAngle) * game->player.moveSpeed;
	if (game->data->map_data.map[(int)update.y]\
	[(int)(update.x)] == '0')
	{
		game->player.pos.x = update.x;
		game->player.pos.y = update.y;
	}
}

void	move_left(t_game *game)
{
	t_ray_coord	update;

	update.y = game->player.pos.y;
	update.x = game->player.pos.x - 1;
	// game->player.rotAngle -= angle_to_rad(5);
	// if (game->player.rotAngle < 0)
	// 	game->player.rotAngle += 2 * PI;
	// game->player.delta.x = cos(game->player.rotAngle) * 5;
	// game->player.delta.y = sin(game->player.rotAngle) * 5;

	// Get a pointer to the player's current position
	// update = &game->player.pos;
	//  // Calculate the new position based on moving left 90 degrees
	// update->x += cos(game->player.rotAngle + angle_to_rad(-90))\
	//  * game->player.moveSpeed;
	// update->y += sin(game->player.rotAngle + angle_to_rad(-90))\
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
	// game->player.rotAngle -= angle_to_rad(5);
	// if (game->player.rotAngle > 2 * PI)
	// 	game->player.rotAngle -= 2 * PI;
	// game->player.delta.x = cos(game->player.rotAngle) * 5;
	// game->player.delta.y = sin(game->player.rotAngle) * 5;
	t_ray_coord	update;

	update.y = game->player.pos.y;
	update.x = game->player.pos.x + 1;

	// update = &game->player.pos;
	// update->x += cos(game->player.rotAngle + angle_to_rad(90))\
	// * game->player.moveSpeed;
	// update->y += sin(game->player.rotAngle + angle_to_rad(90))\
	// * game->player.moveSpeed;
	if (game->data->map_data.map[pixel_to_coord(update.y)]\
	[pixel_to_coord(update.x)] == '0')

	if (game->data->map_data.map[(int)update.y]\
	[(int)(update.x)] == '0')
	{
		game->player.pos.x = update.x;
		game->player.pos.y = update.y;
	}
}
