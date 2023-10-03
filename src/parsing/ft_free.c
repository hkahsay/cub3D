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
			free(map_data->map[i]); // Free each row of the map
		}
		free(map_data->map); // Free the array of row pointers
	}
	// reset the height and width
	map_data->m_height = 0;
	map_data->m_width = 0;
}

void	free_strs_array(char **strs)
{
	int i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}
