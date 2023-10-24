#include "../../includes/cub3d.h"

void	init_color(t_color *color)
{

	color->r = -1;

	color->g = -1;

	color->b = -1;
}

void	init_textures(t_texture *texture)
{
	texture->path = NULL;
}

void	init_map(t_map *grid)
{
	grid->map = NULL;
	grid->m_height = 0;
	grid->m_width = 0;
	grid->pos = NULL;
}

void	initialize_variables(t_scene_params *params)
{
	params->i = 0;
	params->mapStartedIndex = 0;
	params->mapstarted = 0;
	params->shouldIncrementHeight = 1;
}

