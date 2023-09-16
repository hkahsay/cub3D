#include "../../cub3d.h"



// void    rendering(t_game *game)
// {
//     game->mlx->mlx_ptr = mlx_init();
//     game->mlx->win_mlx = mlx_new_window(game->mlx->mlx_ptr, game->data->resolution.width, game->data->resolution.height, "cub3D");
//     mlx_hook(game->mlx->win_mlx, 2, 0, key_press, game);//key_press
//     mlx_hook(game->mlx->win_mlx, 3, 0, key_release, game);//key_release
//     mlx_loop(game->mlx->mlx_ptr);
// }
// static void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }
// static void   draw(int *img, int x, int y)
// {
//     int i = 0;
//     while (i < x * y)
//     {
//         img[i] = 0x00FF00FF;
//         i++;
//     }

// }
// void draw_ceiling(int img, int x, int y)
// {
//     int i = 0;
//     while (i < x * y)
//     {
//         img[i] = data->ceiling_color.rgb;
//         i++;
//     }
// }
// static int		get_fill_color(t_color *floor_color, char grid_item)
// {
// 	int	color;

// 	if (grid_item == '1')
// 		color = floor_color->rgb;
// 	else if (grid_item == '0')
// 		color = 0x00fca311;
// 	else
// 		color = 0x00FFFFFF;
// 	return (color);
// }

// static void   draw_map(t_sceneData *data, int y, int x)
// {
    // int y = 0;
    // while (y < data->map_data.m_height)
//     {
//         // int x = 0;
//         while (x < data->map_data.m_width)
//         {
//             if (data->map_data.map[y][x] == '1')
//             {
//                printf("render data->map_data.map[%d][%d]: %c\n", y, x, data->map_data.map[y][x]);
//                 mlx_pixel_put(data->mlx.mlx_ptr, data->mlx.win_mlx, x, y, 0x00FF0000);
//             }
//             else if (data->map_data.map[y][x] == '0')
//             {
//                 mlx_pixel_put(data->mlx.mlx_ptr, data->mlx.win_mlx, x, y, 0x0000FF00);
//             }
//             x++;
//         } 
//         y++;
//     }
// }
 //my_mlx_pixel_put(&img, 5, 5, 0x00FF00FF);
	// my_mlx_pixel_put(&img, 6, 6, 0x00FF00FF);
	// my_mlx_pixel_put(&img, 7, 7, 0x00FF00FF);
	// my_mlx_pixel_put(&img, 8, 8, 0x00FF00FF);
	// my_mlx_pixel_put(&img, 9, 9, 0x00FF00FF);
	// my_mlx_pixel_put(&img, 10, 10, 0x00FF00FF);
	// my_mlx_pixel_put(&img, 11, 11, 0x00FF00FF);
	// my_mlx_pixel_put(&img, 12, 12, 0x00FF00FF);
// static void get_texture_img(t_sceneData *data, t_img *img, char *path, t_texture *texture)
// {
//     if (img->img != NULL && img->addr != NULL) 
//     {
//         if (texture->tex_width > 0 && texture->tex_height > 0)
//         {
//             img->img = mlx_xpm_file_to_image(data->mlx.mlx_ptr, path, \
//             &texture->tex_width, &texture->tex_height);
//             img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, \
//             &img->line_length, &img->endian);
//         }
//         else
//         {
//             printf("Error\nTexturee not found\n");
//             exit(0);
//         }
//     }
//     else
//     {
//         printf("Error\nTexture not found\n");
//         exit(0);
//     }
// }
// void    rendering(t_game *game)
// {
//     t_img	img;
//     printf("game->data->north_texture.path: %s\n", game->data->north_texture.path);
//     game->mlx.mlx_ptr = mlx_init();
//     game->mlx.win_mlx = mlx_new_window(game->mlx.mlx_ptr, game->data->resolution.width, game->data->resolution.height, "cub3D");
// 	img.img = mlx_new_image(game->mlx.mlx_ptr, game->data->resolution.width, game->data->resolution.height);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
// 								&img.endian);
//     get_texture_img(game->data, &img, game->data->north_texture.path, &game->data->north_texture);
//     get_texture_img(game->data, &img, game->data->south_texture.path, &game->data->south_texture);
//     get_texture_img(game->data, &img, game->data->west_texture.path, &game->data->west_texture);
//     get_texture_img(game->data, &img, game->data->east_texture.path, &game->data->east_texture);
//     // draw((int *)img.addr, game->data->resolution.width, game->data->resolution.height);  
//     // draw_map(data, data->map_data.m_height, data->map_data.m_width);                          

//     mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_mlx, img.img, 0, 0);
//     mlx_loop(game->mlx.mlx_ptr);
// }






static int		get_fill_color(t_color *floor_color, char grid_item)
{
	int	color;

	if (grid_item == '1')
		color = floor_color->rgb;
	else if (grid_item == '0')
		color = 0x00fca311;
	else
		color = 0x00FFFFFF;
	return (color);
}
int	draw_map(t_game *game)
{
	// t_rect	rect;
	int		i;
	int		j;
    int     fill_color;
	char	grid_item;

	i = -1;
	while (++i < game->data->map_data.m_height)
	{
		j = -1;
		while (++j < game->data->map_data.m_width)
        {
            grid_item = game->data->map_data.map[i][j];
            if (grid_item == ' ')
                continue ;
            // rect.x = j * game->data->map_data.tile_size;
            // rect.y = i * game->data->map_data.tile_size;
            // rect.width = game->data->map_data.tile_size;
            // rect.height = game->data->map_data.tile_size;
            // rect.border_color = 0x0014213d;
            // rect.border_width = 0;
            fill_color = get_fill_color(&game->data->floor_color, grid_item);
            // draw_rect(&rect, game->mlx.img.data, game->scene.res.width);
        }
	}
	return(fill_color);
}


// Updated rendering function
void rendering(t_game *game)
{
    t_img img;
    int px = 100;
    int py = 100;
    game->mlx.mlx_ptr = mlx_init();
    game->mlx.win_mlx = mlx_new_window(game->mlx.mlx_ptr, game->data->resolution.width, game->data->resolution.height, "cub3D");

    // Initialize img.img and img.addr here
    img.img = mlx_new_image(game->mlx.mlx_ptr, game->data->resolution.width, game->data->resolution.height);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    get_textures_img(game, &img);
    get_player(game);
    mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_mlx, img.img, 0, 0);
    mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_mlx, img.img, px, py);

    mlx_hook(game->mlx.win_mlx, KEY_EXIT, 0, exit_game, game);//key_press
    mlx_hook(game->mlx.win_mlx, 2, 0, key_press, game);//key_press
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

