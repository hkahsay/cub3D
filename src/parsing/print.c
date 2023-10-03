#include "../../includes/cub3d.h"
#include <string.h>


void    print_map(t_map *map_data)
{
    int i;

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
		printf( "print_scene: %s", data->scene[i]);
		printf("\n");
		i++;
	}
	printf("print_scene: %s\n", data->scene[i]);
}
