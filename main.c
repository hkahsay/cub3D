#include "cub3d.h"




int main(int argc, char **argv)
{
	t_game *game;
	
	// data = NULL;
	game = malloc(sizeof(t_game));
	game->data = malloc(sizeof(t_sceneData));
	if(!game->data)
	{
		printf("Error\nMalloc failed\n");
		return (0);
	}
	check_arg(argc, argv);
	init_sceneData(game->data);
	read_scene(argv[1], game->data);
	printf("1\n");
	get_scene(game->data);
	printf("2\n");

	check_scene(game->data);
	printf("3\n");
	init_mlx_win(game);
	init_graphics(game);
	// printf("game->data->resolution.width: %d\n", game->data->resolution.width);
    // printf("game->data->north_texture.path: %s\n", game->data->north_texture.path);
	// double posX = 22.0, posY = 11.5;  //x and y start position
  	// double dirX = -1.0, dirY = 0.0; //initial direction vector
	// printf("data from main %s\n", data->scene[0]);

	// check_scene(data);
    // destroy_textures(game->mlx.mlx_ptr, &game->img);
	
	// get_scene(data);
	free_map_data(&(game->data->map_data));
	free(game->data);
	// free(game);
	return (0);
}

void check_arg(int ac, char **av)
{
	
	//!ft_strchr(av[1], '.' ) if dot is not found
	//ft_strncmp((ft_strrchr(av[1], '.')), ".cub", 5 if the last 4 characters are not .cub
	if (ac < 2)
	{
		printf("Error\n");
		printf("%s\n", VIOLET"Too few arguments\n");
		exit(1);
	}
	if (ac > 2)
	{
		printf("Error\n");
		printf("%s\n", VIOLET"Too many arguments\n");
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



t_lineNode *build_linked_list(int fd)
{
    t_lineNode *line_list = NULL;
    t_lineNode *last_node = NULL;
    char *current_line = NULL;

    while (1)
	{
        current_line = get_next_line(fd);
        if (current_line == NULL)
            break; // Exit the loop if no more lines can be read from the file.

        // Create a new node in the linked list for the current line.
 		current_line = trim(current_line);

        t_lineNode *new_node = malloc(sizeof(t_lineNode));
        if (!new_node) {
            // Handle memory allocation error here.
            free_line_list(line_list); // Free the previously allocated nodes.
            return (NULL);
        }
        new_node->line = current_line;
        new_node->next = NULL;
        // If it's the first node, set line_list to point to it.
        if (line_list == NULL)
            line_list = new_node;
		else
            last_node->next = new_node;
        last_node = new_node; // Update the last_node pointer.
    }
	// while (line_list != NULL)
	// {
	// 	printf("line_list->line %s\n", line_list->line);
	// 	line_list = line_list->next;
	// }
    return (line_list);
}

// static void initialize_data(t_sceneData *data, char **combined_map, char **current_line, t_lineNode **line_list) {
//     *combined_map = NULL;
//     *current_line = NULL;
//     *line_list = NULL;
//     data->scene = NULL; // If needed, you can also initialize data members here.
// }

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
// get_scene(data);
// check_scene(data);
// miss_color_set(data, "floor");
// miss_color_set(data, "ceiling");
// check_scene(data);
}


// void    read_scene(char *file, t_sceneData *data)
// {
// 	int fd;
//     char *combined_map;
//     char *current_line;
// 	t_lineNode *line_list; // Initialize the linked list to NULL.

// 	initialize_data(data, &combined_map, &current_line, &line_list);
// 	fd = open_file(file);
// 	combined_map = ft_strdup(""); // Allocate memory for a string to store the file contents, initialize with an empty string.
// 	if(!combined_map)
// 		return;
// 	line_list = build_linked_list(fd); // Call the function to build the linked list.
//     if (line_list == NULL) 
// 	{
//         // Handle error if the linked list could not be built.
//         free(combined_map);
//         close_file(fd);
//         return;
//     } 
// 	data->scene = convert_linked_list_to_array(line_list);
// 	// print_scene(data);
// 	free(combined_map);
// 	free(current_line);
// 	close_file(fd);
// }

int close_file(int fd)
{
	if (close(fd) == -1)
	{
		printf("Error\nCould not close file.\n");
		exit(1);
	}
	return (0);

}

char **convert_linked_list_to_array(t_lineNode *line_list)
{
    int count = 0;
    t_lineNode *current = line_list;

    // Count the number of nodes in the linked list.
    while (current != NULL) {
        count++;
        current = current->next;
    }

    // Allocate memory for the char** array.
    char **array = (char **)malloc((count + 1) * sizeof(char *));
    if (array == NULL) {
        // Handle memory allocation error here.
        return NULL;
    }

    // Copy lines from the linked list to the array.
    current = line_list;
    int i = 0;
	// char *trimmed_line = ft_strtrim(current->line, " ");
    while (current != NULL) {
        array[i] = current->line;
        // array[i] = trimmed_line;
        i++;
        current = current->next;
    }
    array[i] = NULL;  // Null-terminate the array.
	i = 0;
	while (array[i] != NULL)
	{
		printf("array[i] %s\n", array[i]);
		i++;
	}
	
    return array;
}

// if (is_empty_line(current_line)) {
            // Handle empty line error here (you can define is_empty_line() to check for empty lines).
        //     ft_error_msg("Error\nEmpty line in map.\n");
		// 	free(current_line);
        //     // free_line_list(line_list); // Free the allocated memory before returning.
        //     return;
        // }






// void read_scene(char *file, t_sceneData *data) {
//     int fd;
//     char *current_line = NULL;
//     t_lineNode *line_list = NULL; // Initialize the linked list to NULL.
    
//     fd = open_file(file);
//     if (fd == -1) {
//         // Handle file open error here.
//         return;
//     }

//     while (1) {
//         current_line = get_next_line(fd);
//         if (current_line == NULL) {
//             break; // Exit the loop if no more lines can be read from the file.
//         }

//         // // Check if the line is empty (contains only whitespace characters).
//         if (is_empty_line(current_line)) {
//             // Handle empty line error here (you can define is_empty_line() to check for empty lines).
//             free(current_line);
//             free_line_list(line_list); // Free the allocated memory before returning.
//             return;
//         }
//         // Create a new node for the linked list.
//         t_lineNode *new_node = malloc(sizeof(t_lineNode));
//         if (new_node == NULL) {
//             // Handle memory allocation error here.
//             free(current_line);
//             free_line_list(line_list); // Free the allocated memory before returning.
//             return;
//         }
//         new_node->line = current_line;
//         new_node->next = NULL;

//         // Add the new node to the linked list.
//         if (line_list == NULL) {
//             line_list = new_node; // The first node in the list.
//         } else {
//             // Traverse the list to find the last node and append the new node.
//             t_lineNode *current = line_list;
//             while (current->next != NULL) {
//                 current = current->next;
//             }
//             current->next = new_node;
//         }
//     }

//     // Now you have a linked list containing the lines of the scene data.
//     // You can process the data as needed and free the linked list when done.

//     // Remember to free the allocated memory and close the file.
//     free_line_list(line_list);
//     if (close(fd) == -1) {
//         printf("Error\nCould not close file %s.\n", file);
//         exit(1);
//     }
    
//     get_scene(data);
//     check_scene(data);
// }






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
