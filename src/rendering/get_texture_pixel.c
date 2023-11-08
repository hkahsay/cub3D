/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_pixel.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkahsay <hkahsay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:34:18 by ckarl             #+#    #+#             */
/*   Updated: 2023/11/08 09:57:43 by hkahsay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

//initialize texture image
void	load_texture_img(void *mlx, t_texture *texture)
{
	texture->img = malloc(sizeof(t_img));
	if (!texture->img)
		ft_error_msg(RED"Malloc Error\n"RESET);
	texture->img->img = mlx_xpm_file_to_image(mlx, texture->path, \
		&texture->img->width, &texture->img->height);
	if (!texture->img->img)
	{
		printf(RED"Error\nTexture not found: %s\n"RESET, texture->path);
		exit(EXIT_FAILURE);
	}
	else
		texture->img->addr = mlx_get_data_addr(texture->img->img, \
		&texture->img->bits_per_pixel, \
		&texture->img->line_length, &texture->img->endian);
	if (texture->img->height != texture->img->width)
	{
		printf(RED"Error\nTexture not square: %s\n"RESET, texture->path);
		exit(EXIT_FAILURE);
	}
}

//load all textures
void	load_textures_img(t_game *game)
{
	load_texture_img(game->mlx.mlx_ptr, &game->data->north_texture);
	load_texture_img(game->mlx.mlx_ptr, &game->data->south_texture);
	load_texture_img(game->mlx.mlx_ptr, &game->data->west_texture);
	load_texture_img(game->mlx.mlx_ptr, &game->data->east_texture);
}
