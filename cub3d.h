#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
#include <fcntl.h>
#include <ctype.h>
#include <stddef.h>
#include <stdlib.h>
// #include "parser.h"



# define BUFFER_SIZE 	42

# define GREEN	"\033[1m\033[32m"
# define RED	"\033[1m\033[31m"
# define YELLOW  "\033[33m"
# define BLUE    "\033[34m"
# define VIOLET		"\033[0;36m"
# define RESET			"\033[0m"

# define KEY_ESC 	53
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_W	13
# define KEY_S 1
# define KEY_D 2
# define KEY_A 0

#  define MAX_RES_HEIGHT 1080
#  define MAX_RES_WIDTH 1920



//  Color Name

#include <stdio.h>
typedef struct s_texture
{
	char *path;
	int tex_width;
	int tex_height;
} t_texture;

typedef struct s_color
{
	int R;
	int	G;
	int	B;
	char **colors;
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


typedef struct s_resolution
{
	int width;
	int height;
} t_resolution;

typedef struct s_sceneData
{
	// void 	wall;
	void		*win_mlx;
	void		*img_ptr;
	void		*mlx_ptr;
	void 		*ptr;
	t_resolution	resolution;
	t_texture	north_texture;
	t_texture	south_texture;
	t_texture	west_texture;
	t_texture	east_texture;
	t_texture	*texture_field;
	struct s_parserState	*state;
	t_color	floor_color;
	t_color	ceiling_color;
	t_color	*color_field;
    int    elm;
	t_map	map_data;
	char 	**scene;
} t_sceneData;


typedef struct s_parserState
{
    size_t pos;
    int line_number;
	t_color floor_color;
    t_color ceiling_color;
	int floor_color_set;    // Flag for floor color
    int ceiling_color_set;  // Flag for ceiling color
    char *curr_line; // maybe use char* and remove [2048] instead
    t_sceneData data;
} t_parserState;


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


//---------cub3d--------------//
void	read_scene(char *file, t_sceneData *data);
int	ft_check_char(char *str, char c);

int 	open_file(char *file);
void 	check_arg(int ac, char **av);
//-----------init-------------//

void	init_sceneData(t_sceneData *data);
void    init_map(t_map *grid);
void    init_textures(t_texture *texture);
void  init_color(t_color *color);
void initialize_variables(t_scene_params *params);

//------------------free------------------//

void    free_strs_array(char **strs);
//----------utils2------------//

void    empty_color(char *str);
int 	ft_isdigit_strict(const char *str);
void miss_color_set(t_sceneData *data, const char *colorType);

//----------util--------------//

char	*ft_strncpy(char *dest, char *src, size_t n);
void	*ft_realloc(void *ptr, size_t orig_size, size_t new_size);
char	**ft_split2(char *str, char *charset);
int 	is_space(char c);
void 	skip_newline(t_parserState *state); 
int 	ft_strcmp(const char *s1, const char *s2);
// char *ft_strtok(const char *str, const char *delimiters);
char *ft_strtok(const char *str);
char *my_strtok(char *srcString, char *delim);


//----------print----------//
void	print_scene(t_sceneData *data);
void	print_map(t_map *map_data);

//----------error----------//
int ft_error_msg(char *msg);
void    empty_line_error(t_sceneData *data);

//----------map----------//

int		is_map(char *line);
void    get_map(t_sceneData *data,int mapStartedIndex);
size_t  get_width(char **maplines);
void 	free_map_data(t_map *map_data);
void    check_map(t_map *map_data);
void    ccheck_map_validty(char **map, int m_height, int row, int col);
void    check_map_valid_characters(char **map);
int 	is_surrounded(char **map);
int    check_wall(char *line);
int is_empty_line(char *str);
int has_empty_line(char **map, int height);

int check_row(char *row);

//----------parse----------//

void 	check_map_elm(t_sceneData *data);
void    get_scene(t_sceneData  *data);
void 	parse_map(char *line, t_map *map);
int 	color_ranges_valid(int *r, int *g, int *b);
void 	get_file(char *identifier, char *str, t_sceneData *data);//char **str, 
// int	is_color(t_parserState *state);
void	check_scene(t_sceneData	*data);
int		valid_extension(char *tex_path);
void	check_color(t_color *color, char *color_name);


void	check_texture(char *texture, char *tex_name);


#endif