#include "../../cub3d.h"

void	get_player(t_game *game)
{
	game->player.dirX = 0;
	game->player.dirY = 0;
	game->player.moveSpeed = 0.15;
	game->player.rotSpeed = angle_to_rad(4);
	get_starting_position(&game->player, game->data->map_data.map);
}

void	get_starting_position(t_player *player, char **grid)
{
	int	i;
	int	j;

	i = -1;
	while (grid[++i])
	{
		j = -1;
		while (grid[i][++j])
        {
            if (ft_strchr("NSWE", grid[i][j]))
            {
                player->posX = 0.5;//for smoother movment and to avoid wall collision
                player->posY = 0.5;//for smoother movment and to avoid wall collision
                player->rotAngle = starting_angle(grid[i][j]);
                grid[i][j] = '0';
            }
        }
    }
}

double    starting_angle(char c)
{
    double radian = 0;
    if (c == 'N')
        radian = angle_to_rad(270); //a negative Y direction represents "up" or "North,"
    else if (c == 'S')
        radian = angle_to_rad(90); //a positive Y direction represents "down" or "South,"
    else if (c == 'W')
        radian = angle_to_rad(180); //a negative X direction represents "left" or "West,"
    else if (c == 'E')
        radian = angle_to_rad(0); //a positive X direction represents "right" or "East,"
    return (radian);
}

// void    draw_payer(t_game *game)
// {
//     t_rect	rect;
//     rect.x = game->player.posX;
//     rect.y = game->player.posY;
//     rect.width = game->data->map_data.tile_size;
//     rect.height = game->data->map_data.tile_size;
//     rect.border_color = 0x0014213d;
//     rect.border_width = 0;
//     draw_rect(&rect, game->mlx.img.data, game->scene.res.width);
// }