/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getMap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkahsay <hkahsay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 10:40:14 by ckarl             #+#    #+#             */
/*   Updated: 2023/11/08 09:55:49 by hkahsay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// Tab character adds 4 to the length
size_t	get_width(char **maplines)
{
	size_t	max_width;
	size_t	length;
	int		i;
	int		j;

	max_width = 0;
	i = -1;
	while (maplines[++i])
	{
		length = 0;
		j = -1;
		while (maplines[i][++j])
		{
			if (maplines[i][j] == '\t')
				length += 4;
			else
				length++;
		}
		if (length > max_width)
			max_width = length;
	}
	return (max_width);
}

// Allocate memory for the entire map_data.map array
static void	map_allocate_memory(t_sceneData *data, int map_started_index)
{
	data->map_data.map = malloc(sizeof(char *) * (data->map_data.m_height + 1));
	if (!data->map_data.map)
	{
		ft_error_msg(RED"Error: Dynamic allocation failed."RESET);
		free_map_data(&data->map_data);
	}
	data->map_data.m_width = get_width(&data->scene[map_started_index]);
}

void	get_map(t_sceneData *data, int map_started_index)
{
	int	i;

	i = 0;
	map_allocate_memory(data, map_started_index);
	while (i < data->map_data.m_height)
	{
		data->map_data.map[i] = malloc(sizeof(char) * (data->map_data.m_width \
								+ 1));
		if (!data->map_data.map[i])
		{
			ft_error_msg(RED"Error: Dynamic allocation failed."RESET);
			free_map_data(&data->map_data);
		}
		ft_strlcpy(data->map_data.map[i], data->scene[map_started_index + i], \
		data->map_data.m_width + 1);
		i++;
	}
	data->map_data.map[data->map_data.m_height] = NULL;
	check_map_valid_characters(&data->map_data);
}
