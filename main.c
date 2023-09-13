#include "cub3d.h"




int main(int argc, char **argv)
{
	t_sceneData *data;
	
	// data = NULL;
	data = malloc(sizeof(t_sceneData));
	if(!data)
	{
		printf("Error\nMalloc failed\n");
		return (0);
	}
	check_arg(argc, argv);
	init_sceneData(data);
	read_scene(argv[1], data);
	rendering(data);
	// printf("data from main %s\n", data->scene[0]);

	// check_scene(data);
	
	// get_scene(data);
	free_map_data(&(data->map_data));
	free(data);
	return (0);
}

void check_arg(int ac, char **av)
{
	
	//!ft_strchr(av[1], '.' ) if dot is not found
	//ft_strncmp((ft_strrchr(av[1], '.')), ".cub", 5 if the last 4 characters are not .cub
	if (ac < 2)
	{
		printf("Error\n");
		printf("%s\n", VIOLET"You dont have enough arguments\n");
		exit(1);
	}
	if (!ft_strchr(av[1], '.'))
	{
		printf("Error\n");
		printf("%s\n", RED"Invalid File");
		exit(1);
	}
	
	if (ft_strncmp((ft_strrchr(av[1], '.')), ".cub", 5))
	{
		printf("Error\n");
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
		printf("Error\n");
		printf("%s\n", RED"No file to read"RESET);
		exit(0);
	}
	return(fd);
}

void    read_scene(char *file, t_sceneData *data)
{
    char *combined_map = NULL;
    char *current_line = NULL;
    char *temp_map = NULL;
	int fd;
	// data->scene = malloc(sizeof(char *) + 1);
	current_line = NULL;
	fd = open_file(file);
	combined_map = ft_strdup(""); // Allocate memory for a string to store the file contents, initialize with an empty string.
	if(!combined_map)
		return;
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
data->scene = ft_split(combined_map, '\n');
//print_scene(data);
free(combined_map);
free(current_line);
if (close(fd) == -1)
{
	printf("Error\nCould not close file %s.\n", file);
	exit(1);
}
get_scene(data);
check_scene(data);
// miss_color_set(data, "floor");
// miss_color_set(data, "ceiling");
// check_scene(data);
}





// int main(int argc, char **argv)
// {
//     t_sceneData *data;
//     data = malloc(sizeof(t_sceneData));
//     if (!data)
//     {
//         printf("Error\nMalloc failed\n");
//         return (0);
//     }

//     check_arg(argc, argv);
//     printf("argv[1]: %s\n", argv[1]);
//     init_sceneData(data);
//     read_scene(argv[1], data);
    
//     // Extract and print map lines
//     extract_map_lines(data);
    
//     // Continue with the rest of your logic
//     // ...
    
//     free(data);
//     return (0);
// }




// void    get_map(const char *line_map, t_map *map_data, t_sceneData *data)
// {
//     int i;

//     //Intialize map width and height
   
//     map_data->m_width = ft_strlen(line_map);

//     map_data->m_height = 0;

//    // memmory allocation for map
//    printf("map_data->map: %p\n", map_data->map);
//     map_data->map = (char **)malloc(sizeof(char *));
//     map_data->map[0] = strdup(line_map);
//    printf("map_data->map2: %s\n", map_data->map[0]);
//     map_data->m_height++;
//     //get the rest of the map
//     i = 0;
//     // printf("data->scene[i]1: %s\n", data->scene[i]);
//    printf("before data->scene[i]: %s\n", data->scene[i]);

//     while (data->scene[i] != NULL)
//     {
//         if (data->scene[i][0] == '\0')
//         {
//             printf("Error: Empty line in map.\n");
//             exit(EXIT_FAILURE);
//         }
//         else
//         {

//             map_data->m_height++;
//             //resize map array
//             map_data->map = (char **)realloc(map_data->map, map_data->m_height * sizeof(char *));
//             // Allocate memory and store the map line
//             map_data->map[map_data->m_height - 1] = strdup(data->scene[i]);
//         }
//         i++;
//         // printf("data->scene[i]: %s\n", data->scene[i]);
//     }
  
//    printf("data->scene[i]: %s\n", data->scene[i]);
// }



// //note what to continue
// //first check if its valid scene
