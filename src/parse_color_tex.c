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
    
    // printf(RED"Error: Unknown identifier: %s\n"RESET, identifier);
    // exit(EXIT_FAILURE);
}



void parse_texture(const char *str, t_texture *texture)
{
    if (str == NULL)
    {
        printf(RED"Error: Texture path is NULL.\n"RESET);
        exit(EXIT_FAILURE);
    }
    if(!texture->path)
    {
        texture->path = ft_strdup_const(str);
        if(!texture->path)
        {
            printf("Error: Could not allocate memory for texture path.\n");
            exit(EXIT_FAILURE);
        }
            // return;
        // printf("parse_texture: %p\n", texture->path);
        printf("parse_texture: %s\n", texture->path);

    }
    else
        texture->path = 0;

}

void miss_color_set(t_sceneData *data, const char *colorType)
{
    if (data->floor_color.R == -1 || data->floor_color.G == -1 || data->floor_color.B == -1 ||
        data->ceiling_color.R == -1 || data->ceiling_color.G == -1 || data->ceiling_color.B == -1)
    {
        printf(RED"Error: %s color is not set.\n"RESET, colorType);
        exit(EXIT_FAILURE);
    }
}



void parse_color(const char *str, t_color *color)
{
    // (void)color;
    init_color(color);
    char **strs_split;
    empty_color((char*)str);
  
    printf("parse_color: %s\n", str);

    strs_split = ft_split(str, ',');
    if (strs_split == NULL)
    {
        printf("Error: could not split color components.\n");
	    free_strs_array(strs_split);
        // return;
        exit(EXIT_FAILURE);
    }
    // printf("strs_split[0]%s\n", strs_split[0]);
    // printf("strs_split[1] %s\n", strs_split[1]);
    
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
            printf(RED"Error: Invalid color range.\n"RESET);
            exit(EXIT_FAILURE);
            
        }
    }
    else
    {
        printf("color->R: %d\n", color->R);
        printf("color->B: %d\n", color->B);
        printf("color->G: %d\n", color->G);
        printf(RED"Error: Invalid color format.\n"RESET);
        exit(EXIT_FAILURE);
    }
	free_strs_array(strs_split);
}





void free_map_data(t_map *map_data)
{
    if (map_data->map)
    {
        for (int i = 0; i < map_data->m_height; i++)
        {
            free(map_data->map[i]); // Free each row of the map
        }
        free(map_data->map); // Free the array of row pointers
    }
    // reset the height and width
    map_data->m_height = 0;
    map_data->m_width = 0;
}


