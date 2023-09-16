#include "../../cub3d.h"
void	check_scene(t_sceneData	*data)
{
    // printf("check_texture(data->north_texture.path, north %s\n", data->north_texture.path);
    check_reso(&data->resolution);
	check_texture(data->north_texture.path, "north");
	check_texture(data->south_texture.path, "south");
	check_texture(data->west_texture.path, "west");
	check_texture(data->east_texture.path, "east");
	check_color(&data->floor_color, "floor");
	check_color(&data->ceiling_color, "ceiling");
	check_map(&data->map_data);
}

// Function to check if a string contains only whitespace characters
int is_empty_line(char *str)
{
    while (*str)
    {
        if (!isspace(*str) )
            // printf("no_empty_line strr: %s\n", str);
            return (0); // Non-whitespace character found
        str++;
    }
//    printf("is_empty_line strr: \n");
    return (1); 
}

// Function to check if the map contains an empty line
int has_empty_line(char **map, int height)
{
    int i;

    i = 0;
    while (i < height) 
    {
        // printf("height: %d\n", height);
        // printf("has_empty_line: %d\n", i);
        //     printf("has_empty_line map[i]: %s\n", map[i]);
        if (is_empty_line(map[i]) != 0)
        {
            printf ("has empty line\n");
            return (1); // Found an empty line
        }
        i++;
    }
    return (0); // No empty lines found
}

void    empty_line_error(t_sceneData *data)
{
    // Set the last element to NULL to terminate the map array
    if (has_empty_line(data->map_data.map, data->map_data.m_height) != 0)
    {
        ft_error_msg(RED"Error: The map contains an empty line."RESET);
        free_map_data(&data->map_data);
    }
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
