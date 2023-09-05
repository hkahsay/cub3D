#include "../cub3d.h"
#include "../parser.h"

#include <string.h>

void    print_map(t_map *map_data)
{
    int i;

    i = 0;
    while (i < map_data->m_height)
    {
        printf("map_data->map[%d]: %s\n", i, map_data->map[i]);
        i++;
    }
}

size_t  get_width(char **strlines)
{
    size_t max_width;
    size_t  length;
    int i;
    int j;


    max_width = 0;
    i = 0;
    while (strlines[i])
    {
        j = 0;
        length = 0;
        while (strlines[i][j])
        {
            if (ft_strcmp(&strlines[i][i], "\t") == 0)//strlines[i][j] == '/t'
                length += 4;
            else
                length++;
            // length = ft_strlen(strlines[i]);
            j++;
        }
        if (length > max_width)
            max_width = length;
        i++;
    }
    return (max_width);
}

void check_map_elm(t_sceneData *data)
{
    int i;

    i = 0;
    while (data->scene[i] != NULL)
    {
        if (is_map(data->scene[i]) == 0)
        {
            data->elm++;
            printf("elm: %d\n", data->elm);
        }
        else if(is_map(data->scene[i]) == 1)
            break;
        i++;
    }
    if (data->elm != 6)
    {
        printf("%s%s%s\n", RED, "Invalid map", RESET);
        exit(1);
    }
    printf("elm: %d\n", data->elm);
    
}



int is_map(char *line)
{
    int i = 0;
    int valid_char = 0; // Initialize valid_char to 0

    // Check if the line starts with '1' (assuming it's a map element)
    if (ft_check_char(line, '1') == 1)
    {
        // while (line[i])
        // {
            // Check if the character is not one of the valid map characters
            if (!ft_strchr("01NSEW \n\t\v\f\r", line[i]))
            {
                // Invalid character found in the map line
                // printf("%s ismap:\n", line);
                return 0;
            }
            
            // Move this return statement outside of the loop
            if (line[i] == '1') {
                valid_char = 1; // Set valid_char to 1 if '1' is found
            }
            // printf("%s ismap:\n", line);
            // printf("valid_char: %d\n", valid_char);
            printf("ismap iterations %d\n", i);

        //     i++;
        // }
    }

    return valid_char; // Return the value of valid_char
}



int    check_wall(char *line)
{
    int i;

    i = 0;
    while (line[i])
    {
        if (line[i] != '1' && !is_space(line[i]))
            return(1);
        i++;
    }
    return(0);
    
}

char **cpy_map(char **scene, int *height) 
{
    char **strs;
    int i = 0;

    strs = malloc(sizeof(char *));
    if (!strs) {
        exit(EXIT_FAILURE); // Change EXIT_SUCCESS to EXIT_FAILURE
    }

    while (scene[i]) {
        strs = ft_realloc(strs,
                (i + 1) * sizeof(char *),
                (i + 2) * sizeof(char *));
        if (!strs) {
            exit(EXIT_FAILURE); // Change EXIT_SUCCESS to EXIT_FAILURE
        }

        strs[i] = strdup(scene[i]);
        // printf("Loop iteration: %d\n", i);
        i++;
    }

    strs[i] = NULL;
    *height = i;
    //  printf("Copied map contents:\n");
    // for (int j = 0; j < i; j++) {
    //     printf("%s\n", strs[j]);
    // }
    return strs;
}




// void get_map(t_sceneData *data, t_map *map_data) {
//     map_data->map = cpy_map(data->scene, &map_data->m_height);
//     // map_data->m_width = get_width(map_data->map);
// }

// void extract_map_lines(t_sceneData *data)
// {
//     int i = 0;
//     int map_started = 0;
//     int map_lines_found = 0;
    
//     while (data->scene[i] != NULL)
//     {
//         if (!map_started)
//         {
//             if (is_map(data->scene[i]) == 1)
//             {
//                 printf("Map is started\n");
//                 map_started = 1;
//             }
//         }
        
//         if (map_started)
//         {
//             if (is_map(data->scene[i]) == 1)
//             {
//                 map_lines_found++;
// 				get_map(data, &data->map_data);
//                 // printf("Map Line %d: %s\n", map_lines_found, data->scene[i]);
//             }
//             else
//             {
//                 break; // Exit the loop once map lines are no longer found
//             }
//         }
        
//         i++;
//     }
// 	print_map(&data->map_data);
// }


// int is_map(char *line) {

//     int i;
//     // printf("%s map line0:", line);
//     i = 0;
//     if(ft_check_char(line, '1') == 1)
//     {
//         while (line[i])
//         {
//             if (!ft_strchr("01NSEW \n\t\v\f\r", *line))
//             {
//                 printf("%s ismap:\n", line);
//                 // printf("%s%s%s\n", RED, "Invalid map", RESET);
//                 return 0; 
//             }
//             printf("%s ismap:\n", line);
//             return (1);
//             // i++;
//             line++;
//         }
//     }
//     return (0);
//     // printf("flg: %d\n", flg);
//     // printf("%s map line1:", line);
// }

// int is_map(char *line)
// {
//     int i = 0;
    
//     // Check if the line starts with '1' (assuming it's a map element)
//     if (ft_check_char(line, '1') == 1)
//     {
//         while (line[i])
//         {
//             // Check if the character is not one of the valid map characters
//             if (!ft_strchr("01NSEW \n\t\v\f\r", line[i]))
//             {
//                 // Invalid character found in the map line
//                 printf("%s ismap:\n", line);
//                 // printf("%s%s%s\n", RED, "Invalid map", RESET);
//                 return 0;
//             }
//             // printf("%s ismap:\n", line);
//             return 1; // Valid map line
//             // i++;
//             line++;
//         }
//     }
//     return 0; // Not a map line
// }


// char	**cpy_map(char *scene, char *line, int *height)
// {
// 	char	**strs;
// 	int		i;

// 	i = 0;
//     printf("line: %s\n", line);
// 	strs = malloc(sizeof(char *));
// 	if (!strs)
// 		exit(EXIT_SUCCESS);
// 	while (line)
// 	{
// 		strs = ft_realloc(strs,
// 				(i + 1) * sizeof(char *),
// 				(i + 2) * sizeof(char *));
// 		if (!strs)
// 			exit(EXIT_SUCCESS);
// 		strs[i++] = ft_strdup(line);
// 		free(line);
// 		line = scene[i];
// 	}
// 	// free(line);
// 	strs[i] = NULL;
// 	*height = i;
// 	return (strs);
// }



// void    get_map(t_sceneData *data, char *line, t_map *map_data)
// {
//     map_data->map = cpy_map(data, line, &map_data->m_height);
//     // map_data->m_width = get_width(map_data->map);
// }
    //Intialize map width and height
    // map_data->m_width = get_width(map_data->map);
    // map_data->m_width = ft_strlen(map_data->map);
    // printf("line_map: %s\n", line_map);
    // map_data->m_width = ft_strlen(line_map);

//     map_data->m_height = 0;
//    // data->map_field->m_width = get_width(data->scene);

//    // memmory allocation for map
//     printf("map_data->map: %p\n", map_data->map);
//     map_data->map = (char **)malloc(num_lines * sizeof(char *));
//     if (!map_data->map) {
//         // Handle memory allocation failure
//         exit(EXIT_FAILURE);
//     }
//     if (map_data->map == NULL)
//     {
//         printf("Error: Could not allocate memory for map.\n");
//         exit(1);
//     }
//  // Copy each line of the map into map_data->map
//    for (int i = 0; i < num_lines; i++) {
//         map_data->map[i] = strdup(line_map[i]);
//         if (!map_data->map[i]) {
//             // Handle memory allocation failure
//             exit(EXIT_FAILURE);
//         }
//         map_data->m_height++;
//     }
    
//    printf("map_data->map2: %s\n", map_data->map[0]);
    //get the rest of the map
    // i = 0;
    // printf("data->scene[i]1: %s\n", data->scene[i]);
//    printf("before data->scene[i]: %s\n", data->scene[i]);
    // while (data->scene[i] != NULL)
    // {
    // printf("before data->scene[i]: %s\n", data->scene[i]);
    //     if (data->scene[i][0] == '\0')
    //     {
    //         printf("Error: Empty line in map.\n");
    //         exit(1);
    //     }
    //     else
    //     {

    //         map_data->m_height++;
    //         //resize map array
    //         map_data->map = (char **)realloc(map_data->map, map_data->m_height * sizeof(char *));
    //         // Allocate memory and store the map line
    //         map_data->map[map_data->m_height - 1] = strdup(data->scene[i]);
    //         // printf("data->scene[i]: %s\n", data->scene[i]);
    //     }
    //     i++;
    //     // printf("line_map: %s\n", line_map);
    //     // printf("data->scene[i]: %s\n", data->scene[i]);
    // }
    //     // printf("map_data->map[i]: %s\n", map_data->map[i]);
    // store player position and orientation (N/S/E/W) using map_data->pos
//    printf("data->scene[i]: %s\n", data->scene[i]);
//   }  