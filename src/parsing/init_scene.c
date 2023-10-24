#include "../../includes/cub3d.h"

void	init_color(t_color *color)
{
	color->R = -1;
	color->G = -1;
	color->B = -1;
}

// void	init_keys(t_keys *keys)
// {
// 	keys->w = 0;
// 	keys->a = 0;
// 	keys->s = 0;
// 	keys->d = 0;
// 	keys->left = 0;
// 	keys->right = 0;
// }

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

void	init_textures(t_texture *texture)
{
	texture->path = NULL;
	// texture->tex_height = 0;
	// texture->tex_width = 0;
}

void	init_map(t_map *grid)
{
	grid->map = NULL;
	grid->m_height = 0;
	grid->m_width = 0;
	grid->pos = NULL;
	// grid->play_pos.row = 0;
	// grid->play_pos.col = 0;
	// grid->play_pos.dir = 0;
}

void	initialize_variables(t_scene_params *params)
{
	params->i = 0;
	params->mapStartedIndex = 0;
	params->mapstarted = 0;
	params->shouldIncrementHeight = 1;
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

void	init_sceneData(t_sceneData *data)
{
	// init_mlx(&(data->mlx));
	// init_img(&(data->img));
	// init_keys(&(data->keys));
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
