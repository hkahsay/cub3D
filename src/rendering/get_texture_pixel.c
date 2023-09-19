#include "../../cub3d.h"

// Updated get_texture_img function
void get_texture_img(void *mlx, t_img *img, t_texture *texture)
{
    if (img->img != NULL)
    {
        mlx_destroy_image(mlx, img->img); // Free any existing image
    } 
    if (texture->tex_width > 0 && texture->tex_height > 0)
    {
        // printf("game->data->north_texture.path: %s\n", data->north_texture.path);
        img->img = mlx_xpm_file_to_image(mlx, texture->path, \
        &texture->tex_width, &texture->tex_height);
        if(img->img != NULL)
        {
            img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, \
                &img->line_length, &img->endian);
        }
        else
            ft_error_msg(RED"Error\nTexturee not found\n"RESET);
    }
    else
        ft_error_msg(RED"Error\n image is not found\n"RESET);
}

void    get_textures_img(t_game *game, t_img *img)
{
    get_texture_img(game->mlx.mlx_ptr, img, &game->data->north_texture);
    // printf("game->data->north_texture.path: %s\n", game->data->north_texture.path);
    get_texture_img(game->mlx.mlx_ptr, img, &game->data->south_texture);
    get_texture_img(game->mlx.mlx_ptr, img, &game->data->west_texture);
    get_texture_img(game->mlx.mlx_ptr, img, &game->data->east_texture);
}

void destroy_textures(void *mlx, t_img *img)
{
    if (img->img != NULL)
    {
        mlx_destroy_image(mlx, &img->img);
        img->img = NULL; // Set the pointer to NULL to avoid accidental reuse
    }
    // You can also reset any other texture-related fields if needed
}