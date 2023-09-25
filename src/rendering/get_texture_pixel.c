#include "../../cub3d.h"


// In your ft_esc function, call destroy_textures to release textures before exiting
int ft_esc(t_game *game)
{
    if (game->keys.esc == 1)
    {
        mlx_destroy_window(game->mlx.mlx_ptr, game->mlx.win_mlx);
        destroy_textures(game);
        exit(0);
    }
    return (0);
}

// Updated get_texture_img function
void load_texture_img(void *mlx, t_img *img, t_texture *texture)
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



void    load_textures_img(t_game *game, t_img *img)
{
    load_texture_img(game->mlx.mlx_ptr, img, &game->data->north_texture);
    // printf("game->data->north_texture.path: %s\n", game->data->north_texture.path);
    load_texture_img(game->mlx.mlx_ptr, img, &game->data->south_texture);
    load_texture_img(game->mlx.mlx_ptr, img, &game->data->west_texture);
    load_texture_img(game->mlx.mlx_ptr, img, &game->data->east_texture);
}

// void destroy_textures(void *mlx, t_img *img)
// {
//     if (img->img != NULL)
//     {
//         mlx_destroy_image(mlx, &img->img);
//         img->img = NULL; // Set the pointer to NULL to avoid accidental reuse
//     }
//     // You can also reset any other texture-related fields if needed
// }

// void load_textures_img(t_game *game)
// {
//     load_texture(game, game->data->north_texture.path);
//     load_texture(game, game->data->south_texture.path);
//     load_texture(game, game->data->west_texture.path);
//     load_texture(game, game->data->east_texture.path);
// }

// Function to destroy all loaded textures
void destroy_textures(t_game *game)
{
    for (int i = 0; i < game->data->num_textures; i++) {
        if (game->data->textures[i].img.img != NULL) {
            mlx_destroy_image(game->mlx.mlx_ptr, game->data->textures[i].img.img);
            game->data->textures[i].img.img = NULL;
        }
    }
}

// Function to load a texture and store it in the game struct
// void load_texture(t_game *game, char *file_path)
// {
//     printf("game->data->num_textures: %d\n", game->data->num_textures);
//     if(game->data->num_textures < MAX_TEXTURES)
//     {
//         int width; // Declare width here
//         int height; // Declare height here


//         game->data->textures[game->data->num_textures].img.img = mlx_xpm_file_to_image(game->mlx.mlx_ptr, file_path, &width, &height);
//         if (game->data->textures[game->data->num_textures].img.img != NULL) {
//             game->data->textures[game->data->num_textures].tex_width = width; // Update tex_width
//             game->data->textures[game->data->num_textures].tex_height = height; // Update tex_height
//             // Initialize image data fields
//             game->data->textures[game->data->num_textures].img.addr = mlx_get_data_addr(
//                 game->data->textures[game->data->num_textures].img.img,
//                 &game->data->textures[game->data->num_textures].img.bits_per_pixel,
//                 &game->data->textures[game->data->num_textures].img.line_length,
//                 &game->data->textures[game->data->num_textures].img.endian
//             );
//             game->data->num_textures++;
//             // printf("game->data->num_textures: %d\n", game->data->num_textures);
//         } else {
//             // Handle error if the texture couldn't be loaded
//             ft_error_msg(RED"Error\nTexture not found\n"RESET);
//         }
//         // game->data->num_textures++;
//     }
//     else {
//         // Handle error if too many textures are loaded
//         ft_error_msg(RED"Error\nMaximum number of textures reached\n"RESET);
//     }
// }
