#include "../../includes/cub3d.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}



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
//             if (i < rect->border_width || i > rect->width - rect->border_width
//                 || j < rect->border_width || j > rect->height - rect->border_width)
//                 img[(rect->y + j) * img_width + rect->x + i] = color;
//             j++;
//         }
//         j = 0;
//         i++;
//     }
// }
void fill_rect_floor(t_game *game, t_rect rect)
{
    int x, y;
    int color = rect.border_color;

    for (x = rect.x; x < rect.x + rect.width; x++)
    {
        for (y = rect.y; y < rect.y + rect.height; y++)
        {
            my_mlx_pixel_put(&game->img, x, y, color);
        }
    }
}

void fill_rect_ceiling(t_game *game, t_rect rect)
{
    int x, y;
    int color = rect.border_color;

    for (x = rect.x; x < rect.x + rect.width; x++)
    {
        for (y = rect.y; y < rect.y + rect.height; y++)
        {
            my_mlx_pixel_put(&game->img, x, y, color);
        }
    }
}



void generate_img(t_img *img, t_mlx *mlx, int width, int height)
{
    img->img = mlx_new_image(mlx->mlx_ptr, width, height);
    img->width = width;
    img->height = height;
    img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, \
    &img->line_length, &img->endian);
}

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

void render_game(t_game *game)
{
    generate_img(&game->img, &game->mlx, MAX_WIDTH, MAX_HEIGHT);
    get_background(game);
    // draw_vertical_lines(game);
    mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_mlx, game->img.img, 0, 0);                            
    // mlx_destroy_image(game->mlx.mlx_ptr, game->img.img);
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
void get_background(t_game *game)
{
    generate_img(&game->img, &game->mlx, MAX_WIDTH, MAX_HEIGHT);
    init_rect_ceiling(&game->data->rect, game->data);
    fill_rect_ceiling(game, game->data->rect);
    init_rect_floor(&game->data->rect, game->data);
    fill_rect_floor(game, game->data->rect);
    mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_mlx, game->img.img, 0, 0);
    // mlx_destroy_image(game->mlx.mlx_ptr, game->img.img);
}
// Updated rendering function
void init_mlx_win(t_game *game)
{
    game->mlx.mlx_ptr = mlx_init();
    game->mlx.win_mlx = mlx_new_window(game->mlx.mlx_ptr, MAX_WIDTH, MAX_HEIGHT, "cub3D");

    mlx_hook(game->mlx.win_mlx, 2, 0, key_press, game);//key_press
    mlx_hook(game->mlx.win_mlx, 3, 0, key_release, game);//key_release
    mlx_loop_hook(game->mlx.mlx_ptr, init_graphics, game);
    mlx_loop(game->mlx.mlx_ptr);
}



int exit_game(t_game *game)
{
    free_map_data(&game->data->map_data);
    // destroy_textures(game->mlx.mlx_ptr, &game->img);
    free(game->data);
    free(game);
    exit(0);
    return (0);
}
    // mlx_hook(data->mlx.win_mlx, 3, 0, key_release, data);//key_release

