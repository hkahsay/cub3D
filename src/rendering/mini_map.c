#include "../../cub3d.h"

int	render_mini_map(t_game *game)
{
    game->img.img = mlx_new_image(game->mlx.mlx_ptr, game->data->resolution.width, game->data->resolution.height);
    game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bits_per_pixel, &game->img.line_length, &game->img.endian);
    render_wall2d(game);
	// movement(game);
	draw_player(game);
	// draw_arrow(game, game->scene->player.pos, game->scene->player.dir);
    mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_mlx, game->img.img, 0, 0);
    mlx_destroy_image(game->mlx.mlx_ptr, game->img.img);
	return (0);
}

void	draw_wall(t_game *game, t_wall_coordinate wall_coord)
{
	int		x;
	int		y;
	
	y = 0;
	while (y < SCALE_MINI_MAP)
	{
		x = 0;
		while (x < SCALE_MINI_MAP)
		{
            my_mlx_pixel_put(&game->img, wall_coord.x * SCALE_MINI_MAP + x, wall_coord.y * SCALE_MINI_MAP + y, 0x00FFFFFF);
			x++;
		}
		y++;
	}
}

void	render_wall2d(t_game *game)
{
	int		i;
	int		j;
    t_wall_coordinate	coord_wall;

	j = 0;
	while (j < game->data->map_data.m_height)
	{
		i = 0;
		while (i < game->data->map_data.m_width)
		{
			if (game->data->map_data.map[j][i] == '1')
			{
				coord_wall.x = i;
				coord_wall.y = j;
				draw_wall(game, coord_wall);
			}
			i++;
		}
		j++;
	}
}