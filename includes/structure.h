/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:07:08 by ckarl						       #+#    #+#             */
/*   Updated: 2023/10/11 17:53:53 by ckarl            ###   ########.fr       */
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

//		Color	Name

typedef struct s_texture
{
	char	*path;
	t_img	img;
	int	tex_width;
	int	tex_height;
}	t_texture;

typedef struct s_color
{
	int	R;
	int	G;
	int	B;
	char	**colors;
	int	rgb;
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
	char	*pos;
	t_map_player	play_pos;
}	t_map;

typedef struct s_scene_params
{
	int	i;
	int	mapStartedIndex;
	int	mapstarted;
	int	shouldIncrementHeight;
}t_scene_params;

typedef struct s_ray_coord
{
	double	x;
	double	y;
}	t_coord;


// typedef struct s_player_coord
// {
// 	float	x;
// 	float	y;
// }	t_player_coord;

typedef struct s_player
{
	t_coord		pos;
	t_coord		plane;
	//	t_player_coord	delta;
	//	t_player_coord	dir;
	//	t_player_coord	plane;
	double			moveSpeed;
	double			rotSpeed;
	double			dir;
	double			beta;
	int				dir_field;
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
	t_coord	camera;
	t_coord	rayDir;
	t_coord	sideDist;
	t_coord	deltaDist;
	t_coord	perpWallDist;
	t_coord	step;
	double	wall_orientation;
	int	hit;
	double	lineHeight;
	t_player	*player;

}	t_ray;

typedef struct s_ray_data
{
	t_ray	*rays;
	double	view_angle;
	double	dist_to_plane;
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
	//	void		wall;
	t_texture				north_texture;
	t_texture				south_texture;
	t_texture				west_texture;
	t_texture				east_texture;
	t_texture				*texture_field;
	struct	s_parserState	*state;
	t_color					floor_color;
	t_color					ceiling_color;
	int						elm;
	t_map					map_data;
	int						mini_map;
	char					**scene;
	t_rect					rect;
	//	t_keys	keys;
	//	t_mlx	mlx;
	//	t_img	img;
	t_texture				textures[MAX_TEXTURES];
	int						num_textures;
	//	struct	s_game	game;

}	t_sceneData;

typedef struct s_time
{
	double	time;
	double	oldTime;
	double	frameTime;
}	t_time;

typedef struct s_game
{
	t_sceneData	*data;
	t_keys	keys;
	t_mlx	mlx;
	t_player	player;
	t_img	img;
	t_ray	ray;
	t_rect	rect;
	t_ray_data	ray_data;
	int	mapx;
	int	mapy;
	int	mapsize;
	t_time	time;
	//	t_img	textures[MAX_TEXTURES];
	//	int	num_textures;
	//	t_texture	texture;
}	t_game;

#endif