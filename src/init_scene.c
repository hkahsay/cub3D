#include "../cub3d.h"

t_color    *init_color(t_color *color)
{
  color = malloc(sizeof(t_color) + 1);

    color->R = -1;
    color->G = -1;
    color->B = -1;
    return (color);
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
    grid->m_height = 1;
    grid->m_width = 1;
    grid->pos = NULL;
}

t_parserState* init_parserState() {
    t_parserState* state = (t_parserState*) malloc(sizeof(t_parserState));
    state->data.west_texture.path = NULL;
    state->data.east_texture.path = NULL;
    state->data.north_texture.path = NULL;
    state->data.south_texture.path = NULL;
    state->data.ceiling_color.colors = NULL;
    state->data.floor_color.colors = NULL;
    // state->floor_color_set = 0;
    // state->ceiling_color_set = 0;
    state->line_number = 0;
    state->pos = 0;
    return state;
}

void    init_sceneData(t_sceneData *data)
{
    data->mlx_ptr = NULL;
    data->win_mlx = NULL;
    data->img_ptr = NULL;
    data->scene = NULL;
    data->map_height = 0;
    data->map_width = 0;
    data->elm = 0;
    init_textures(&(data->north_texture));
    init_textures(&(data->south_texture));
    init_textures(&(data->west_texture));
    init_textures(&(data->east_texture));

    init_color(&(data->floor_color));
    init_color(&(data->ceiling_color));

    init_map(&(data->N_pos));
    init_map(&(data->S_pos));
    init_map(&(data->E_pos));
    init_map(&(data->W_pos));
    init_map(&(data->map_field));
}