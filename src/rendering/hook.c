/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 18:47:37 by ckarl             #+#    #+#             */
/*   Updated: 2023/10/24 18:26:05 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

//unset variables when key is being released
int	key_release(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		game->keys.w = 0;
	else if (keycode == KEY_A)
		game->keys.a = 0;
	else if (keycode == KEY_S)
		game->keys.s = 0;
	else if (keycode == KEY_D)
		game->keys.d = 0;
	else if (keycode == KEY_RIGHT)
		game->keys.right = 0;
	else if (keycode == KEY_LEFT)
		game->keys.left = 0;
	return (0);
}

//set variables when key is being pressed
int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		game->keys.w = 1;
	else if (keycode == KEY_A)
		game->keys.a = 1;
	else if (keycode == KEY_S)
		game->keys.s = 1;
	else if (keycode == KEY_D)
		game->keys.d = 1;
	else if (keycode == KEY_RIGHT)
		game->keys.right = 1;
	else if (keycode == KEY_LEFT)
		game->keys.left = 1;
	else if (keycode == KEY_H)
		game->data->mini_map ^= 1;
	else if (keycode == KEY_ESC || keycode == KEY_EXIT)
	{
		mlx_destroy_window(game->mlx.mlx_ptr, game->mlx.win_mlx);
		destroy_textures(game);
		exit_game(game);
	}
	return (0);
}

//redirect to right key events depending if key is pressed or not
void	key_event(t_game *game)
{
	if (game->keys.w == 1)
		move_forward(game);
	else if (game->keys.a == 1)
		move_left(game);
	else if (game->keys.s == 1)
		move_backward(game);
	else if (game->keys.d == 1)
		move_right(game);
	else if (game->keys.right == 1)
		turn_right(game);
	else if (game->keys.left == 1)
		turn_left(game);
}

//turn viewer angle to the right
void	turn_right(t_game *game)
{
	game->player.dir -= 0.01;
	if (game->player.dir < 0)
		game->player.dir += 2 * M_PI;
	check_direction(&(game->player));
	beta_angle_calc(&game->player);
}

//turn viewer angle to the left
void	turn_left(t_game *game)
{
	game->player.dir += 0.01;
	if (game->player.dir > 2 * M_PI)
		game->player.dir -= 2 * M_PI;
	check_direction(&(game->player));
	beta_angle_calc(&game->player);
}
