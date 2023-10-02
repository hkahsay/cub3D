#include "../../includes/cub3d.h"
#include "../../includes/parser.h"

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
				length += 4; // Tab character adds 4 to the length
			else
				length++;
		}
		if (length > max_width)
			max_width = length;
	}
	return (max_width);
}

static void	map_allocate_memory(t_sceneData *data, int mapStartedIndex)
{
		// Allocate memory for the entire map_data.map array
	data->map_data.map = malloc(sizeof(char *) * (data->map_data.m_height + 1)); // +1 for the NULL terminator
	if (!data->map_data.map)
	{
		ft_error_msg(RED"Error: Dynamic allocation failed."RESET);
		// free_map_data(&data->map_data);
	}
	data->map_data.m_width = get_width(&data->scene[mapStartedIndex]);
}

void	get_map(t_sceneData *data, int mapStartedIndex)
{
	int	i;

	i = 0;
	map_allocate_memory(data, mapStartedIndex);
	while (i < data->map_data.m_height)
	{
		// data->map_data.map[i] = malloc(sizeof(char) * (data->map_data.m_width + 1));
		// if (!data->map_data.map[i])
		// {
		// 	ft_error_msg(RED"Error: Dynamic allocation failed."RESET);
		// 	free_map_data(&data->map_data);
		// }
		// strcpy(data->map_data.map[i], data->scene[mapStartedIndex + i]);
		data->map_data.map[i] = data->scene[mapStartedIndex + i];
		i++;
	}
	data->map_data.map[data->map_data.m_height] = NULL;
	check_map_valid_characters(data->map_data.map);
}

//------------str_cpy need to implement
