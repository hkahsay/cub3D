#include "../../cub3d.h"

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
        game->keys.w = 1;
    else if (keycode == KEY_A)
        game->keys.a = 1;
    else if (keycode == KEY_S)
        game->keys.s = 1;
    else if (keycode == KEY_D)
        game->keys.d = 1;
    else if (keycode == KEY_RIGHT)
        game->keys.right = 1;
    else if (keycode == KEY_LEFT)
        game->keys.left = 1;
    else if(keycode == KEY_ESC)
    {
        game->keys.esc = 1;
        ft_esc(game);
    }
    return (0);
}

int ft_esc(t_game *game)
{
    if (game->keys.esc == 1)
    {
        mlx_destroy_window(game->mlx.mlx_ptr, game->mlx.win_mlx);
        destroy_textures(game->mlx.mlx_ptr, &game->img);
        exit(0);
    }
    return (0);
}