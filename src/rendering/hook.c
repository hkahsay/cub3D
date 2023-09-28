#include "../../includes/cub3d.h"

int    key_release(int keycode, t_game *game)
{
    if (keycode == KEY_W)
		game->keys.w = 0;
	else if (keycode == KEY_A)
		game->keys.a = 0;
	else if (keycode == KEY_S)
		game->keys.s = 0;
	else if (keycode == KEY_D)
		game->keys.d = 0;
	else if (keycode == KEY_RIGHT)
		game->keys.right = 0;
	else if (keycode == KEY_LEFT)
		game->keys.left = 0;
	return (0);
}

int key_press(int keycode, t_game *game)
{
    if (keycode == KEY_W)
        move_forward(game);
    else if (keycode == KEY_A)
        move_left(game);
    else if (keycode == KEY_S)
        move_backward(game);
    else if (keycode == KEY_D)
        move_right(game);
    else if (keycode == KEY_RIGHT)
        game->player.rotAngle += angle_to_rad(5);
    else if (keycode == KEY_LEFT)
        game->player.rotAngle -= angle_to_rad(5);
    else if (keycode == KEY_H)
		game->data->mini_map ^= 1;
    else if(keycode == KEY_ESC)
    {
        game->keys.esc = 1;
        ft_esc(game);
    }
    return (0);
}




void draw_player(t_game *game)
{
    // init_player_pos(game);
    int playerX = (int)game->player.pos.x;
    int playerY = (int)game->player.pos.y;
    int pixelSize = 1; // Adjust the size as needed

    // Calculate the coordinates for the top-left and bottom-right corners of the square
    int startX = playerX - pixelSize / 2;
    int startY = playerY - pixelSize / 2;
    int endX = playerX + pixelSize / 2;
    int endY = playerY + pixelSize / 2;

    if(startX < 0)
        startX = 0;
    if(startY < 0)
        startY = 0;
    if(endX <= game->data->map_data.m_width)
        endX = game->data->map_data.m_width -1;
    if(endY <= game->data->map_data.m_height)
        endY = game->data->map_data.m_height - 1;
    // Draw the filled square
    for (int x = startX; x <= endX; x++) {
        for (int y = startY; y <= endY; y++) {
            my_mlx_pixel_put(&game->img, x, y, 0x00FF0000); 
            // Draws a red pixel
            // mlx_pixel_put(game->img.mlx_ptr, game->img.win_mlx, x, y, 0xFFFFFF); // Draws a white pixel
        }
    }
}


// int key_press(int keycode, t_game *game)
// {
//     if (keycode == KEY_W)
//         game->keys.w = 1;
//     else if (keycode == KEY_A)
//         game->keys.a = 1;
//     else if (keycode == KEY_S)
//         game->keys.s = 1;
//     else if (keycode == KEY_D)
//         game->keys.d = 1;
//     else if (keycode == KEY_RIGHT)
//         game->keys.right = 1;
//     else if (keycode == KEY_LEFT)
//         game->keys.left = 1;
//     else if (keycode == KEY_H)
// 		game->data->mini_map ^= 1;
//     else if(keycode == KEY_ESC)
//     {
//         game->keys.esc = 1;
//         ft_esc(game);
//     }
//     return (0);
// }