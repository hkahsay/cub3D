/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 20:08:39 by ckarl             #+#    #+#             */
/*   Updated: 2023/10/24 20:08:45 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
// #include "../includes/parser.h"

void	check_texture(char *texture, char *tex_name)
{
	int	fd;

	fd = open(texture, O_RDONLY);
	if (texture == NULL)
	{
		printf (RED"Error\n%s texture path is empty\n"RESET, tex_name);
		exit(EXIT_FAILURE);
	}
	else if (valid_extension(texture) == 0)
	{
		printf (RED"Error\nFile %s: %s doesn't have correct extension\n"RESET,
			tex_name, texture);
		exit(EXIT_FAILURE);
	}
	if (fd == -1)
	{
		printf(RED"Error\ncannot open %s: %s\n"RESET, tex_name, texture);
		exit(EXIT_FAILURE);
	}
	if (close(fd) == -1)
	{
		printf(RED"Error\n%s Could not close texture file\n"RESET, texture);
		exit(EXIT_FAILURE);
	}
}

int	valid_extension(char *tex_path)
{
	int	len;

	if (!tex_path)
		return (0);
	len = ft_strlen(tex_path);
	if (len < 4)
		return (0);
	if (tex_path[len - 1] != 'm'
		|| tex_path[len - 2] != 'p'
		|| tex_path[len - 3] != 'x'
		|| tex_path[len - 4] != '.')
	{
		printf("Error\n%s doesn't have correct extension\n", tex_path);
		return (0);
	}
	return (1);
}
