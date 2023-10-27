/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:57:48 by ckarl             #+#    #+#             */
/*   Updated: 2023/10/27 17:40:24 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libs/libft/libft.h"
# include <fcntl.h>
# include <string.h>
# include <ctype.h>
# include <stddef.h>
# include <stdlib.h>
# include "../libs/mlx/mlx.h"
# include "structure.h"
# include "constant.h"
# include <math.h>

//---------cub3d--------------//
void	read_scene(char *file, t_sceneData *data);
int		ft_check_char(char *str, char c);
int		open_file(char *file);
void	check_arg(int ac, char **av);

//-------------get_next_line_functions--------------------//
char	*get_next_line(int fd);
char	*ft_join_free(char *buffer, char *buf);
char	*ft_line(char *buffer);
char	*ft_next_line(char *buffer);
char	*ft_read_file(int fd, char *result);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *str, int c);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t elementCount, size_t elementSize);

//-----------init-------------//

void	init_scenedata(t_sceneData *data);
void	init_map(t_map *grid);
void	init_textures(t_texture *texture);
void	init_color(t_color *color);
void	initialize_variables(t_scene_params *params);

//------------------free------------------//
void	free_map_data(t_map *map_data);
void	free_strs_array(char **strs);

//----------utils2------------//

void	empty_color(char *str);
int		ft_isdigit_strict(const char *str);

//----------util--------------//
int		ft_error_msg2(char *msg, char *msg2);
int		close_file(int fd);
void	skip_spaces(char *str);
int		is_space(char c);
int		ft_strcmp(const char *s1, const char *s2);
char	*my_strtok(char *srcString, char *delim);
unsigned int	is_delim(char c, char *delim);

//----------util4.c--------------//
int		ft_strlen_trim(char *str, char c);
int		tab_size(char **tab);
char	**trimmed_colors(char **tab, char c);
char	**ft_split_ck(char const *s, char c);
int		ft_char_in_set(char c, char const *set);

//----------print----------//
void	print_scene(t_sceneData *data);
void	print_map(t_map *map_data);

//----------error----------//
int		ft_error_msg(char *msg);

//----------map----------//

int		is_map(char *line);
void	get_map(t_sceneData *data, int map_started_index);
size_t	get_width(char **maplines);
void	free_map_data(t_map *map_data);
void	check_map(t_map *map_data);
void	check_map_valid_characters(t_map *map_data);
int		check_wall(char *line);
void	get_play_pos_coord(t_map *map_data, int row, int col, char dir);

//----------parse----------//

void	check_map_elm(t_sceneData	*data);
void	get_scene(t_sceneData	*data);
void	get_file(char *identifier, char *str,
			t_sceneData *data);//char **str,
void	check_scene(t_sceneData	*data);
int		valid_extension(char *tex_path);
void	check_color(t_color *color, char *color_name);
int		create_rgb(int r, int g, int b);
void	check_texture(char *texture, char *tex_name);
void	parse_texture(const char *str, t_texture *texture, char *identifier);
void	parse_color(const char *str, t_color *color, char *identifier);

//----------init_rendering----------//
void	init_mlx(t_mlx *mlx);
void	init_mlx_win(t_game *game);
int		init_graphics(t_game *game);

//----------draw----------//
void	draw_player_minimap(t_game *game);
void	draw_wall(t_game *game, t_wall_coordinate wall_coord);
void	render_2dmap_wall(t_game *game);
void	draw_2dgrid(t_game *game);

//----------load texture----------//
void	load_texture_img(void *mlx, t_texture *texture);
void	load_textures_img(t_game *game);

//-------rendering------------//
void	ready_game(t_game *game);
void	render_game(t_game *game);
void	get_event(t_game *game);
int		render_mini_map(t_game *game);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	generate_img(t_img *img, t_mlx *mlx, int width, int height);
void	get_background(t_game *game);

//-------get_player.c-------//
void	get_player(t_player *player, t_map *map_data);

//-------draw_C_F.c-------//
void	draw_ceiling(t_game *game, t_rect *rect);
void	draw_floor(t_game *game, t_rect *rect);
void	fill_rect(t_game *game, t_rect rect);

//-------exit.c-------//
void	destroy_textures(t_game *game);
int		exit_game(t_game *game);

//-------hook.c-------//
int		key_release(int keycode, t_game *game);
int		key_press(int keycode, t_game *game);
void	key_event(t_game *game);
void	turn_left(t_game *game);
void	turn_right(t_game *game);

//--------movement.c------//
void	move_forward(t_game *game);
void	move_backward(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);

//--------movement_utils1.c------//
void	left_right_adjust(t_player *player, int side);
void	beta_angle_calc(t_player *player);

//--------movement_utils2.c------//
void	check_direction(t_player *player);
void	move_straight(t_coord *update, t_game *game, int dir);
void	straight_dir(t_coord *update, t_game *game, int flag);
void	move_in_angle(t_coord *update, t_player *player, int flag);
void	move_angle_left_right(t_coord *update, t_player *player, int flag);

//--------ray_init.c----------//
void	get_ray_data(t_game *game);
void	draw_all_rays(t_game *game);
void	draw_single_ray(t_ray *ray, t_game *game);
void	draw_wall_slice(t_game *game, t_ray *ray, int x);
void	get_wall_height(t_ray *ray, t_game *game, double distance);

//--------ray_utils1.c------//
double	angle_to_rad(double rad);
double	rad_to_angle(double angle);
int		check_north(double angle);
int		check_west(double angle);
void	normalize_angle_rad(double *angle);

//--------ray_utils2.c------//
int		check_map_error(double x, double y, t_game *game);
int		check_map_error_movement(double x, double y, t_game *game);

//--------ray_vertical.c------//
void	get_vertical_ray(t_ray *ray, t_game *game);
void	get_sidedist_vt(t_ray *ray);
void	get_deltadist_vt(t_ray *ray);
void	set_ray_coef_vt(t_ray *ray);
void	get_vertical_wall_xpos(t_ray *ray);

//--------ray_horizontal.c------//
void	get_horizontal_ray(t_ray *ray, t_game *game);
void	get_sidedist_hz(t_ray *ray);
void	get_deltadist_hz(t_ray *ray);
void	set_ray_coef_hz(t_ray *ray);
void	get_horizontal_wall_xpos(t_ray *ray);

#endif