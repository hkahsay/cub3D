/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkahsay <hkahsay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 10:41:24 by ckarl             #+#    #+#             */
/*   Updated: 2023/11/08 09:58:00 by hkahsay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	init_graphics(t_game *game)
{
	if (game->data->mini_map == 1)
		render_mini_map(game);
	else
		render_game(game);
	return (1);
}

void	render_game(t_game *game)
{
	generate_img(&game->img, &game->mlx, MAX_WIDTH, MAX_HEIGHT);
	get_background(game);
	key_event(game);
	draw_all_rays(game);
	mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_mlx, \
							game->img.img, 0, 0);
	mlx_destroy_image(game->mlx.mlx_ptr, game->img.img);
}

void	get_background(t_game *game)
{
	generate_img(&game->img, &game->mlx, MAX_WIDTH, MAX_HEIGHT);
	draw_ceiling(game, &game->rect);
	draw_floor(game, &game->rect);
}
