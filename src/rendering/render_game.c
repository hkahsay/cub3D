/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 10:41:24 by ckarl             #+#    #+#             */
/*   Updated: 2023/10/09 18:21:00 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	init_graphics(t_game *game)
{
	if (game->data->mini_map == 1)
	{
		// printf("render minimap\n");
		render_mini_map(game);
	}
	else
	{
		// printf("render game\n");
		render_game(game);
	}
	return (1);
}

void	render_game(t_game *game)
{
	generate_img(&game->img, &game->mlx, MAX_WIDTH, MAX_HEIGHT);
	get_background(game);
	draw_ray(&game->ray_data, game);
	// draw_vertical_lines(game);
	// update(game);
	// draw(game);
	mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_mlx, \
							game->img.img, 0, 0);
	mlx_destroy_image(game->mlx.mlx_ptr, game->img.img);
}

void	get_background(t_game *game)
{
	generate_img(&game->img, &game->mlx, MAX_WIDTH, MAX_HEIGHT);
	draw_ceiling(game, &game->rect);
	draw_floor(game, &game->rect);
	// draw_wall(game, game->wall_coord);
	// fill_rect_floor(game, game->data->rect);
	mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_mlx, \
							game->img.img, 0, 0);
	// mlx_destroy_image(game->mlx.mlx_ptr, game->img.img);
}

void	get_event(t_game *game)
{
	// Disable key autorepeat
	mlx_do_key_autorepeatoff(game->mlx.mlx_ptr);
	mlx_key_hook(game->mlx.win_mlx, &key_press, game);
	// mlx_hook(game->mlx.win_mlx, 3, 0, key_release, game);//key_release
	mlx_hook(game->mlx.win_mlx, 17, 0, exit_game, game);
}

// void update(t_game *game)
// {
//     update_player_pos(&game->player,game->data->map_data.map);
//     update_player_orientation(game->player);
//     update_rays(game);
// }

// void    draw_rect(t_rect *rect, int *img, int img_width)
// {
//     int i;
//     int j;
//     int color;

//     i = 0;
//     j = 0;
//     color = rect->border_color;
//     while (i < rect->width)
//     {
//         while (j < rect->height)
//         {
//             if (i < rect->border_width || i > rect->width\
//					 - rect->border_width
//                 || j < rect->border_width || j > rect->height\
//					 - rect->border_width)
//                 img[(rect->y + j) * img_width + rect->x + i] = color;
//             j++;
//         }
//         j = 0;
//         i++;
//     }
// }

// static void    draw_vertical_lines(t_game *game)
// {
//     int col;
//     (void)game;
//     col = 0;
//     while (col < MAX_WIDTH)
//     {
//         draw_vertical_line(game, col);
//         // printf("draw vertical lines\n");
//         col++;
//     }

// }
// void    draw_vertical_line(t_game *game, int col)
// {

// }