/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:53:48 by ckarl             #+#    #+#             */
/*   Updated: 2023/10/24 18:29:27 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

//destroy all loaded textures before exiting the game
void	destroy_textures(t_game *game)
{
	int	i;

	i = -1;
	while (++i < game->data->num_textures)
	{
		if (game->data->textures[i].img->img != NULL)
		{
			mlx_destroy_image(game->mlx.mlx_ptr, \
					game->data->textures[i].img->img);
			game->data->textures[i].img->img = NULL;
		}
	}
}

//free all data before exiting the game
int	exit_game(t_game *game)
{
	(void)game;
	free_map_data(&game->data->map_data);
	destroy_textures(game);
	free(game->data);
	free(game);
	exit(EXIT_SUCCESS);
}
