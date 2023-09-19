#include "../../cub3d.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}




void movment(t_game *game)
{
    if (game->keys.w) {
        // Move player forward
        game->player.posX += cos(game->player.rotAngle) * game->player.moveSpeed;
        game->player.posY += sin(game->player.rotAngle) * game->player.moveSpeed;
    }
    if (game->keys.s) {
        // Move player backward
        game->player.posX -= cos(game->player.rotAngle) * game->player.moveSpeed;
        game->player.posY -= sin(game->player.rotAngle) * game->player.moveSpeed;
    }
    if (game->keys.left) {
        // Rotate player left
        game->player.rotAngle -= game->player.rotSpeed;
    }
    if (game->keys.right) {
        // Rotate player right
        game->player.rotAngle += game->player.rotSpeed;
    }
}

void render_game(t_game *game)
{
  
    game->img.img = mlx_new_image(game->mlx.mlx_ptr, game->data->resolution.width, game->data->resolution.height);
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bits_per_pixel, &game->img.line_length,
								&game->img.endian);
    get_textures_img(game, &game->img);
    mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_mlx, game->img.img, 0, 0);                            
    mlx_destroy_image(game->mlx.mlx_ptr, game->img.img);
}

int	init_graphics(t_game *game)
{
	if (game->data->mini_map == 1)
	{
		render_mini_map(game);
	}
	else
	{
		render_game(game);
	}
	return (1);
}
// Updated rendering function
void init_mlx_win(t_game *game)
{
    game->mlx.mlx_ptr = mlx_init();
    game->mlx.win_mlx = mlx_new_window(game->mlx.mlx_ptr, game->data->resolution.width, game->data->resolution.height, "cub3D");
    // mlx_hook(game->mlx.win_mlx, KEY_EXIT, 0, exit_game, game);//key_press
    // game->img.img = mlx_new_image(game->mlx.mlx_ptr, game->data->resolution.width, game->data->resolution.height);
	// game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bits_per_pixel, &game->img.line_length,
	// 							&game->img.endian);
    // mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_mlx, game->img.img, 0, 0);                            
    mlx_hook(game->mlx.win_mlx, 2, 0, key_press, game);//key_press
    // mlx_hook(game->mlx.win_mlx, 3, 0, key_release, game);//key_press
    mlx_loop_hook(game->mlx.mlx_ptr, init_graphics, game);
    mlx_loop(game->mlx.mlx_ptr);
}


int exit_game(t_game *game)
{
    free_map_data(&game->data->map_data);
    free(game->data);
    free(game);
    exit(0);
    return (0);
}
    // mlx_hook(data->mlx.win_mlx, 3, 0, key_release, data);//key_release

