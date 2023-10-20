#include "../../includes/cub3d.h"

// Updated get_texture_img function
void	load_texture_img(void *mlx, t_texture *texture)
{
	texture->img = malloc(sizeof(t_img));
	if (!texture->img)
		ft_error_msg(RED"Malloc Error\n"RESET);
	// if (texture->tex_width > 0 && texture->tex_height > 0 && \
	// 	texture->tex_height == texture->tex_width)
	// {
		// printf("game->data->north_texture.path: %s\n", data->north_texture.path);
		texture->img->img = mlx_xpm_file_to_image(mlx, texture->path, \
			&texture->img->width, &texture->img->height);
		if (!texture->img->img)
			ft_error_msg(RED"Error\nTexture not found\n"RESET);
		texture->tex_height = texture->img->height;
		texture->tex_width = texture->img->width;
		texture->img->addr = mlx_get_data_addr(texture->img->img, \
			&texture->img->bits_per_pixel, \
			&texture->img->line_length, &texture->img->endian);



	// }
	// else
	// 	ft_error_msg(RED"Error\n image is not found\n"RESET);
}

void    load_textures_img(t_game *game)
{
	load_texture_img(game->mlx.mlx_ptr, &game->data->north_texture);
	load_texture_img(game->mlx.mlx_ptr, &game->data->south_texture);
	load_texture_img(game->mlx.mlx_ptr, &game->data->west_texture);
	load_texture_img(game->mlx.mlx_ptr, &game->data->east_texture);
}


// static int	*ft_get_color(t_img *img)
// {
// 	int		*color;
// 	int		i;
// 	t_real	pos;

// 	pos.x = 0;
// 	i = 0;
// 	color = malloc(sizeof(int) * (img->width * img->height));
// 	if (!color)
// 		ft_print_error(MSG_MALLOC_ERR);
// 	while (pos.x < img->width)
// 	{
// 		pos.y = 0;
// 		while (pos.y < img->height)
// 		{
// 			color[i] = ft_get_pixel(img, pos.x, pos.y);
// 			i++;
// 			pos.y++;
// 		}
// 		pos.x++;
// 	}
// 	return (color);
// }

// void destroy_textures(void *mlx, t_img *img)
// {
//     if (img->img != NULL)
//     {
//         mlx_destroy_image(mlx, &img->img);
//         img->img = NULL; // Set the pointer to NULL to avoid accidental reuse
//     }
//     // You can also reset any other texture-related fields if needed
// }


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
