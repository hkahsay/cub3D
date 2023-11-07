/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:07:08 by ckarl             #+#    #+#             */
/*   Updated: 2023/10/27 14:32:28 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

# include "constant.h"

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;

}	t_img;

typedef struct s_wall_coordinate
{
	int	x;
	int	y;
	int	z;
}	t_wall_coordinate;

typedef struct s_tab_trim
{
	int	i;
	int	j;
	int	k;
}	t_tab_trim;

//		Color	Name

typedef struct s_texture
{
	char	*path;
	t_img	*img;
}	t_texture;

typedef struct s_color
{
	int		r;
	int		g;
	int		b;
	int		flag;
	int		rgb;
}	t_color;

typedef struct s_map_player
{
	int	row;
	int	col;
	int	dir;
}	t_map_player;

typedef struct s_map
{
	char			**map;
	int				m_width;
	int				m_height;
	char			*pos;
	t_map_player	play_pos;
}	t_map;

typedef struct s_scene_params
{
	int	i;
	int	map_started_index;
	int	mapstarted;
	int	should_increment_height;
}t_scene_params;

typedef struct s_coord
{
	double	x;
	double	y;
}	t_coord;

typedef struct s_hz_vt
{
	double	hz;
	double	vt;
}	t_hz_vt;

typedef struct s_texel
{
	int	x;
	int	y;
}	t_texel;

typedef struct s_player
{
	t_coord	pos;
	double	dir;
	double	beta;
	int		dir_field;
}	t_player;

typedef struct s_keys
{
	int	w;
	int	s;
	int	a;
	int	d;
	int	left;
	int	right;
	int	esc;

}	t_keys;

typedef struct s_rect
{
	int	x;
	int	y;
	int	width;
	int	height;
	int	border_color;
	int	border_width;
	int	fill_color;
}	t_rect;

typedef struct s_ray
{
	t_coord		ray_pos;
	t_coord		sidedist;
	t_coord		deltadist;
	t_coord		coef;
	t_player	player;
	t_hz_vt		eucl_dist;
	double		wallangle;
	double		walldist;
	double		wallheight;
	float		wall_pos_x;
	t_texture	*texture;
}	t_ray;

typedef struct s_ray_data
{
	double	view_angle;
	double	sub_ray_angle;
}	t_ray_data;

typedef struct s_mlx
{
	void		*img_ptr;
	void		*mlx_ptr;
	void		*win_mlx;
}	t_mlx;

typedef struct s_sceneData
{
	t_texture	north_texture;
	t_texture	south_texture;
	t_texture	west_texture;
	t_texture	east_texture;
	t_color		floor_color;
	t_color		ceiling_color;
	int			elm;
	t_map		map_data;
	int			mini_map;
	char		**scene;
	t_rect		rect;
}	t_sceneData;

typedef struct s_game
{
	t_sceneData	*data;
	t_keys		keys;
	t_mlx		mlx;
	t_img		img;
	t_player	player;
	t_rect		rect;
	t_ray_data	ray_data;
}	t_game;

#endif