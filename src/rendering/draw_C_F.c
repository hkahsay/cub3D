/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_C_F.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 10:52:33 by ckarl             #+#    #+#             */
/*   Updated: 2023/10/24 20:28:39 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_ceiling(t_game *game, t_rect *rect)
{
	rect->x = 0;
	rect->y = 0;
	rect->width = MAX_WIDTH;
	rect->height = MAX_HEIGHT / 2;
	rect->border_width = 0;
	rect->fill_color = game->data->ceiling_color.rgb;
	rect->border_color = 0X00FF00;
	fill_rect(game, *rect);
}

void	draw_floor(t_game *game, t_rect *rect)
{
	rect->x = 0;
	rect->y = MAX_HEIGHT / 2;
	rect->width = MAX_WIDTH;
	rect->height = MAX_HEIGHT / 2;
	rect->border_width = 0;
	rect->fill_color = game->data->floor_color.rgb;
	rect->border_color = 0X00FF00;
	fill_rect(game, *rect);
}

// Check if the current pixel is within the border or interior
void	fill_rect(t_game *game, t_rect rect)
{
	int	x;
	int	y;

	y = rect.y - 1;
	while (++y < rect.y + rect.height)
	{
		x = rect.x - 1;
		while (++x < rect.x + rect.width)
		{
			if (x < rect.x + rect.border_width \
			|| x >= rect.x + rect.width - rect.border_width
				|| y < rect.y + rect.border_width \
				|| y >= rect.y + rect.height - rect.border_width)
				my_mlx_pixel_put(&game->img, x, y, rect.border_color);
			else
				my_mlx_pixel_put(&game->img, x, y, rect.fill_color);
		}
	}
}
