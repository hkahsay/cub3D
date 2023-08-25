#include "../cub3d.h"

int	is_color(t_parserState *state)
{
	if (state->data.floor_color.colors != NULL
		&& state->data.ceiling_color.colors != NULL)
		return(1);
	return(0);
    // return state->floor_color_set && state->ceiling_color_set;
}

void check_comma(t_parserState *state)
{
    if (current_char(state) != ',')
    {
        printf("Error: expected comma after green component.\n");
        exit(1);
    }
}

void	read_floor_ceiling(int fd, t_parserState *state)
{
    t_color *color; //= malloc(sizeof(t_color) + 1);
    (void)fd;
    char **file;
    int i;

    i = 0;
    while (file[i] && ft_isdigit(file[i]))
        i++;
    
	// skip_spaces(state);
	// while (is_color(state))
	// {
        printf("1\n");
		// skip_spaces(state);
        
        printf("current_char(state): %c\n", current_char(state));
		// if (current_char(state) == 'F' || current_char(state) == 'C') 
		// {
			skip_spaces(state);
			++state->pos;
            if (current_char(state) == 'F')
                color = &(state->data.floor_color);
            else
                color = &(state->data.ceiling_color);

            color->R = ft_atoi(read_path(state));
            printf("color->R: %d\n", color->R);
            check_comma(state);
			++state->pos;
            color->G = ft_atoi(read_path(state));
            printf("color->G: %d\n", color->G);

            check_comma(state);
            ++state->pos;
            color->B = ft_atoi(read_path(state));
            printf("color->B: %d\n", color->B);

            if (current_char(state) != '\n')
            {
                printf("Error: expected newline after color components.\n");
                exit(1);
            }
		// }
		// else if(current_char(state) == '\n')
		// {
        //     continue;
		// }
		// else
		// {
        //     printf("Error: unexpected character '%c'.\n", current_char(state));
        //     exit(1);
        // }
	    // state->curr_line = get_next_line(fd);
        // get_nx_line(fd, state);
		
	// }
	
}