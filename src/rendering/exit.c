/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:53:48 by ckarl             #+#    #+#             */
/*   Updated: 2023/10/24 19:46:00 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

//destroy all loaded textures before exiting the game
void	destroy_textures(t_game *game)
{
	free(game->data->north_texture.path);
	mlx_destroy_image(game->mlx.mlx_ptr, \
					game->data->north_texture.img->img);
	free(game->data->north_texture.img);
	free(game->data->south_texture.path);
	mlx_destroy_image(game->mlx.mlx_ptr, \
					game->data->south_texture.img->img);
	free(game->data->south_texture.img);
	free(game->data->east_texture.path);
	mlx_destroy_image(game->mlx.mlx_ptr, \
					game->data->east_texture.img->img);
	free(game->data->east_texture.img);
	free(game->data->west_texture.path);
	mlx_destroy_image(game->mlx.mlx_ptr, \
					game->data->west_texture.img->img);
	free(game->data->west_texture.img);
}

//free all data before exiting the game
int	exit_game(t_game *game)
{
	free_map_data(&game->data->map_data);
	destroy_textures(game);
	free_strs_array(game->data->scene);
	free(game->data);
	free(game);
	exit(EXIT_SUCCESS);
}
