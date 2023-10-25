/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:02:52 by ckarl             #+#    #+#             */
/*   Updated: 2023/10/25 10:31:16 by ckarl            ###   ########.fr       */
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
	exit_game(game);
	return (0);
}

void	check_arg(int ac, char **av)
{
	if (ac < 2)
		ft_error_msg2(VIOLET"Error\n"RESET, VIOLET"Too few arguments"RESET);
	if (ac > 2)
		ft_error_msg2(VIOLET"Error\n"RESET, VIOLET"Too many arguments"RESET);
	if (!ft_strchr(av[1], '.'))
		ft_error_msg2(RED"Error\n"RESET, RED"Invalid File"RESET);
	if (ft_strncmp((ft_strrchr(av[1], '.')), ".cub", 5))
		ft_error_msg2(RED"Error\n"RESET, RED"invalid extension"RESET);
}
