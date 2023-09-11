#include "../cub3d.h"
// #include "../parser.h"

// static int		check_extension(char *file, char *extension)
// {
// 	int	len_file;
// 	int	len_ext;

// 	len_file = ft_strlen(file);
// 	len_ext = ft_strlen(extension);
// 	if (len_file <= len_ext)
// 		return (0);
// 	else if (!ft_strncmp(&file[len_file - len_ext], extension, len_ext + 1))
// 		return (1);
// 	else
// 		return (0);
// }

void	check_texture(char *texture, char *tex_name)
{
	int fd;
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
	if(valid_extension(texture) == 0)
	{
		printf(RED"Error\nFile doesn't have xpm extension\n"RESET);
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