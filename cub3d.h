#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
#include <stddef.h>
#include <stdlib.h>
#include "./mlx/mlx.h"
#include <math.h>
// #include "parser.h"
// # include "./mlx/mlx.h"


# define BUFFER_SIZE 	42

# define GREEN	"\033[1m\033[32m"
# define RED	"\033[1m\033[31m"
# define YELLOW  "\033[33m"
# define BLUE    "\033[34m"
# define VIOLET		"\033[0;36m"
# define RESET			"\033[0m"

# define KEY_ESC 	53
# define KEY_EXIT 17
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_W	13
# define KEY_S 1
# define KEY_D 2
# define KEY_A 0
# define KEY_M 46
# define KEY_H 4

# define MAX_WIDTH 1024
# define MAX_HEIGHT 512
# define FOV 60

# define TILE_SIZE 64
# define SCALE_MINI_MAP 8
# define PI 3.14159265359  
# define MAX_TEXTURES 5

typedef struct	s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int 	width;
	int 	height;
	
} t_img;


typedef struct s_wall_coordinate
{
	int	x;
	int	y;
	int	z;
}	t_wall_coordinate;

typedef struct s_lineNode {
    char *line;
    struct s_lineNode *next;
} t_lineNode;

//  Color Name

typedef struct s_texture
{
	char *path;
	t_img img;
	int tex_width;
	int tex_height;
	

} t_texture;

typedef struct s_color
{
	int R;
	int	G;
	int	B;
	char **colors;
	int rgb;
} 	t_color;

typedef struct s_map
{
	char **map;
	int m_width;
	int m_height;
	char	*pos;
}	t_map;

typedef struct s_scene_params
{
	int i;
    int mapStartedIndex;
    int mapstarted;
    int shouldIncrementHeight;
}t_scene_params;

typedef	struct s_ray_coord
{
	double x;
	double y;
}	t_ray_coord;

typedef struct s_player_coord
{
	float x;
	float y;
} t_player_coord;

typedef struct s_player
{
	t_ray_coord pos;
	t_ray_coord dir;
	t_ray_coord plane;
	// t_player_coord dir;
	// t_player_coord plane;
	double moveSpeed;
	double rotSpeed;
	double rotAngle;
} t_player;

typedef struct s_keys
{
	int w;
	int s;
	int a;
	int d;
	int left;
	int right;
	int esc;

} t_keys;

typedef struct s_rect
{
	int x;
	int y;
	int width;
	int height;
	int border_color;
	int border_width;
} t_rect;



typedef struct s_ray
{
	t_ray_coord camera;
	t_ray_coord rayDir;
	t_ray_coord sideDist;
	t_ray_coord deltaDist;
	t_ray_coord perpWallDist;
	t_ray_coord step;
	t_ray_coord tileSize;
	double wall;
	int hit;
	double lineHeight;
	t_player player;

} t_ray;



typedef struct s_mlx
{
	void		*img_ptr;
	void		*mlx_ptr;
	void		*win_mlx;
} t_mlx;
typedef struct s_sceneData
{
	// void 	wall;

	t_texture	north_texture;
	t_texture	south_texture;
	t_texture	west_texture;
	t_texture	east_texture;
	t_texture	*texture_field;
	struct s_parserState	*state;
	t_color	floor_color;
	t_color	ceiling_color;
    int    elm;
	t_map	map_data;
	int	mini_map;
	char 	**scene;
	t_rect rect;
	t_keys keys;
	t_mlx mlx;
	t_img img;
	t_texture textures[MAX_TEXTURES];
	int num_textures;
	// struct s_game game;
	
} t_sceneData;

typedef struct s_time
{
	double time;
	double oldTime;
	double frameTime;
} t_time;

typedef struct s_game
{
	t_sceneData *data;
	t_keys keys;
	t_mlx mlx;
	t_player player;
	t_img img;
	t_ray ray;
	int mapx;
	int mapy;
	int mapsize;
	t_time time;
	// t_img textures[MAX_TEXTURES];
	// int num_textures;
	// t_texture texture;
} t_game;



// void parse_resolution(const char *str, t_sceneData *data);
// void parse_texture(const char *str, t_sceneData *data);
// void parse_color(const char *str, t_sceneData *data);

// typedef struct
// {
//     const char *identifier;
//     void (*parser)(const char *, t_sceneData *); // This is correct for second argument type
// } IdentifierParser;


// IdentifierParser parsers[] = {
//     {"R", parse_resolution},
//     {"NO", parse_texture},
//     {"SO", parse_texture},
//     {"WE", parse_texture},
//     {"EA", parse_texture},
//     {"S", parse_texture},
//     {"F", parse_color},
//     {"C", parse_color},
// };

//get_next_line_functions
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

//-------rendering------------//
int    	init_graphics(t_game *game);
int    	key_release(int keycode, t_game *game);
int 	key_press(int keycode, t_game *game);
void 	init_mlx(t_mlx *mlx);
double	starting_angle(char c);
void	get_starting_position(t_player *player, char **grid);
void	get_player(t_game *game);
void	draw_player(t_game *game);
void	draw_mini_player(t_game *game);
void 	move_mini(t_game *game);
void 	init_mlx_win(t_game *game);
void	render_game(t_game *game);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	draw_wall(t_game *game, t_wall_coordinate wall_coord);
void	render_2dMap_wall(t_game *game);
int		render_mini_map(t_game *game);
void	fill_rect_ceiling(t_game *game, t_rect rect);
void	fill_rect_floor(t_game *game, t_rect rect);
void	generate_img(t_img *img, t_mlx *mlx, int width, int height);
void	get_background(t_game *game);
void	load_texture_img(void *mlx, t_img *img, t_texture *texture);
void    load_textures_img(t_game *game, t_img *img);
void    hooks(t_game *game);
// void load_textures_img(t_game *game);
// void load_texture(t_game *game, char *file_path);

//---------cub3d--------------//
void	read_scene(char *file, t_sceneData *data);
int		ft_check_char(char *str, char c);
char	**convert_linked_list_to_array(t_lineNode *line_list);
int 	open_file(char *file);
void 	check_arg(int ac, char **av);
//-----------init-------------//

void	init_sceneData(t_sceneData *data);
void    init_map(t_map *grid);
void    init_textures(t_texture *texture);
void	init_color(t_color *color);
void	initialize_variables(t_scene_params *params);
void	init_rect_ceiling(t_rect *rect, t_sceneData *data);
void	init_rect_floor(t_rect *rect, t_sceneData *data);

//--------------exit----------------//
int		exit_game(t_game *game);
int		ft_esc(t_game *game);
// void destroy_textures(void *mlx, t_img *img);
void	destroy_textures(t_game *game);

//------------------free------------------//
void	free_line_list(t_lineNode *head);
void	free_map_data(t_map *map_data);

void    free_strs_array(char **strs);
//----------utils2------------//

void    empty_color(char *str);
int 	ft_isdigit_strict(const char *str);

//----------util--------------//
char	*trim(char *str);
int		ft_error_msg2(char *msg, char *msg2);
int		close_file(int fd);

char	*ft_strncpy(char *dest, char *src, size_t n);
void	*ft_realloc(void *ptr, size_t orig_size, size_t new_size);
char	**ft_split2(char *str, char *charset);
int 	is_space(char c);
int 	ft_strcmp(const char *s1, const char *s2);
char	*ft_strtok(const char *str);
char	*my_strtok(char *srcString, char *delim);
void empty_reso(char *str);
//----------rendering utils----------//
double	rad_to_angle(double angle);
double	angle_to_rad(double rad);

//----------print----------//
void	print_scene(t_sceneData *data);
void	print_map(t_map *map_data);

//----------error----------//
int		ft_error_msg(char *msg);
void    empty_line_error(t_sceneData *data);

//----------map----------//

int		is_map(char *line);
void    get_map(t_sceneData *data,int mapStartedIndex);
size_t  get_width(char **maplines);
void 	free_map_data(t_map *map_data);
void    check_map(t_map *map_data);
void    check_map_valid_characters(char **map);
int		check_wall(char *line);
int		is_empty_line(char *str);
int		has_empty_line(char **map, int height);

//----------parse----------//

void 	check_map_elm(t_sceneData *data);
void    get_scene(t_sceneData  *data);
void 	get_file(char *identifier, char *str, t_sceneData *data);//char **str, 
void	check_scene(t_sceneData	*data);
int		valid_extension(char *tex_path);
void	check_color(t_color *color, char *color_name);
int		create_rgb(int r, int g, int b);
void	check_texture(char *texture, char *tex_name);


#endif