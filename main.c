#include "cub3d.h"

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


int main(int argc, char **argv)
{
	t_parserState *state = NULL;
	t_sceneData *data = NULL;

	
	data = malloc(sizeof(t_sceneData) + 1);

	// if(!state)
	// 	return(0);
	check_arg(argc, argv);
	init_sceneData(data);
	state = init_parserState();
	// printf("curline from main %s\n", data->state->curr_line);
	printf("hello\n");
	read_scene(argv[1], state);
	// printf("hello cub3d\n");
	// find_ray();
}

//note what to continue
//first check if its valid scene
