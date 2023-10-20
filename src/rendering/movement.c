/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 16:56:58 by ckarl             #+#    #+#             */
/*   Updated: 2023/10/20 14:52:07 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	move_forward(t_game *game)
{
	t_coord	update;

	if (game->player.dir_field == N_E)
		move_in_angle(&update, &(game->player), 1);
	else if (game->player.dir_field == N_W)
		move_in_angle(&update, &(game->player), 1);
	else if (game->player.dir_field == S_W)
		move_in_angle(&update, &(game->player), 0);
	else if (game->player.dir_field == S_E)
		move_in_angle(&update, &(game->player), 0);
	else
		move_straight(&update, game, FORWARD);
	if (check_map_error(update.x, update.y, game) == 0)
	{
		game->player.pos.x = update.x;
		game->player.pos.y = update.y;
	}
}

void	move_backward(t_game *game)
{
	t_coord	update;

	if (game->player.dir_field == N_E)
		move_in_angle(&update, &(game->player), 0);
	else if (game->player.dir_field == N_W)
		move_in_angle(&update, &(game->player), 0);
	else if (game->player.dir_field == S_W)
		move_in_angle(&update, &(game->player), 1);
	else if (game->player.dir_field == S_E)
		move_in_angle(&update, &(game->player), 1);
	else
		move_straight(&update, game, BACKWARD);
	if (check_map_error(update.x, update.y, game) == 0)
	{
		game->player.pos.x = update.x;
		game->player.pos.y = update.y;
	}
}

void	move_left(t_game *game)
{
	t_coord	update;

	if (game->player.dir_field == N_E)
		move_angle_left_right(&update, &(game->player), 1);
	else if (game->player.dir_field == N_W)
		move_angle_left_right(&update, &(game->player), 1);
	else if (game->player.dir_field == S_E)
		move_angle_left_right(&update, &(game->player), 0);
	else if (game->player.dir_field == S_W)
		move_angle_left_right(&update, &(game->player), 0);
	else
	{
		left_right_adjust(&(game->player), LEFT);
		move_straight(&update, game, FORWARD);
		left_right_adjust(&(game->player), RIGHT);
	}
	if (check_map_error(update.x, update.y, game) == 0)
	{
		game->player.pos.x = update.x;
		game->player.pos.y = update.y;
	}
}

void	move_right(t_game *game)
{
	t_coord	update;

	if (game->player.dir_field == N_E)
		move_angle_left_right(&update, &(game->player), 0);
	else if (game->player.dir_field == N_W)
		move_angle_left_right(&update, &(game->player), 0);
	else if (game->player.dir_field == S_E)
		move_angle_left_right(&update, &(game->player), 1);
	else if (game->player.dir_field == S_W)
		move_angle_left_right(&update, &(game->player), 1);
	else
	{
		left_right_adjust(&(game->player), RIGHT);
		move_straight(&update, game, FORWARD);
		left_right_adjust(&(game->player), LEFT);
	}
	if (check_map_error(update.x, update.y, game) == 0)
	{
		game->player.pos.x = update.x;
		game->player.pos.y = update.y;
	}
}
