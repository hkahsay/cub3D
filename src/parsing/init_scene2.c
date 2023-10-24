#include "../../includes/cub3d.h"

void	init_img(t_img *img)
{
	img->img = NULL;
	img->addr = NULL;
	img->bits_per_pixel = 0;
	img->line_length = 0;
	img->endian = 0;
	img->width = 0;
	img->height = 0;
}

void	init_player(t_player *player)
{
	player->moveSpeed = 0;
	player->rotSpeed = 0;
	player->dir = 0;
}

void	init_mlx(t_mlx *mlx)
{
	mlx->mlx_ptr = NULL;
	mlx->win_mlx = NULL;
	mlx->img_ptr = NULL;
}

void	init_scenedata(t_sceneData *data)
{
	data->scene = NULL;
	data->mini_map = 0;
	data->elm = 0;
	init_textures(&(data->north_texture));
	init_textures(&(data->south_texture));
	init_textures(&(data->west_texture));
	init_textures(&(data->east_texture));
	init_color(&(data->floor_color));
	init_color(&(data->ceiling_color));
	init_map(&(data->map_data));
}
