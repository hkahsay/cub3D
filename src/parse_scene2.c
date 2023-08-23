#include "../cub3d.h"
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


// void	read_scene(char *file, t_parserState *state)
// {
// 	int fd;

// 	fd = open_file(file);
//     // while ((state->curr_line = get_next_line(fd)) != NULL)//(state->curr_line = get_next_line(fd)) != NULL
//     // {
//         // state->curr_line = get_next_line(fd);
//         // get_nx_line(fd, state);
//         // printf("readscene state->curr_line: %s\n", state->curr_line);
//     //    if (ft_strncmp(state->curr_line, "NO", 2 ) == 0 || ft_strncmp(state->curr_line, "SO", 2) == 0 ||
//     //         ft_strncmp(state->curr_line, "EA", 2) == 0 || ft_strncmp(state->curr_line, "WE", 2) == 0)
//     //    {
//             // read_texture(fd, state);
//     //    }
//     //    else if (ft_strncmp(state->curr_line, "F", 1) == 0 || ft_strncmp(state->curr_line, "c", 1) == 0)
//     //    {
//             read_floor_ceiling(fd, state);
//             printf("readscene state->curr_line: %s\n", state->curr_line);

//     //    }
       
//     // }
//     // ++state->line_number;
//     printf("read_scene fd, file: %d, %s\n", fd, file);
// 	// get_nx_line(fd, state);
//     // read_floor_ceiling(state);
//     printf("getnextline %s\n", state->curr_line);

// 	close(fd);
// }

// void	read_scene(char *file, t_sceneData *data)
// {
//     char *combined_map = NULL;
//     char *current_line = NULL;
//     char *temp_map = NULL;
// 	int fd;

// 	// data = malloc(sizeof(t_sceneData) + 1);
// 	current_line = NULL;
// 	fd = open_file(file);
// 	combined_map = ft_strdup(""); //// Allocate memory for a string to store the file contents, initialize with an empty string.
// 	while (1)
// 	{
// 		current_line = get_next_line(fd);
// 		if (current_line == NULL)
// 			break; // Exit the loop if no more lines can be read from the file.
// 		temp_map = combined_map;
// 		combined_map = ft_strjoin(temp_map, current_line);// Concatenate the new line to the existing file contents.
// 		free(temp_map);
// 		free(current_line);
// 	}
// data->map = *ft_split(combined_map, '\n');
// printf("data->map %s\n", data->map);
// ++data->state->line_number;
// free(combined_map);
// free(current_line);
// close(fd);

// }

void	read_scene(char *file, t_parserState *state)
{
    char *combined_map = NULL;
    char *current_line = NULL;
    char *temp_map = NULL;
	int fd;

	// data = malloc(sizeof(t_sceneData) + 1);
	current_line = NULL;
	fd = open_file(file);
	combined_map = ft_strdup(""); //// Allocate memory for a string to store the file contents, initialize with an empty string.
	while (1)
	{
		current_line = get_next_line(fd);
		if (current_line == NULL)
			break; // Exit the loop if no more lines can be read from the file.
		temp_map = combined_map;
		combined_map = ft_strjoin(temp_map, current_line);// Concatenate the new line to the existing file contents.
		free(temp_map);
		free(current_line);
	}
state->curr_line = *ft_split(combined_map, '\n');
printf("data->map %s\n", state->curr_line);
// ++data->state->line_number;
free(combined_map);
free(current_line);
close(fd);

}

// int		is_map(char *line)
// {
// 	// int	flg;

// 	// flg = 0;
// 	while (*line)
// 	{
// 		if (!ft_strchr("01NSEW \n\t\v\f\r", *line))
//         {
//             printf("%s%s%s\n", RED, "invalid map", RESET);
//             printf("%s\n", "ismap1");
// 			return (0);

//         }
// 		// else if (*line == '1')
//         // {
//         //     // printf("%s line\n", line);
// 		// 	flg = 1;
//         // }
//         printf("%s\n", "ismap2");
// 		line++;
// 	}
// 	return (1);
// }

int is_map(char *line) {
    int flg = 0;
    // printf("%s map line0:", line);
    while (*line) {
        if (*line != '0' && *line != '1' && *line != ' ' &&
            *line != 'N' && *line != 'S' && *line != 'E' && *line != 'W' &&
            !isspace((unsigned char)(*line))) {
            printf("%s map line1.0:", line);
            printf("%s%s%s\n", RED, "Invalid map", RESET);
            flg++;
            // return 0; // Return 0 to indicate an invalid map
            exit(1);
        }
        line++;
    }
    // printf("flg: %d\n", flg);
    // printf("%s map line1:", line);
    return 1; // Return 1 to indicate a valid map
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


