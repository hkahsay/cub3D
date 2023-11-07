/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 20:06:42 by ckarl             #+#    #+#             */
/*   Updated: 2023/10/27 17:07:04 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

//not needed anymore since the i are not allocated anymore
void	free_map_data(t_map *map_data)
{
	int	i;

	i = -1;
	if (map_data->map)
	{
		while (++i < map_data->m_height)
		{
			free(map_data->map[i]);
		}
		free(map_data->map);
	}
	map_data->m_height = 0;
	map_data->m_width = 0;
}

void	free_strs_array(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		if (strs[i])
			free(strs[i]);
		i++;
	}
	if (strs)
		free(strs);
}
