/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 20:09:13 by ckarl             #+#    #+#             */
/*   Updated: 2023/10/25 10:38:34 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	print_map(t_map *map_data)
{
	int	i;

	i = 0;
	while (i < map_data->m_height)
	{
		printf("map_data->map[%d]: %s\n", i, map_data->map[i]);
		i++;
	}
}

void	print_scene(t_sceneData *data)
{
	int	i;

	i = 0;
	printf("in print scene\n");
	if (!data->scene)
		return ;
	while (data->scene[i])
	{
		printf("print_scene: %s\n", data->scene[i]);
		i++;
	}
	printf("print_scene: %s\n", data->scene[i]);
}
