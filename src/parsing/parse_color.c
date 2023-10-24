/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 20:07:57 by ckarl             #+#    #+#             */
/*   Updated: 2023/10/24 20:08:04 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	color_ranges_valid(int *r, int *g, int *b)
{
	return (*r >= 0 && *r <= 255 && *g >= 0 \
	&& *g <= 255 && *b >= 0 && *b <= 255);
}

void	check_color(t_color *color, char *color_name)
{
	if (color->r == -1)
	{
		printf("Error\nThe %s is not set or poorly \
			formatted.\n", color_name);
		exit(EXIT_SUCCESS);
	}
	else if (!color_ranges_valid(&color->r, &color->g, &color->b))
	{
		printf(RED"Error\nThe RGB code for the " YELLOW"%s"RED" is \
			out of range.\n"RESET, color_name);
		exit(EXIT_SUCCESS);
	}
	color->rgb = create_rgb(color->r, color->g, color->b);
}

int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}
