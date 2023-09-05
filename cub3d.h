#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
#include <fcntl.h>
#include <ctype.h>


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



typedef struct s_sceneData
{
	// void 	wall;
	void		*win_mlx;
	void		*img_ptr;
	void		*mlx_ptr;
	void 		*ptr;
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

//------------------free------------------//

void    free_strs_array(char **strs);
//----------utils2------------//

void    emprty_str(char *str);
int 	ft_isdigit_strict(const char *str);

//----------util--------------//

char	*ft_strncpy(char *dest, char *src, size_t n);
void	*ft_realloc(void *ptr, size_t orig_size, size_t new_size);
char	**ft_split2(char *str, char *charset);
int 	is_space(char c);
void    skip_spaces(t_parserState *state);
void 	skip_newline(t_parserState *state); 
int 	ft_strcmp(const char *s1, const char *s2);

//----------print----------//
void	print_scene(t_sceneData *data);
void	print_map(t_map *map_data);

//----------map----------//

int		is_map(char *line);
void    get_map(t_sceneData *data,int mapStartedIndex);
// void    get_map(t_sceneData *data, t_map *map_data);
size_t  get_width(char **strlines);
char 	**cpy_map(char **scene, int *height);
void 	extract_map_lines(t_sceneData *data);
int		is_map_enclosed(char **map, int height, int width);

void	valid_extension(char *tex_path);

//----------parse----------//

void 	check_map_elm(t_sceneData *data);
void    get_scene(t_sceneData  *data);
void 	parse_map(char *line, t_map *map);
int 	color_ranges_valid(int *r, int *g, int *b);
void 	get_file(char *identifier, char *str, t_sceneData *data);//char **str, 
// int	is_color(t_parserState *state);
void	check_scene(t_sceneData	*data);

void	check_texture(t_sceneData *data);

#endif