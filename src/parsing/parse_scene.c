/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:41:32 by ckarl             #+#    #+#             */
/*   Updated: 2023/10/24 19:54:46 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	line_contains_non_whitespace(const char *line)
{
	int	k;

	k = 0;
	while (line[k] != '\0')
	{
		if (!is_space((unsigned char)line[k]))
			return (1);
		k++;
	}
	return (0);
}

static void	process_non_map_line(t_sceneData *data, int i)
{
	char				*identifier;
	char				*dataline;

	if (line_contains_non_whitespace(data->scene[i]) == 0)
		return ;
	identifier = my_strtok(data->scene[i], " ");
	dataline = my_strtok(NULL, "");
	if (!identifier)
		return ;
	get_file(identifier, dataline, data);
	data->elm++;
}

static void	process_map_line(t_sceneData *data, t_scene_params *params)
{
	if (params->mapstarted == 1)
	{
		if (line_contains_non_whitespace(data->scene[params->i]) == 1)
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
			params->map_started_index = params->i;
			params->mapstarted = 1;
		}
	}
	process_map_line(data, params);
}

void	get_scene(t_sceneData *data)
{
	t_scene_params	params;

	initialize_variables(&params);
	check_map_elm(data);
	while (data->scene[params.i] != NULL)
	{
		process_scene_line(&params, data);
		params.i++;
	}
	get_map(data, params.map_started_index);
}
