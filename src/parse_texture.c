#include "../cub3d.h"
// #include "../parser.h"


void	check_texture(char *texture, char *tex_name)
{
	int fd;
	// printf("texture: %s\n", texture);
	// if(valid_extension(texture) == 0)
	// {
	// 	printf(RED"Error\n%s texture path is invalid\n"RESET, tex_name);
	// 	exit(EXIT_FAILURE);
	// }

	printf("texture: %s\n", texture);
	if (texture == NULL)
	{
		printf( RED"Error\n%s texture path is empty\n"RESET, tex_name);
		exit(EXIT_FAILURE);
	}
	if ((fd = open(texture, O_RDONLY)) == -1)
	{
		printf(RED"Error\ncan not open %s: %s\n"RESET, tex_name, texture);
		exit(EXIT_FAILURE);
	}
	if (close(fd) == -1)
	{
		printf(RED"Error\n%s Could not close texture file\n"RESET, texture);
		exit(EXIT_FAILURE);
	}

}

int	valid_extension(char *tex_path)
{
	int len;

	
	len = ft_strlen(tex_path);
	printf("tex_path: %s\n", tex_path);
	if (tex_path[len - 1] != 'j' || tex_path[len - 2] != 'p' || tex_path[len - 3] != 'x' || tex_path[len - 4] != '.')
	{
		printf("tex_path: %s\n", tex_path);
		return (0);
	}
	return (1);
}