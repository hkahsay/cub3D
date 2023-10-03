/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 18:47:37 by ckarl             #+#    #+#             */
/*   Updated: 2023/10/03 11:59:52 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		move_forward(game);
	else if (keycode == KEY_A)
		move_left(game);
	else if (keycode == KEY_S)
		move_backward(game);
	else if (keycode == KEY_D)
		move_right(game);
	else if (keycode == KEY_RIGHT)
		game->player.rotAngle += angle_to_rad(5);
	else if (keycode == KEY_LEFT)
		game->player.rotAngle -= angle_to_rad(5);
	else if (keycode == KEY_H)
		game->data->mini_map ^= 1;
	else if (keycode == KEY_ESC || keycode == KEY_EXIT)
	{
		mlx_destroy_window(game->mlx.mlx_ptr, game->mlx.win_mlx);
		destroy_textures(game);
		exit_game(game);
		return (1);
	}
	return (0);
}

// int	key_event(t_game *game)
// {
// 	while (game->keys.w)
// 		move_forward(game);
// 	while (game->keys.a)
// 		move_left(game);
// 	while (game->keys.s)
// 		move_backward(game);
// 	while (game->keys.d)
// 		move_right(game);
// 	while (game->keys.right)
// 		game->player.rotAngle += angle_to_rad(5);
// 	while (game->keys.left)
// 		game->player.rotAngle -= angle_to_rad(5);
// 	if (game->keys.esc)
// 	{
// 		mlx_destroy_window(game->mlx.mlx_ptr, game->mlx.win_mlx);
// 		destroy_textures(game);
// 		exit_game(game);
// 		return (1) ;
// 	}
// 	return (0);
// }
