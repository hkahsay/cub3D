#include "../../includes/cub3d.h"
#include "../../includes/parser.h"

int	lineContainsNonWhitespace(const char *line)
{
	int	k;

    k = 0;
    while(line[k] != '\0')
    {
        if (!is_space((unsigned char)line[k]))
            return (1); // Found a non-whitespace character
        k++;
    }
    return (0); // whitespace characters found
}


static void	process_non_map_line(t_sceneData *data, int i)
{
	char	*identifier;
	char	*dataLine;

	identifier = my_strtok(data->scene[i], " "); // Use delimiters " \t\v\f\rNO,SO,WE,EA,F,C"
	dataLine = my_strtok(NULL, ""); // Remaining part of the line
	get_file(identifier, dataLine, data);
data->elm++;
}

static void	process_map_line(t_sceneData *data, t_scene_params *params)
{
	if (params->mapstarted == 1)//&& params->shouldIncrementHeight == 1
	{
		if (lineContainsNonWhitespace(data->scene[params->i]) == 1)
			data->map_data.m_height++;
		else
		{
			ft_error_msg(RED"Error: The map contains an empty line."RESET);
			free_map_data(&data->map_data);
		}
	}
	else
		process_non_map_line(data, params->i);
}

//function to process scene line
static void	process_scene_line(t_scene_params *params, t_sceneData *data)
{
	if (params->mapstarted == 0)
	{
		if (is_map(data->scene[params->i]) == 1)
		{
			params->mapStartedIndex = params->i;
			params->mapstarted = 1;
		}
	}
	process_map_line(data, params);
}

void	get_scene(t_sceneData *data)
{
	t_scene_params	params;

	initialize_variables(&params);
	printf("in get scene: after initialize var\n");
	check_map_elm(data);
	while (data->scene[params.i] != NULL)
	{
		process_scene_line(&params, data);
		params.i++; // Move to the next identifier/data pair
	}
	printf("in get scene before get map\n");
	get_map(data, params.mapStartedIndex);
	printf("in get scene after get map\n");
}
