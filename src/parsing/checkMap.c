/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkMap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkahsay <hkahsay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 10:59:47 by ckarl             #+#    #+#             */
/*   Updated: 2023/11/08 09:55:15 by hkahsay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_char_in_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

// Initialize valid_char to 0
// Check if the character is not one of the valid map characters
// Set valid_char to 1 if '1' is found
// Return the value of valid_char
int	is_map(char *line)
{
	int	i;
	int	valid_char;

	i = 0;
	valid_char = 0;

	while (line[i])
	{
		if (ft_char_in_set(line[i], "01NSEW \n\t\v\f\r"))
			valid_char = 1;
		else
		{
			valid_char = 0;
			break ;
		}
		i++;
	}
	return (valid_char);
}

void	check_map_elm(t_sceneData *data)
{
	int	i;
	int	found;

	i = 0;
	while (data->scene[i] != NULL)
	{
		// printf("line:'%s'\n", data->scene[i]);
		if (is_map(data->scene[i]) == 0)
		{
			data->elm++;
			// printf("data elm: %d\n", data->elm);
			found = 0;
		}
		if (is_map(data->scene[i]) == 1)
			found = 1;
		i++;
	}
	if (found == 0)
		ft_error_msg(RED"Error\nInexistent map or map not at \
the end of file"RESET);
	else if (data->elm == 0)
		ft_error_msg(RED"Error\nFile contains insufficient information"RESET);
}

void	check_map_validty(char **map, int m_height, int row, int col)
{
	if (row < 0 || row >= m_height || col < 0 || \
		col >= (int)ft_strlen(map[row]))
	{
		printf(RED"Error\nInvalid map: (%d, %d) is outside of \
the map or map is not surrounded by 1.\n"RESET, row, col);
		exit(EXIT_FAILURE);
	}
}

void	check_map_valid_characters(t_map *map_data)
{
	int	i;
	int	j;
	int	start_postion;

	i = -1;
	start_postion = 0;
	while (map_data->map[++i])
	{
		j = -1;
		while (map_data->map[i][++j])
		{
			if (!ft_strchr("01NSEW ", map_data->map[i][j]))
			{
				ft_error_msg(RED"Invalid map: Invalid character \
found in the map."RESET);
			}
			if (ft_strchr("NSEW", map_data->map[i][j]))
			{
				get_play_pos_coord(map_data, i, j, map_data->map[i][j]);
				map_data->map[i][j] = '0';
				start_postion++;
			}
		}
	}
	if (start_postion != 1)
		ft_error_msg(RED"Error\nInvalid map: Choose one starting point."RESET);
}

void	check_map(t_map *map_data)
{
	int	i;
	int	j;

	i = 0;
	while (i < map_data->m_height)
	{
		j = 0;
		while (map_data->map[i][j])
		{
			if (map_data->map[i][j] == '0' || ft_strchr("NSEW", \
				map_data->map[i][j]))
			{
				check_map_validty(map_data->map, map_data->m_height, i, j - 1);
				check_map_validty(map_data->map, map_data->m_height, i, j + 1);
				check_map_validty(map_data->map, map_data->m_height, i - 1, j);
				check_map_validty(map_data->map, map_data->m_height, i + 1, j);
			}
			j++;
		}
		i++;
	}
}

//old is_map function
// int	is_map(char *line)
// {
// 	int	i;
// 	int	valid_char;

// 	i = 0;
// 	valid_char = 0;
// 	// if (ft_check_char(line, '1') == 1)
// 	// {
// 		while(line[i])
// 		{
// 			//\n\t\v\f\r
// 			if (ft_char_in_set(line[i], "01NSEW "))
// 				valid_char = 1;
// 			else
// 			{
// 				valid_char = 0;
// 				break ;
// 			}
// 			i++;
// 			// if (line[i] == '1' || line[i] == ' ')
// 			// 	valid_char = 1;
// 			// i++;
// 		}
// 		return (valid_char);
// 	// }
// 	// return (0);
// }