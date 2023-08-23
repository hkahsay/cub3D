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
    t_color *color = malloc(sizeof(t_color) + 1);

    // get_nx_line(fd, state);
	state->curr_line = get_next_line(fd);
	while (!is_color(state))
	{
        printf("1\n");
		skip_spaces(state);
		if (current_char(state) == 'F' || current_char(state) == 'C') 
		{
			// skip_spaces(state);
            printf("2\n");
			++state->pos;
            if (current_char(state) == 'F')
                color = &(state->data.floor_color);
            else
                color = &(state->data.ceiling_color);

            color->R = ft_atoi(read_path(state));
            check_comma(state);
			++state->pos;
            color->G = ft_atoi(read_path(state));
            check_comma(state);
            ++state->pos;
            color->B = ft_atoi(read_path(state));
            if (current_char(state) != '\n')
            {
                printf("Error: expected newline after color components.\n");
                exit(1);
            }
		}
		else if(current_char(state) == '\n')
		{
            continue;
		}
		else
		{
            printf("Error: unexpected character '%c'.\n", current_char(state));
            exit(1);
        }
	    state->curr_line = get_next_line(fd);
		
	}
	
}