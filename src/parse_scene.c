#include "../cub3d.h"
#include "../parser.h"

#include <string.h>

IdentifierParser parsers[] = {
    {"NO", (void *)&parse_texture},
    {"SO", (void *)&parse_texture},
    {"WE", (void *)&parse_texture},
    {"EA", (void *)&parse_texture},
    {"F", (void *)&parse_color},
    {"C", (void *)&parse_color},

};




void get_file(char *identifier, char *str, t_sceneData *data)
{
    size_t i = 0;
    while(i < sizeof(parsers) / sizeof(parsers[0]))
    {
        if (!ft_strcmp(identifier, parsers[i].identifier))
        {
            if(!ft_strcmp(parsers[i].identifier, "NO") ) {
                parse_texture(str, &data->north_texture);
            } else if(!ft_strcmp(parsers[i].identifier, "SO") ) {
                parse_texture(str, &data->south_texture);
            } else if(!ft_strcmp(parsers[i].identifier, "WE") ) {
                parse_texture(str, &data->west_texture);
            } else if(!ft_strcmp(parsers[i].identifier, "EA") ) {
                parse_texture(str, &data->east_texture);
            } else if(!ft_strcmp(parsers[i].identifier, "F") ) {
                parse_color(str, &data->floor_color);
            } else if(!ft_strcmp(parsers[i].identifier, "C") ) {
                parse_color(str, &data->ceiling_color);
            }
            else
            {
                // Handle other cases...
                printf("Error: Unknown identifier: %s\n", identifier);
                exit(EXIT_FAILURE);
            }
            return; // Exit after finding and calling the parser
        }
        ++i;
    }
    
    printf("Error: Unknown identifier: %s\n", identifier);
    exit(EXIT_FAILURE);
}



void parse_texture(const char *str, t_texture *texture)
{

    if(!texture->path)
    {
        texture->path = ft_strdup_const(str);
        // printf("parse_texture: %p\n", texture->path);
        printf("parse_texture: %s\n", texture->path);

    }
    else
        texture->path = 0;

}



void parse_color(const char *str, t_color *color)
{
    // (void)color;
    init_color(color);
    char **strs_split;
    emprty_str((char*)str);
    printf("parse_color: %s\n", str);

    strs_split = ft_split(str, ',');
    if (strs_split == NULL)
    {
        printf("Error: could not split color components.\n");
	    free_strs_array(strs_split);
        // return;
        // exit(1);
    }
    printf("strs_split[0]%s\n", strs_split[0]);
    printf("strs_split[1] %s\n", strs_split[1]);
    
    // printf("strs_split[2] %s\n", strs_split[2]);
        printf("color->R b: %d\n", color->R);
        printf("color->B b: %d\n", color->B);
        printf("color->G b: %d\n", color->G);
    if(strs_split[0] && strs_split[1] && strs_split[2] &&
        ft_isdigit_strict(strs_split[0]) && 
        ft_isdigit_strict(strs_split[1]) && 
        ft_isdigit_strict(strs_split[2]))
    {
        // printf("2\n");
        color->R = ft_atoi(strs_split[0]);
        color->G = ft_atoi(strs_split[1]);
        color->B = ft_atoi(strs_split[2]);
        if (color_ranges_valid(&color->R, &color->G, &color->B))
        {
            printf("color->R: %d\n", color->R);
            printf("color->B: %d\n", color->B);
            printf("color->G: %d\n", color->G);
        }
        else
        {
            printf("Error: Invalid color range.\n");
            return;
        }
        // printf("3\n");
    }
    else
    {
        printf("color->R: %d\n", color->R);
        printf("color->B: %d\n", color->B);
        printf("color->G: %d\n", color->G);
        printf("Error: Invalid color format.\n\n");
        return;
    }
	free_strs_array(strs_split);
}



void get_scene(t_sceneData *data)
{
    int i = 0;
    int mapStartedIndex = 0;
    int mapstarted = 0;
    
    while (data->scene[i] != NULL)
    {
        // printf("Loop iteration: %d\n", i);
        if (mapstarted == 0)
        {
            if (is_map(data->scene[i]) == 1)
            {
                mapStartedIndex = i;
                // printf("map is started at index %d\n", mapStartedIndex);
                mapstarted = 1;
            }
        
        }
        if (mapstarted == 1)
        {
            // printf("data->scene[i], data->map_data_field %s%s\n", data->scene[i], data->map_data_field.map[i]);
            data->map_data.m_height++;
            //get_map(data, &data->map_data_field);
            // printf("data->map_data_field.map[i]: %s\n", data->map_data_field.map[i]);
        }
        else
        {
           
            // if (is_map(data->scene[i]) == 0)
            // {
                // Extract identifier and data
                if (data->scene[i][0] != '\0')
                {
                    // printf("data->scene[i][0]: %c\n", data->scene[i][0]);
                    char *identifier = strtok(data->scene[i], " "); // Assuming identifiers are followed by a space
                    char *dataLine = strtok(NULL, ""); // Remaining part of the line
                    // printf("data->scene[i], data->scene[i + 1]: %s, %s\n", data->scene[i], data->scene[i + 1]);
                    // printf("identifier: %s\n", identifier);
                    // printf("dataline: %s\n", dataLine);
                    
                    get_file(identifier, dataLine, data);
                    // printf("data->scene[i]: %s\n", data->scene[i]); 
                    // printf("Loop iteration: %d\n", i);
                    
                    // printf("identifier after get_file: %s\n", identifier);
                    data->elm++;
                }
           
            
        }
        // printf("data->scene[i]: %s\n", data->scene[i]); 
        // printf("Loop iteration: %d\n", i);
        i++; // Move to the next identifier/data pair
    }

    // data->map_data.map = malloc(sizeof(char *) * data->map_data.m_height);

    // for (int i = 0; i < data->map_data.m_height; i++)
    // {
    //     data->map_data.map[i] = data->scene[mapStartedIndex + i];
    //     // Warning: data->map_data.map[i] is a pointer to a string in data->scene
    //     // We should probably copy the string instead of just copying the pointer.
    // }

    // printf("map height: %d\n", data->map_data.m_height);
    get_map(data, mapStartedIndex);
    print_map(&data->map_data);

    // printf("data->win_mlx: %s\n", (char *) data->win_mlx);
    // printf("data->texture->path: %s\n", data->north_texture.path);

}

void    get_map(t_sceneData *data,int mapStartedIndex)
{
    int i;

    i = 0;
    data->map_data.map = malloc(sizeof(char *) * data->map_data.m_height);
    data->map_data.m_width = get_width(&data->scene[mapStartedIndex]);
    // printf("map_data->m_height: %d\n", data->map_data.m_height);
    // printf("map_data->m_width: %d\n", data->map_data.m_width);
    // printf("mapStartedIndex: %d\n", mapStartedIndex);

    while (i < data->map_data.m_height)
    {
        data->map_data.map[i] = data->scene[mapStartedIndex + i];
        // printf("data->map_data.map[i]: %s\n", data->map_data.map[i]);
        // Warning: data->map_data.map[i] is a pointer to a string in data->scene
        // We should probably copy the string instead of just copying the pointer.
        i++;
    }
    if (!is_map_enclosed(data->map_data.map, data->map_data.m_height, data->map_data.m_width))
    {
        printf("Error\nMap is not enclosed\n");
        exit(1);
    }
   
    
}
int		is_map_enclosed(char **map, int height, int width)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] != '1' && map[i][j] != ' ')
			{
				if (i == 0 || j == 0 || i == height - 1 || j == width - 1)
                {
                    printf("map[i][j]: %c\n", map[i][j]);
					return (0);
                }
				else if (map[i - 1][j - 1] == ' ' || map[i - 1][j] == ' '
					|| map[i - 1][j + 1] == ' ' || map[i][j + 1] == ' '
					|| map[i + 1][j + 1] == ' ' || map[i + 1][j] == ' '
					|| map[i + 1][j - 1] == ' ' || map[i][j - 1] == ' ')
                    {
                        printf("map[i - 1][j + 1]: %c\n", map[i - 1][j + 1]);
                    }
					return (0);
			}
		}
	}
	return (1);
}
// void get_scene(int fd, t_sceneData *data)
// {
//     int i = 0;
//     (void)fd;
//     int mapstarted = 0;
    
//     while (data->scene[i] != NULL)
//     {
//         if (mapstarted == 0)
//         {
//             if (is_map(data->scene[i]) == 1)
//             {
//                 printf("map is started\n");
//                 mapstarted = 1;
//             }
        
//         }
//         if (mapstarted == 1)
//         {
//             data->map_data_height++;
//         }
//         else
//         {
           
//             if (is_map(data->scene[i]) == 0)
//             {
//                 // Extract identifier and data
//                 if (data->scene[i][0] != '\0')
//                 {
//                     char *identifier = strtok(data->scene[i], " "); // Assuming identifiers are followed by a space
//                     char *dataLine = strtok(NULL, ""); // Remaining part of the line
                    
//                     get_file(identifier, dataLine, data);
//                     printf("data->scene[i]: %s\n", data->scene[i]); 
//                     data->elm++;
//                 }
//             }
//             else if(is_map(data->scene[i]) == 1)
//             {
//                 printf("map is started\n");
//                 mapstarted = 1;
//                 break;
//             }
            
//         }
//         i++; // Move to the next identifier/data pair
//     }
//     extract_map_lines(data);

// }