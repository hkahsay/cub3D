#include "../cub3d.h"
// #include "../parser.h"

int is_all_texture_path_read(t_parserState	*state)
{
	if(state->data.north_texture.path != NULL
		&& state->data.south_texture.path != NULL
		&& state->data.east_texture.path != NULL
		&& state->data.west_texture.path != NULL)
		return(1);
	return(0);
}


// Function to handle errors and exit
// void handle_error_exit(t_parserState *state, char expected, char got)
// {
//     (void)state;
// 	printf("currchar 1%c\n", current_char(state));
//     printf("Error: expected character '%c' but got '%c'.\n", expected, got);
//     exit(1);
// }

// Function to read a single texture
// void read_single_texture(t_parserState *state, t_texture *texture, char expectedChar)
// {
//     ++state->pos;
//     if (current_char(state) == expectedChar)
//     {
//         ++state->pos;
//         texture->path = read_path(state);
// 		printf("currchar 00%c\n", current_char(state));

//     }
//     else
//     {
// 		printf("currchar %c\n", current_char(state));
//         handle_error_exit(state, expectedChar, current_char(state));
//     }
// }

// char	*read_path(t_parserState *state)
// {
// 	int	start_pos;
// 	int	end_pos;
// 	char	*res;
// 	int	size;
// 	skip_spaces(state);

// 	start_pos = state->pos;
// 	while (!(is_space(current_char(state))) && current_char(state) != '\n')
// 		++state->pos;
// 	end_pos = state->pos;
// 	size = end_pos - start_pos;
// 	printf("size read path: %d\n", size);
// 	printf("end pos read path: %d\n", end_pos);
// 	printf("start read path: %d\n", start_pos);

// 	res = (char *)malloc(size + 1);
// 	ft_bzero(res, size + 1);
// 	ft_strncpy(res, state->curr_line + start_pos, size);
// 	return (res);
// }

// void	read_texture(t_parserState *state)//int fd, 
// {
	
// 	while (!is_all_texture_path_read(state))
// 	{
// 		// get_nx_line(fd, state);
// 		printf("read_texture: %s\n", state->curr_line);
// 		skip_spaces(state);
// 			skip_spaces(state);
// 		// printf("state->curr")
// 		if (current_char(state) == 'N')
// 		{
// 			read_single_texture(state, &state->data.north_texture, 'O');

// 		}
// 		else if (current_char(state) == 'S')
// 		{
// 			printf("dddd\n");
			
// 			read_single_texture(state, &state->data.south_texture, 'O');
// 			printf("read_texture2: %s\n", state->curr_line);

// 			printf("tttd\n");
// 		}
// 		else if(current_char(state) == 'W')
// 		{
// 			printf("read_texture3: %s\n", state->curr_line);
// 			read_single_texture(state, &state->data.west_texture, 'E');
// 			printf("cccccd\n");
// 		}
// 		else if(current_char(state) == 'E')
// 		{
// 			read_single_texture(state, &state->data.east_texture, 'A');

// 		}
// 		else if(current_char(state) == '\n')
// 		{
//             continue;
// 		}
// 		// else
// 		// {
//         //     printf("Error: unexpected character '%c'.\n", current_char(state));
//         //     exit(1);
//         // }
// 		else if (is_all_texture_path_read(state))
//         {
//             break; // Exit the loop
//         }

// 	}
// 	printf("read_texture pos: %d\n", state->pos);

// // }

// void parse_texture(const char *str, t_sceneData *sceneData)
// {
//     // t_texture *texture = (t_texture*)data;

//     if(!sceneData->texture_field->path)
//         sceneData->texture_field->path = ft_strdup_const(str);
//     else
//         sceneData->texture_field->path = 0;

// }

// void parse_resolution(const char *str, t_sceneData *data)
// {
//     (void)data;
//     printf("parse_resolution: %s\n", str);
// }

// void parse_color(const char *str, t_sceneData *data)
// {
//     (void)data;

//     printf("parse_color: %s\n", str);
// }

// void read_texture(t_parserState* state) {

// 	// state->curr_line = get_next_line(fd);
//     // state->line_number++;

// 	// (void)fd;
// 	// get_nx_line(fd, state);
//     while(is_all_texture_path_read(state)) {
// 		state->pos = 0;
//         // next_line(state);
//         printf("read_texture (current: line: %d, current pos: %zu)\n", state->line_number, state->pos);
//         skip_spaces(state);
//         if(current_char(state) == 'N') {
//             next_char(state);
//             if(current_char(state) == 'O') {
//                 next_char(state);
//                 state->data.north_texture.path = read_path(state);
// 				printf("Path: %s\n", state->data.north_texture.path);
//             } else {
//                 printf("Error: expected character 'O' but got '%c'.\n", current_char(state));
//                 exit(1);
//             }
//         } else if(current_char(state) == 'S') {
//             next_char(state);
//             if(current_char(state) == 'O') {
//                 next_char(state);
//                 state->data.south_texture.path = read_path(state);
// 				printf("Path: %s\n", state->data.south_texture.path);

//             } else {
//                 printf("Error: expected character 'O' but got '%c'.\n", current_char(state));
//                 exit(1);
//             }
//         } else if(current_char(state) == 'W') {
//             next_char(state);
//             if(current_char(state) == 'E') {
//                 next_char(state);
//                 state->data.west_texture.path = read_path(state);
// 				printf("Path: %s\n", state->data.west_texture.path);

//             } else {
//                 printf("Error: expected character 'E' but got '%c'.\n", current_char(state));
//                 exit(1);
//             }
//         } else if(current_char(state) == 'E') {
//             next_char(state);
//             if(current_char(state) == 'A') {
//                 next_char(state);
//                 state->data.east_texture.path = read_path(state);
// 				printf("Path: %s\n", state->data.east_texture.path);
//             } else {
//                 printf("Error: expected character 'A' but got '%c'.\n", current_char(state));
//                 exit(1);
//             }
//         } 
//         else if(current_char(state) == '\n') {
//             continue;
//         } 
//         else {
//             printf("Error: unexpected character '%c'.\n", current_char(state));
//             exit(1);
//         }
// 		++state->line_number;
// 		printf(" from texture state->line_number %d\n", state->line_number);
// 		printf(" from texture state->curr_line %s %d\n", state->curr_line, state->line_number);

// 	// 	state->curr_line = get_next_line(fd);
//     //     // get_nx_line(fd, state);
//     }
// }