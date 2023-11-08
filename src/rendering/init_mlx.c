/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkahsay <hkahsay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 10:47:22 by ckarl             #+#    #+#             */
/*   Updated: 2023/11/08 09:57:50 by hkahsay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

//updated pixel put function (faster than the one from mlx)
void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

//generate a mlx image
void	generate_img(t_img *img, t_mlx *mlx, int width, int height)
{
	img->img = mlx_new_image(mlx->mlx_ptr, width, height);
	img->width = width;
	img->height = height;
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, \
	&img->line_length, &img->endian);
}

/*initialize the mlx window: loop the init_graphics (minimap or game)
and all other necessary functions through ready_game*/
void	init_mlx_win(t_game *game)
{
	game->mlx.mlx_ptr = mlx_init();
	game->mlx.win_mlx = mlx_new_window(game->mlx.mlx_ptr, \
	MAX_WIDTH, MAX_HEIGHT, "cub3D");
	mlx_loop_hook(game->mlx.mlx_ptr, init_graphics, game);
	ready_game(game);
	mlx_loop(game->mlx.mlx_ptr);
}

//get player position, event loops, ray general data and textures
void	ready_game(t_game *game)
{
	get_player(&game->player, &game->data->map_data);
	get_event(game);
	get_ray_data(game);
	load_textures_img(game);
}

//set events for movements (wasd), turns and exit
void	get_event(t_game *game)
{
	mlx_do_key_autorepeatoff(game->mlx.mlx_ptr);
	mlx_hook(game->mlx.win_mlx, 2, 0, key_press, game);
	mlx_hook(game->mlx.win_mlx, 3, 0, key_release, game);
	mlx_hook(game->mlx.win_mlx, 17, 0, exit_game, game);
}
