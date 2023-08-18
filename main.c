#include "cub.h"

void check_arg(int ac, char **av)
{
	// if (ac != 2)
	// {
	// 	printf("Usage: ./cub3d <map>");
	// 	exit(1);
	// }
	if (ac < 2)
	{
		printf("%s\n", VIOLET"You dont have enough arguments\n");
		exit(1);
	}
	if (!ft_strchr(av[1], '.'))
	{
		printf("%s\n", RED"Invalid File");
		exit(1);
	}
	
	if (ft_strncmp((ft_strrchr(av[1], '.')), ".cub", 5))
	{
		printf("%s\n", RED"invalid extension");
		exit(1);
	}
}

int open_file(char *file)
{
	int	fd;
	fd = open(file, O_RDONLY);
	if(fd == -1)
	{
		printf("%s\n", RED"No file to read");
		exit(0);
	}
	return(fd);
}

void	read_scene(char *file, t_sceneData *data)
{
    char *combined_map = NULL;
    char *current_line = NULL;
    char *temp_map = NULL;
	int fd;

	current_line = NULL;
	fd = open_file(file);
	combined_map = ft_strdup(""); //// Allocate memory for a string to store the file contents, initialize with an empty string.
	while (1)
	{
		current_line = get_next_line(fd);
		if (current_line == NULL)
			break; // Exit the loop if no more lines can be read from the file.
		temp_map = combined_map;
		combined_map = ft_strjoin(temp_map, current_line);// Concatenate the new line to the existing file contents.
		free(temp_map);
		free(current_line);
	}
data->map = ft_split(combined_map, '\n');
free(combined_map);
free(current_line);
close(fd);

}

int main(int argc, char **argv)
{
	t_sceneData *data = NULL;
	data = malloc(sizeof(t_sceneData) + 1);
	check_arg(argc, argv);
	read_scene(argv[1], data);
	printf("hello cub3d\n");
	find_ray();
}