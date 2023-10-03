/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:53:48 by ckarl             #+#    #+#             */
/*   Updated: 2023/10/03 11:55:29 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// Function to destroy all loaded textures
void	destroy_textures(t_game *game)
{
	int	i;

	i = -1;
	while (++i < game->data->num_textures)
	{
		if (game->data->textures[i].img.img != NULL)
		{
			mlx_destroy_image(game->mlx.mlx_ptr, \
					game->data->textures[i].img.img);
			game->data->textures[i].img.img = NULL;
		}
	}
}

int	exit_game(t_game *game)
{
	free_map_data(&game->data->map_data);
	free(game->data);
	free(game);
	exit(EXIT_SUCCESS);
}

// In your ft_esc function, call destroy_textures to
//release textures before exiting
// int ft_esc(t_game *game)
// {
//     if (game->keys.esc == 1)
//     {
//         mlx_destroy_window(game->mlx.mlx_ptr, game->mlx.win_mlx);
//         destroy_textures(game);
//         exit(0);
//     }
//     return (0);
// }
