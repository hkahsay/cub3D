#include "../../includes/cub3d.h"

void	get_player(t_game *game)
{
    // generate_img(&game->img, &game->mlx, 4, 4);
	game->player.dir.x = 0;
	game->player.dir.y = 0;
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
                player->pos.x = 0.5;//for smoother movment and to avoid wall collision
                player->pos.y = 0.5;//for smoother movment and to avoid wall collision
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

void draw_mini_player(t_game *game)
{
    int playerX = (int)game->player.pos.x;
    int playerY = (int)game->player.pos.y;
    int pixelSize = 35; // Adjust the size as needed

    // Calculate the coordinates for the top-left and bottom-right corners of the square
    int startX = playerX - pixelSize / 2;
    int startY = playerY - pixelSize / 2;
    int endX = playerX + pixelSize / 2;
    int endY = playerY + pixelSize / 2;

    // Draw the filled square
    for (int x = startX; x <= endX; x++) {
        for (int y = startY; y <= endY; y++) {
            my_mlx_pixel_put(&game->img, x, y, 0x00FF00); // Draws a green pixel
            // mlx_pixel_put(game->mlx.mlx_ptr, game->mlx.win_mlx, x, y, 0x0000FF); // Draws a white pixel
        }
    }
}
void move_mini(t_game *game)
{
    if (game->keys.w)
        game->player.pos.y -= 5; // Move up
    else if (game->keys.s)
        game->player.pos.y += 5; // Move down
    else if (game->keys.a)
        game->player.pos.x -= 5; // Move left
    else if (game->keys.d)
        game->player.pos.x += 5; // Move right
    else if(game->keys.esc)
        ft_esc(game);
    mlx_clear_window(game->mlx.mlx_ptr, game->mlx.win_mlx);
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