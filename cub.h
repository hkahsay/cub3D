#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
#include <fcntl.h>

# define BUFFER_SIZE 	42

# define GREEN	"\033[1m\033[32m"
# define RED	"\033[1m\033[31m"
# define YELLOW  "\033[33m"
# define BLUE    "\033[34m"
# define VIOLET		"\033[0;36m"


# define KEY_ESC 	53
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_W	13
# define KEY_S 1
# define KEY_D 2
# define KEY_A 0

//  Color Name

#include <stdio.h>

typedef struct s_sceneData
{
	// void 	wall;
	// void 	player;
	void	*win_mlx;
	void	*img_ptr;
	void	*mlx_ptr;
	void 		*ptr;
	char 	**map;
	size_t map_height;
    size_t map_width;
} t_sceneData;


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


//---------cub3d--------
void find_ray();
void	read_scene(char *file, t_sceneData *data);
int open_file(char *file);
void check_arg(int ac, char **av);

#endif