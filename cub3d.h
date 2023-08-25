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

// typedef struct
// {
//     const char *identifier;
//     void (*parser)(const char *, void *);
// } IdentifierParser;

// void get_resolution(const char *str, t_sceneData *data);
// void get_texture(const char *str, t_texture *texture);
// void get_color(const char *str, t_color *color);

// IdentifierParser parsers[] = {
//     {"R", get_resolution},
//     {"NO", get_texture},
//     {"SO", get_texture},
//     {"WE", get_texture},
//     {"EA", get_texture},
//     {"S", get_texture},
//     {"F", get_color},
//     {"C", get_color},
// };

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
	char *colors;
} 	t_color;

typedef struct map
{
	char **map;
	int m_width;
	int	m_height;
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
	struct s_parserState	*state;
	t_color	floor_color;
	t_color	ceiling_color;
	t_map	N_pos;
	t_map	S_pos;
	t_map	E_pos;
	t_map	W_pos;
	char 	**map;
	size_t map_height;
    size_t map_width;
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
void 	find_ray();
// void	read_scene(char *file, t_parserState *state);
void	read_scene(char *file, t_sceneData *data);

int 	open_file(char *file);
void 	check_arg(int ac, char **av);
//-----------init-------------//

void 	init_sceneData(t_sceneData *data);
t_parserState *init_parserState();
void    init_map(t_map *grid);
void    init_textures(t_texture *texture);
void    init_color(t_color *color);

//----------util--------------//

// static int  find_length(char *str, char *charset);
char	*ft_strncpy(char *dest, char *src, size_t n);
// static void		import_str(char **dest, char *src, int start, int end);
char			**ft_split2(char *str, char *charset);
int is_space(char c);
void    skip_spaces(t_parserState *state);
void skip_newline(t_parserState *state); 
int ft_strcmp(const char *s1, const char *s2);

//----------parse----------//
int		is_map(char *line);


void parse_texture(char *line, t_texture *texture);
void parse_map(char *line, t_map *map);
int parse_scene(char *line, t_parserState *data);
void    is_scene_valid(char *curr_line, t_parserState *data);
void	print_scene(t_sceneData *data);

//----------parsestate----------//
void	get_nx_line(int fd, t_parserState *state);
char	current_char(t_parserState *state);
void	next_char(t_parserState	*state);

//----------parseTexture----------//

int is_all_texture_path_read(t_parserState	*state);
void read_single_texture(t_parserState *state, t_texture *texture, char expectedChar);
void handle_error_exit(t_parserState *state, char expected, char got);
char	*read_path(t_parserState *state);
void	read_texture(t_parserState *state);

//----------parseTexture----------//
int	is_color(t_parserState *state);
void	read_floor_ceiling(int fd, t_parserState *state);


#endif