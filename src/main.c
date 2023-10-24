/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:02:52 by ckarl             #+#    #+#             */
/*   Updated: 2023/10/24 19:37:10 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	game->data = malloc(sizeof(t_sceneData));
	if (!game->data)
	{
		printf("Error\nMalloc failed\n");
		return (0);
	}
	check_arg(argc, argv);
	init_scenedata(game->data);
	read_scene(argv[1], game->data);
	get_scene(game->data);
	check_scene(game->data);
	init_mlx_win(game);
	free_map_data(&(game->data->map_data));
	destroy_textures(game);
	free_strs_array(game->data->scene);
	free(game->data);
	free(game);
	return (0);
}

void	check_arg(int ac, char **av)
{
	if (ac < 2)
	{
		printf("Error\n");
		printf("%s\n", VIOLET"Too few arguments\n");
		exit(1);
	}
	if (ac > 2)
	{
		printf("Error\n");
		printf("%s\n", VIOLET"Too many arguments\n");
		exit(1);
	}
	if (!ft_strchr(av[1], '.'))
	{
		printf("Error\n");
		printf("%s\n", RED"Invalid File");
		exit(1);
	}
	if (ft_strncmp((ft_strrchr(av[1], '.')), ".cub", 5))
	{
		printf("Error\n");
		printf("%s\n", RED"invalid extension");
		exit(1);
	}
}
