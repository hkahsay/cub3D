/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 10:47:22 by ckarl             #+#    #+#             */
/*   Updated: 2023/10/03 11:36:23 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	generate_img(t_img *img, t_mlx *mlx, int width, int height)
{
	img->img = mlx_new_image(mlx->mlx_ptr, width, height);
	img->width = width;
	img->height = height;
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, \
	&img->line_length, &img->endian);
}

// Updated rendering function
void	init_mlx_win(t_game *game)
{
	game->mlx.mlx_ptr = mlx_init();
	game->mlx.win_mlx = mlx_new_window(game->mlx.mlx_ptr, \
	MAX_WIDTH, MAX_HEIGHT, "cub3D");
	ready_game(game);
	// mlx_hook(game->mlx.win_mlx, 2, 0, key_press, game);//key_press
	// mlx_hook(game->mlx.win_mlx, 3, 0, key_release, game);//key_release
	mlx_loop_hook(game->mlx.mlx_ptr, init_graphics, game);
	mlx_loop(game->mlx.mlx_ptr);
}

void	ready_game(t_game *game)
{
	get_player(game);
	get_event(game);
	get_rays(game);
	load_textures_img(game, &game->img);
}
