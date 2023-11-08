/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkahsay <hkahsay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:16:34 by ckarl             #+#    #+#             */
/*   Updated: 2023/11/08 09:55:10 by hkahsay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	check_scene(t_sceneData	*data)
{
	check_texture(data->north_texture.path, "north");
	check_texture(data->south_texture.path, "south");
	check_texture(data->west_texture.path, "west");
	check_texture(data->east_texture.path, "east");
	check_color(&data->floor_color, "floor");
	check_color(&data->ceiling_color, "ceiling");
	check_map(&data->map_data);
}

int	ft_error_msg(char *msg)
{
	printf("%s\n", msg);
	exit(EXIT_FAILURE);
}

int	ft_error_msg2(char *msg, char *msg2)
{
	printf("%s%s\n", msg, msg2);
	exit(EXIT_FAILURE);
}

int	check_wall(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1' && !is_space(line[i]))
			return (1);
		i++;
	}
	return (0);
}

void	get_play_pos_coord(t_map *map_data, int row, int col, char dir)
{
	map_data->play_pos.row = row;
	map_data->play_pos.col = col;
	if (dir == 'N')
		map_data->play_pos.dir = 90;
	else if (dir == 'E')
		map_data->play_pos.dir = 0;
	else if (dir == 'S')
		map_data->play_pos.dir = 270;
	else if (dir == 'W')
		map_data->play_pos.dir = 180;
}
