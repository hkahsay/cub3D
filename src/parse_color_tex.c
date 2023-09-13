#include "../cub3d.h"
#include "../parser.h"

#include <string.h>

    // {"S", parse_resolution},
    // {"R", parse_resolution},
IdentifierParser parsers[] = {
    {"NO", (void *)&parse_texture},
    {"SO", (void *)&parse_texture},
    {"WE", (void *)&parse_texture},
    {"EA", (void *)&parse_texture},
    {"F", (void *)&parse_color},
    {"C", (void *)&parse_color},

};
 /*if(!ft_strcmp(parsers[i].identifier, "R") )
                parse_resolution(str, &data->resolution);
            else*/
static void check_identifiers(char *identifier, char *str, t_sceneData *data, int i)
{
    if (!ft_strcmp(identifier, parsers[i].identifier))
        {
            if(!ft_strcmp(parsers[i].identifier, "NO") )
                parse_texture(str, &data->north_texture);
            else if(!ft_strcmp(parsers[i].identifier, "SO"))
                parse_texture(str, &data->south_texture);
            else if(!ft_strcmp(parsers[i].identifier, "WE"))
                parse_texture(str, &data->west_texture);
            else if(!ft_strcmp(parsers[i].identifier, "EA"))
                parse_texture(str, &data->east_texture);
            else if(!ft_strcmp(parsers[i].identifier, "F"))
                parse_color(str, &data->floor_color);
            else if(!ft_strcmp(parsers[i].identifier, "C"))
                parse_color(str, &data->ceiling_color);
            else
            {
                printf("Error\n");
                printf("Unknown identifier: %s\n", identifier);
                exit(EXIT_FAILURE);
            }
            return; // Exit after finding and calling the parser
        }
}
void get_file(char *identifier, char *str, t_sceneData *data)
{
    size_t i;

    i = -1;
    while(++i < sizeof(parsers) / sizeof(parsers[0]))
    {
        check_identifiers(identifier, str, data, i);
    
    }
}



void parse_texture(const char *str, t_texture *texture)
{
    if (str == NULL)
    {
        printf("Error\n");
        printf(RED"Texture path is NULL.\n"RESET);
        exit(EXIT_FAILURE);
    }
    if(!texture->path)
    {
        texture->path = ft_strdup_const(str);
        if(!texture->path)
        {
            printf("Error\nCould not allocate memory for texture path.\n");
            exit(EXIT_FAILURE);
        }
        printf("parse_texture: %s\n", texture->path);

    }
    else
        texture->path = 0;

}

static void    color_split(char **strs_split, t_color *color)
{
    if (strs_split[0] && strs_split[1] && strs_split[2] &&
        ft_isdigit_strict(strs_split[0]) && 
        ft_isdigit_strict(strs_split[1]) && 
        ft_isdigit_strict(strs_split[2]))
    {
        color->R = ft_atoi(strs_split[0]);
        color->G = ft_atoi(strs_split[1]);
        color->B = ft_atoi(strs_split[2]);
    }
    else
    {
        printf(RED"Error\n Invalid color format.\n"RESET);
        exit(EXIT_FAILURE);
    }
}

void parse_color(const char *str, t_color *color)
{
    char **strs_split;

    init_color(color);
    empty_color((char*)str);
  
    strs_split = ft_split(str, ',');
    if (strs_split == NULL)
    {
        ft_error_msg("Error: could not split color components.");
	    free_strs_array(strs_split);
    }
    color_split(strs_split, color);
	free_strs_array(strs_split);
}
