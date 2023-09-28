#include "../../includes/cub3d.h"
void	check_scene(t_sceneData	*data)
{
    // printf("check_texture(data->north_texture.path, north %s\n", data->north_texture.path);
    // check_reso(&data->resolution);
    printf("check_texture\n");
	check_texture(data->north_texture.path, "north");
	check_texture(data->south_texture.path, "south");
	check_texture(data->west_texture.path, "west");
	check_texture(data->east_texture.path, "east");
    printf("check_color\n");
	check_color(&data->floor_color, "floor");
	check_color(&data->ceiling_color, "ceiling");
    printf("check_map\n");
	check_map(&data->map_data);
}



int ft_error_msg(char *msg)
{
    printf("%s\n", msg);
    exit(EXIT_FAILURE);
}

int ft_error_msg2(char *msg, char *msg2)
{
    printf("%s%s\n", msg, msg2);
    exit(EXIT_FAILURE);
}

int    check_wall(char *line)
{
    int i;

    i = 0;
    while (line[i])
    {
        if (line[i] != '1' && !is_space(line[i]))
            return(1);
        i++;
    }
    return(0);
}
