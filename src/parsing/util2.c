/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 20:19:35 by ckarl             #+#    #+#             */
/*   Updated: 2023/11/10 12:20:04 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_isdigit_strict(const char *str)
{
	if (*str == '-' || *str == '+' || *str == ' ')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

void	empty_color(char *str)
{
	if (!str)
	{
		ft_error_msg(RED"Error\nColor is not set."RESET);
	}
}

void	empty_reso(char *str)
{
	if (!str)
	{
		ft_error_msg(RED"Error\nResolution is not set."RESET);
	}
}

void	convert_spaces(t_map *map_data)
{
	int	i;
	int	j;

	i = 0;
	while (i < map_data->m_height)
	{
		j = 0;
		while (map_data->map[i][j])
		{
			if (map_data->map[i][j] == ' ')
				map_data->map[i][j] = '1';
			j++;
		}
		i++;
	}
}
