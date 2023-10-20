/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 10:47:22 by ckarl             #+#    #+#             */
/*   Updated: 2023/10/20 16:18:39 by ckarl            ###   ########.fr       */
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
	// printf("after init mlx\n");
	mlx_loop_hook(game->mlx.mlx_ptr, init_graphics, game);
	// printf("after init graphics loop\n");
	ready_game(game);
	// printf("after ready game\n");
	mlx_loop(game->mlx.mlx_ptr);
}

void	ready_game(t_game *game)
{
	get_player(&game->player, &game->data->map_data);
	// printf("after get player\n");
	get_event(game);
	// printf("after get event\n");
	get_ray_data(game);
	// printf("after get ray data\n");
	load_textures_img(game);
	// printf("after load textures\n");
}

void	get_event(t_game *game)
{
	// Disable key autorepeat
	mlx_do_key_autorepeatoff(game->mlx.mlx_ptr);
	mlx_hook(game->mlx.win_mlx, 2, 0, key_press, game);
	mlx_hook(game->mlx.win_mlx, 3, 0, key_release, game);
	mlx_hook(game->mlx.win_mlx, 17, 0, exit_game, game);
}
