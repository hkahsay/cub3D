#include "../cub3d.h"
#include "../parser.h"

#include <string.h>

IdentifierParser parsers[] = {
    {"R", (void *)&parse_resolution},
    {"NO", (void *)&parse_texture},
    {"SO", (void *)&parse_texture},
    {"WE", (void *)&parse_texture},
    {"EA", (void *)&parse_texture},
    {"F", (void *)&parse_color},
    {"C", (void *)&parse_color},
};



void get_file(char *identifier, char *str, t_sceneData *data)
{
    for (size_t i = 0; i < sizeof(parsers) / sizeof(parsers[0]); ++i)
    {
        if (!strcmp(identifier, parsers[i].identifier))
        {
            if (!strcmp(parsers[i].identifier, "NO") ||
                !strcmp(parsers[i].identifier, "SO") ||
                !strcmp(parsers[i].identifier, "WE") ||
                !strcmp(parsers[i].identifier, "EA"))
            {
                printf("Checking identifier: %s\n", identifier);
                parsers[i].parser(str, data);
            }
            else if (!strcmp(parsers[i].identifier, "F") ||
                     !strcmp(parsers[i].identifier, "C"))
            {
                parsers[i].parser(str, data);
            }
            else
            {
                // Handle other cases...
                printf("Error: Unknown identifier: %s\n", identifier);
                exit(EXIT_FAILURE);
            }
            return; // Exit after finding and calling the parser
        }
    }
    
    printf("Error: Unknown identifier: %s\n", identifier);
    exit(EXIT_FAILURE);
}



void parse_texture(const char *str, t_texture *data)
{

    if(!data->path)
    {
        data->path = ft_strdup_const(str);
        // printf("parse_texture: %p\n", data->path);
        printf("parse_texture: %s\n", data->path);



    }
    else
        data->path = 0;

}

void parse_resolution(const char *str, t_resolution *data)
{
    (void)data;
    printf("parse_resolution: %s\n", str);
}

void parse_color(const char *str, t_color *data)
{
    (void)data;

    printf("parse_color: %s\n", str);
}

// 
// line receive from file;
// Check if the current character is not one of the valid characters
// Return 0 to indicate an invalid map
// Return flg = 1 to indicate a valid map at the end of the file with the help of flg


// void	parse_resolution(const char **strs, t_resolution *res)
// {
// 	if (!ft_isdigit2(strs[1]) || !ft_isdigit2(strs[2]))
// 		return ;
// 	if (strs[3] != 0)
// 		return ;
// 	res->width = ft_atoi(strs[1]);
// 	res->height = ft_atoi(strs[2]);
// }



void check_map(t_sceneData *data)
{
    int i = 0;
    
    while (data->scene[i] != NULL)
    {
        if (is_map(data->scene[i]) == 0)
        {
            // Extract identifier and data
            if (data->scene[i][0] != '\0')
            {
                printf("data->scene[i][0]: %c\n", data->scene[i][0]);
                char *identifier = strtok(data->scene[i], " "); // Assuming identifiers are followed by a space
                char *dataLine = strtok(NULL, ""); // Remaining part of the line
                // printf("data->scene[i], data->scene[i + 1]: %s, %s\n", data->scene[i], data->scene[i + 1]);
                printf("identifier: %s\n", identifier);
                printf("dataline: %s\n", dataLine);
                
                get_file(identifier, dataLine, data);
                // printf("identifier after get_file: %s\n", identifier);

                data->elm++;
            }
        }
        printf("Loop iteration: %d\n", i);
        i ++; // Move to the next identifier/data pair
    }
}

