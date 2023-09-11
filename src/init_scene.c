#include "../cub3d.h"

void    init_color(t_color *color)
{
//   color = malloc(sizeof(t_color) + 1);
  if(!color)
    return;

    color->R = -1;
    color->G = -1;
    color->B = -1;
    // printf("color->R, %d color->G, %d color->B  %d", color->R, color->G, color->B);
}

void    init_textures(t_texture *texture)
{
    texture->path = NULL;
    texture->tex_height = 0;
    texture->tex_width = 0;
}

void    init_map(t_map *grid)
{
    grid->map = NULL;
    grid->m_height = 0;
    grid->m_width = 0;
    grid->pos = NULL;
}

void initialize_variables(t_scene_params *params)
{
    params->i = 0;
    params->mapStartedIndex = 0;
    params->mapstarted = 0;
    params->shouldIncrementHeight = 1;
} 

void    init_sceneData(t_sceneData *data)
{
    data->mlx_ptr = NULL;
    data->win_mlx = NULL;
    data->img_ptr = NULL;
    data->scene = NULL;
    data->elm = 0;
    init_textures(&(data->north_texture));
    init_textures(&(data->south_texture));
    init_textures(&(data->west_texture));
    init_textures(&(data->east_texture));
    init_color(&(data->floor_color));
    init_color(&(data->ceiling_color));
    init_map(&(data->map_data));
}