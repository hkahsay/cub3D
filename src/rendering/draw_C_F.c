/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_C_F.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 10:52:33 by ckarl             #+#    #+#             */
/*   Updated: 2023/10/24 18:32:03 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_ceiling(t_game *game, t_rect *rect)
{
	rect->x = 0; // X-coordinate of the top-left corner of the rectangle
	rect->y = 0; // Y-coordinate of the top-left corner of the rectangle
	rect->width = MAX_WIDTH; // Width of the rectangle
	rect->height = MAX_HEIGHT / 2; // Height of the rectangle
	rect->border_width = 0; // Width of the rectangle border
	rect->fill_color = game->data->ceiling_color.rgb; // Color of the rectangle
	rect->border_color = 0X00FF00; // Color of the rectangle
	fill_rect(game, *rect);
}

void	draw_floor(t_game *game, t_rect *rect)
{
	rect->x = 0; // X-coordinate of the top-left corner of the rectangle
	rect->y = MAX_HEIGHT / 2; // Y-coordinate of the top-left corner of the rectangle
	rect->width = MAX_WIDTH; // Width of the rectangle
	rect->height = MAX_HEIGHT/ 2; // Height of the rectangle
	rect->border_width = 0; // Width of the rectangle border
	rect->fill_color = game->data->floor_color.rgb; // Color of the rectangle
	rect->border_color = 0X00FF00; // Color of the rectangle
	fill_rect(game, *rect);
}

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
			// Check if the current pixel is within the border or interior
			if (x < rect.x + rect.border_width || x >= rect.x + rect.width - rect.border_width
				|| y < rect.y + rect.border_width || y >= rect.y + rect.height - rect.border_width)
			{
				my_mlx_pixel_put(&game->img, x, y, rect.border_color);
			}
			else
			{
				my_mlx_pixel_put(&game->img, x, y, rect.fill_color);
			}
		}
	}
}

// void fill_rect_floor(t_game *game, t_rect rect)
// {
//     int x, y;
//     int color = rect.border_color;

//     for (x = rect.x; x < rect.x + rect.width; x++)
//     {
//         for (y = rect.y; y < rect.y + rect.height; y++)
//         {
//             my_mlx_pixel_put(&game->img, x, y, color);
//         }
//     }
// }

// void fill_rect(t_game *game, t_rect rect)
// {
//     int row;
//     int col;

//     row = -1;
//     while (++row < rect.height)
//     {
//         printf("1\n");
//         col = -1;
//         while (++col < rect.width)
//         {
//            printf("2\n");
//              // Check if the current pixel is within the border or interior
//             if (row < rect.x + rect.border_width || row >= rect.x + rect.width - rect.border_width
//                 || col < rect.y + rect.border_width || col >= rect.y + rect.height - rect.border_width)
//             {
//                 printf("3\n");
//                 my_mlx_pixel_put(&game->img, row, col, rect.border_color);
//                 printf("4\n");
//             }
//             else
//             {
//                 printf("5\n");
//                 my_mlx_pixel_put(&game->img, row, col, rect.fill_color);
//                 printf("6\n");
//             }
//         }
//     }
// }
