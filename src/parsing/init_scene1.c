/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 20:07:41 by ckarl             #+#    #+#             */
/*   Updated: 2023/10/24 20:24:53 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	params->map_started_index = 0;
	params->mapstarted = 0;
	params->should_increment_height = 1;
}
