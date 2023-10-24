/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color_tex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 20:08:14 by ckarl             #+#    #+#             */
/*   Updated: 2023/10/24 20:08:34 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	get_file(char *identifier, char *str, t_sceneData *data)
{
	if (!ft_strcmp(identifier, "NO"))
		parse_texture(str, &data->north_texture);
	else if (!ft_strcmp(identifier, "SO"))
		parse_texture(str, &data->south_texture);
	else if (!ft_strcmp(identifier, "WE"))
		parse_texture(str, &data->west_texture);
	else if (!ft_strcmp(identifier, "EA"))
		parse_texture(str, &data->east_texture);
	else if (!ft_strcmp(identifier, "F"))
		parse_color(str, &data->floor_color);
	else if (!ft_strcmp(identifier, "C"))
		parse_color(str, &data->ceiling_color);
	else if (!ft_strcmp(identifier, "\n"))
		return ;
	else
	{
		printf(RED"Error\nUnknown identifier: %s\n"RESET, identifier);
		exit(EXIT_FAILURE);
	}
}

void	parse_texture(const char *str, t_texture *texture)
{
	char		*temp;

	if (str == NULL)
	{
		printf("Error\n");
		printf(RED"Texture path is NULL.\n"RESET);
		exit(EXIT_FAILURE);
	}
	if (!texture->path)
	{
		temp = ft_strdup_const(str);
		texture->path = ft_strtrim(temp, " ");
		free(temp);
		if (!texture->path)
		{
			printf("Error\nCould not allocate memory for texture path.\n");
			exit(EXIT_FAILURE);
		}
	}
	else
		texture->path = 0;
}

static void	color_split(char **strs_split, t_color *color)
{
	if (strs_split[0] && strs_split[1] && strs_split[2]
		&& ft_isdigit_strict(strs_split[0])
		&& ft_isdigit_strict(strs_split[1])
		&& ft_isdigit_strict(strs_split[2]))
	{
	color->r = ft_atoi(strs_split[0]);
	color->g = ft_atoi(strs_split[1]);
	color->b = ft_atoi(strs_split[2]);
	}
	else
	{
		printf(RED"Error\n Invalid color format.\n"RESET);
		exit(EXIT_FAILURE);
	}
}

void	parse_color(const char *str, t_color *color)
{
	char	**strs_split;

	empty_color((char *)str);
	strs_split = ft_split(str, ',');
	if (strs_split == NULL)
		ft_error_msg("Error: could not split color components.");
	color_split(strs_split, color);
	free_strs_array(strs_split);
}
