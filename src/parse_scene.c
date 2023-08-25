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




void	read_scene(char *file, t_parserState *state)
{
	int fd;


	fd = open_file(file);
    // get_nx_line(fd, state);

    // printf("state->curr_line from readscene2 %s\n", state->curr_line);
    // state->curr_line = get_next_line(fd);
    while ((state->curr_line = get_next_line(fd)) != NULL)
    {
        
        printf("state->curr_line from readscene1 %s\n", state->curr_line);
        printf("state->line_number %d\n", state->line_number);
        if (!is_all_texture_path_read(state))
        {
            read_texture(state);
            ++state->line_number;

        }
        else if(current_char(state) == 'F' || current_char(state) == 'C')
        {
            ++state->line_number;
             printf("state->curr_line from readscene1 color %s\n", state->curr_line);
            printf("state->line_number color%d\n", state->line_number);
            read_floor_ceiling(fd, state);

        }
        else
        {
            printf("%s%s%s\n", RED, "Invalid scene", RESET);
            exit(1);
        }
            // return ;
        printf("readscene state->curr_line: %s\n", state->curr_line);
        // ++state->line_number;
        // printf("read_scene fd, file: %d, %s\n", fd, file);
    }
    
    // get_nx_line(fd, state);
    // printf("readscene state->curr_line: %s\n", state->curr_line);

	close(fd);
}

// 

// int is_map(char *line) {
//     int flg = 0;
//     // printf("%s map line0:", line);
//     while (*line) {
//         if (*line != '0' && *line != '1' && *line != ' ' &&
//             *line != 'N' && *line != 'S' && *line != 'E' && *line != 'W' &&
//             !isspace((unsigned char)(*line))) {
//             printf("%s map line1.0:", line);
//             printf("%s%s%s\n", RED, "Invalid map", RESET);
//             flg++;
//             // return 0; // Return 0 to indicate an invalid map
//             exit(1);
//         }
//         line++;
//     }
//     // printf("flg: %d\n", flg);
//     // printf("%s map line1:", line);
//     return 1; // Return 1 to indicate a valid map
// }


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