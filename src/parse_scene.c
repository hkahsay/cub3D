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

size_t  get_width(char **strlines)
{
    size_t max_width;
    size_t  length;
    int i;
    int j;


    max_width = 0;
    i = 0;
    while (strlines[i])
    {
        j = 0;
        length = 0;
        while (strlines[i][j])
        {
            if (ft_strcmp(&strlines[i][i], "\t") == 0)//strlines[i][j] == '/t'
                length += 4;
            else
                length++;
            // length = ft_strlen(strlines[i]);
            j++;
        }
        if (length > max_width)
            max_width = length;
        i++;
    }
    return (max_width);
}

void    get_map(const char *line_map, t_map *map_data, t_sceneData *data)
{
    int i;

    //Intialize map width and height
    // map_data->m_width = get_width(map_data->map);
    // map_data->m_width = ft_strlen(map_data->map);
    printf("line_map: %s\n", line_map);
    map_data->m_width = ft_strlen(line_map);

    map_data->m_height = 1;
   // data->map_field->m_width = get_width(data->scene);

   // memmory allocation for map
    map_data->map = (char **)malloc(map_data->m_height * sizeof(char *));
    i = 0;
    while (i < map_data->m_height)
    {
        map_data->map[i] = (char *)malloc((map_data->m_width + 1) * sizeof(char)); // +1 for null-terminator
        i++;
    }
    //get the rest of the map
    i = 0;
    // printf("data->scene[i]1: %s\n", data->scene[i]);
    while (data->scene[i] != NULL)
    {
        map_data->m_height++;
        //resize map array
        map_data->map = (char **)realloc(map_data->map, map_data->m_height * sizeof(char *));
         // Allocate memory and store the map line
        map_data->map[map_data->m_height - 1] = strdup(data->scene[i]);
        // printf("data->scene[i]: %s\n", data->scene[i]);

        i++;
    }
    // store player position and orientation (N/S/E/W) using map_data->pos
    

}

void get_file(char *identifier, char *str, t_sceneData *data)
{
    size_t i = 0;
    while(i < sizeof(parsers) / sizeof(parsers[0]))
    {
        if (!ft_strcmp(identifier, parsers[i].identifier))
        {
            if (!ft_strcmp(parsers[i].identifier, "NO") ||
                !ft_strcmp(parsers[i].identifier, "SO") ||
                !ft_strcmp(parsers[i].identifier, "WE") ||
                !ft_strcmp(parsers[i].identifier, "EA"))
            {
                // printf("Checking identifier: %s\n", identifier);
                parsers[i].parser(str, data);
            }
            else if (!ft_strcmp(parsers[i].identifier, "F") ||
            !ft_strcmp(parsers[i].identifier, "C"))
            {
                // printf("Check color\n");
                parsers[i].parser(str, data);
                // printf("Check color2\n");

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

void color_ranges(int *r, int *g, int *b)
{
    if (*r < 0 | *r > 255 || *g < 0 || *g > 255 || *b < 0 || *b > 255)
    {
        printf("Error: Invalid color range.\n");
        // exit(EXIT_FAILURE);
    }
}


void parse_color(const char *str, t_color *color)
{
    // (void)color;
    color = init_color(color);
    char **strs_split;
    printf("parse_color: %s\n", str);
  
   
    strs_split = ft_split(str, ',');
    if (strs_split == NULL)
    {
        printf("Error: could not split color components.\n");
        return;
    }
    if(strs_split[0] && ft_isdigit(*strs_split[0]) && 
        strs_split[1] && ft_isdigit(*strs_split[1]) && 
        strs_split[2] && ft_isdigit(*strs_split[2]))
        {
            // printf("2\n");
            color->R = ft_atoi(strs_split[0]);
            color->G = ft_atoi(strs_split[1]);
            color->B = ft_atoi(strs_split[2]);
            color_ranges(&color->R, &color->G, &color->B);
            // printf("3\n");
            printf("color->R: %d\n", color->R);
            printf("color->B: %d\n", color->B);
            printf("color->G: %d\n", color->G);
        }
    else
    {
        printf("Error: Invalid color format.\n\n");
        return;
    }
	free(strs_split);
}


// 
// line receive from file;
// Check if the current character is not one of the valid characters
// Return 0 to indicate an invalid map
// Return flg = 1 to indicate a valid map at the end of the file with the help of flg



void check_map(t_sceneData *data)
{
    int i = 0;
    int mapstarted = 0;
    
    while (data->scene[i] != NULL)
    {
        if (mapstarted == 0)
        {
            if (is_map(data->scene[i]) == 1)
            {
                printf("map is started\n");
                mapstarted = 1;
            }
        
        }
        if (mapstarted == 1)
        {
            // printf("data->scene[i], data->map_field %s%s\n", data->scene[i], data->map_field.map[i]);
            get_map(data->scene[i], &data->map_field, data);
            // printf("data->map_field.map[i]: %s\n", data->map_field.map[i]);
        }
        else
        {
           
            if (is_map(data->scene[i]) == 0)
            {
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
                    
                    // printf("identifier after get_file: %s\n", identifier);
                    data->elm++;
                }
            }
            else if(is_map(data->scene[i]) == 1)
            {
                printf("map is started\n");
                mapstarted = 1;
                break;
            }
            
        }
        // printf("Loop iteration: %d\n", i);
        i++; // Move to the next identifier/data pair
    }
}

