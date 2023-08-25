#include "../cub3d.h"
#include <string.h>

int open_file(char *file)
{
	int	fd;
	fd = open(file, O_RDONLY);

	if(fd == -1)
	{
		printf("%s\n", RED"No file to read");
		exit(0);
	}
	return(fd);
}

void	read_scene(char *file, t_sceneData *data)
{
	int			fd;
	char		**file_data;

	file_data = NULL;
	fd = open_file(file);
	while (file = get_next_line(fd))
	{
        if(is_map(file) != 0)
        {
            file_data = ft_split(file, "\n\t\v\f\r");
            // get_file(file_data, data);
            // read_texture(data->state);
            free(file_data);
        }
	
	}
	close (fd);

}

// void get_data(char **strs, t_scene *scene) {
//     if (strs[0] == NULL || strs[0][0] == '\0') {
//         return;
//     }

//     for (size_t i = 0; i < sizeof(parsers) / sizeof(parsers[0]); i++) {
//         if (!strcmp(strs[0], parsers[i].identifier)) {
//             parsers[i].parser(strs[1], t_);
//             return;
//         }
//     }

//     printf("Error\nUnknown identifier: %s\n", strs[0]);
//     exit(EXIT_SUCCESS);
// }

// void get_file(char **str, t_sceneData *data)
// {
//     size_t i;
    
//     i = 0;
//     if (str[0] == NULL || str[0][0] == '\0')
//         return ;
//     while (i < sizeof(parsers) / sizeof(parsers[0]))
//     {
//         if(!ft_strcmp(str[0], parsers[i].identifier))
//         {
//             if (str[1] == NULL)
//             {
//                 printf("Error: Missing argument for %s\n", str[0]);
//                 exit(EXIT_FAILURE);
//             }
//              if (!ft_strcmp(parsers[i].identifier, "NO") ||
//                 !ft_strcmp(parsers[i].identifier, "SO") ||
//                 !ft_strcmp(parsers[i].identifier, "WE") ||
//                 !ft_strcmp(parsers[i].identifier, "EA")
        
//        )
//         }

//        i++;
//     }
//     printf("Error\nUnknown identifier: %s\n", str[0]);
//     exit(EXIT_SUCCESS);

// }

// if (!ft_strcmp(str[0], parsers[i].identifier)) {
//     if (str[1] == NULL) {
//         printf("Error: Missing argument for %s\n", str[0]);
//         exit(EXIT_FAILURE);
//     }
//     if (!strcmp(parsers[i].identifier, "NO") ||
//         !strcmp(parsers[i].identifier, "SO") ||
//         // ... check other identifiers that require a t_texture argument
//        ) {
//         parsers[i].parser(str[1], &data->texture_field);
//     } else if (!strcmp(parsers[i].identifier, "F") ||
//                !strcmp(parsers[i].identifier, "C")) {
//         parsers[i].parser(str[1], &data->color_field);
//     } else {
//         // Handle other cases...
//     }
// }
// 
// line receive from file;
// Check if the current character is not one of the valid characters
// Return 0 to indicate an invalid map
// Return flg = 1 to indicate a valid map at the end of the file with the help of flg
int is_map(char *line) {

    int flg = 0;
    // printf("%s map line0:", line);
    flg = 0;
    while (*line) {
        if (!ft_strchr("012NSEW \n\t\v\f\r", *line))
        {
            printf("%s map line1.0:", line);
            printf("%s%s%s\n", RED, "Invalid map", RESET);
            return 0; 
        }
        else if (*line == '1')
            flg = 1;
        line++;
    }
    // printf("flg: %d\n", flg);
    // printf("%s map line1:", line);
    return (flg); // Return 1 to indicate a valid map
}


void parse_color(char *line, t_color *color)
{
    (void)color;
    line = "hello color\n";
    printf("%s", line);

}
// void parse_texture(char *line, t_texture *texture)
// {
//     // Parse the texture path from the line and assign it to texture->path
//     texture->path = ft_strdup(line);
//     printf("%s", "hello texture\n");
//     // You can also parse tex_width and tex_height if needed
// }

void parse_map(char *line, t_map *map)
{
    // void(map);
    // Parse the map data from the line and assign it to map->map
    // You'll need to allocate memory for map->map and copy the data
    map->pos = ft_strdup(line);
    // if(map->pos == NULL)
    // {
    //     printf("%s\n", "map null");
    //     return(0);

    // }
    // else
    // {
        line = "hello map\n";
        // printf("%s %s", line, map->pos);
    //     return(1);
    // }
    // perror("Error parsing map data");

    // Parse m_width and m_height if needed
}


int is_space(char c)
{
    if (c == 32 || (c >= 9 && c <= 13) || c == '\0')
        return(1);
    return(0);
}

void    skip_spaces(t_parserState *state)
{
    while (is_space(current_char(state)))
        ++state->pos;
}


void skip_newline(t_parserState *state ) {
    //  state->curr_line = ft_strchr(str, '\n');
    while (strcmp(state->curr_line, "\n") == 0)
    {
        state->pos++;
        state->line_number++;
    }
    printf("state->curr_line %s\n", state->curr_line);
}