/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color_tex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 20:08:14 by ckarl             #+#    #+#             */
/*   Updated: 2023/11/10 11:26:22 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	get_file(char *identifier, char *str, t_sceneData *data)
{
	if (!ft_strcmp(identifier, "NO"))
		parse_texture(str, &data->north_texture, "NO");
	else if (!ft_strcmp(identifier, "SO"))
		parse_texture(str, &data->south_texture, "SO");
	else if (!ft_strcmp(identifier, "WE"))
		parse_texture(str, &data->west_texture, "WE");
	else if (!ft_strcmp(identifier, "EA"))
		parse_texture(str, &data->east_texture, "EA");
	else if (!ft_strcmp(identifier, "F"))
		parse_color(str, &data->floor_color, "F");
	else if (!ft_strcmp(identifier, "C"))
		parse_color(str, &data->ceiling_color, "C");
	else if (!ft_strcmp(identifier, "\n"))
		return ;
	else
	{
		printf(RED"Error\nUnknown identifier: '%s'\n"RESET, identifier);
		exit(EXIT_FAILURE);
	}
}

void	parse_texture(const char *str, t_texture *texture, char *identifier)
{
	char	*temp;

	if (!str)
	{
		printf("Error\n");
		printf(RED"Texture path is missing.\n"RESET);
		exit(EXIT_FAILURE);
	}
	if (!texture->path)
	{
		temp = ft_strdup_const(str);
		texture->path = ft_strtrim(temp, " ");
		free(temp);
		if (texture->path == NULL)
		{
			printf("Error\nCould not allocate memory for texture path.\n");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		printf(RED"Error\nDouble texture %s %s\n"RESET, identifier, str);
		exit(EXIT_FAILURE);
	}
}

static void	color_split(char **strs_split, t_color *color)
{
	if (tab_size(strs_split) == 3 && \
		strs_split[0] && strs_split[1] && strs_split[2] \
		&& ft_isdigit_strict(strs_split[0]) \
		&& ft_isdigit_strict(strs_split[1]) \
		&& ft_isdigit_strict(strs_split[2]))
	{
		color->r = ft_atoi(strs_split[0]);
		color->g = ft_atoi(strs_split[1]);
		color->b = ft_atoi(strs_split[2]);
		color->flag = 1;
	}
	else
	{
		printf(RED"Error\nInvalid color format.\n"RESET);
		exit(EXIT_FAILURE);
	}
}

void	parse_color(const char *str, t_color *color, char *identifier)
{
	char	**strs_split;
	char	**temp;

	empty_color((char *)str);
	if (!color->flag)
	{
		temp = ft_split_ck(str, ',');
		strs_split = trimmed_colors(temp, ' ');
		free_strs_array(temp);
		if (strs_split == NULL)
			ft_error_msg("Error: could not split color components.");
		color_split(strs_split, color);
		free_strs_array(strs_split);
	}
	else
	{
		printf(RED"Error\nDouble color set %s %s\n"RESET, identifier, str);
		exit(EXIT_FAILURE);
	}
}
