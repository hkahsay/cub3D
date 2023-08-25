#include "../cub3d.h"

// char	current_char(t_parserState *state)
// {
// 	char c;
	
// 	c = state->curr_line[state->pos];
// 	return (c);
// }
int		is_map(char *line)
{
	int	check;

	check = 0;
	while (*line)
	{
		if (!ft_strchr("01NSEW \n\t\v\f\r", *line))
			return (0);
		else if (*line == '1')
			check = 1;
		line++;
	}
	return (check);
}
char current_char(t_parserState *state)
{
    char c;

    // Check if state or curr_line is NULL before accessing
    if (state == NULL || state->curr_line == NULL) {
		printf("Error: state is NULL");
        return (0); // Default character if there's an error
    }

    // Check if pos is within valid range
    if (state->pos >= 0 && state->pos < ft_strlen(state->curr_line)) {
        c = state->curr_line[state->pos];
    } else {
        // Handle the error or return a default value
        return (0); // Default character if pos is out of range
    }
    
    return c;
}

void	next_char(t_parserState	*state)
{
	++state->pos;
}



void	get_nx_line(int fd, t_parserState *state)
{
	
	state->curr_line = get_next_line(fd);
	if (state->curr_line == NULL) {
        printf("Error: Failed to read the next line.\n");
        exit(1); // Or handle the error in a way appropriate for your program
    }
	state->pos = 0;
	++state->line_number;
	printf("from get_nx_line state_curr:%s\n", state->curr_line);

}