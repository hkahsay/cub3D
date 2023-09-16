#include "../../cub3d.h"
#include "../../parser.h"

#include <string.h>

size_t get_width(char **maplines)
{
    size_t max_width;
    size_t length;
    int i;
    int j;
    
    max_width = 0;
    i = -1;
    while (maplines[++i])
    {
        length = 0;
        j = -1;
        while (maplines[i][++j])
        {
            if (maplines[i][j] == '\t')
                length += 4; // Tab character adds 4 to the length
            else
                length++;
        }
        if (length > max_width)
            max_width = length;
    }
    return max_width;
}

static void map_allocate_memory(t_sceneData *data, int mapStartedIndex)
{
        // Allocate memory for the entire map_data.map array
    data->map_data.map = malloc(sizeof(char *) * (data->map_data.m_height + 1)); // +1 for the NULL terminator
    if (!data->map_data.map)
    {
        ft_error_msg(RED"Error: Dynamic allocation failed."RESET);
        free_map_data(&data->map_data);
    }
    data->map_data.m_width = get_width(&data->scene[mapStartedIndex]);
    printf("data->map_data.m_width: %d\n", data->map_data.m_width);
}

void get_map(t_sceneData *data, int mapStartedIndex)
{
    int i;

    i = 0;
    map_allocate_memory(data, mapStartedIndex);
    printf("data->map_data.m_height: %d\n", data->map_data.m_height);
    printf("mapStartedIndex %d\n", mapStartedIndex);
    while (i < data->map_data.m_height)
    {
        data->map_data.map[i] = malloc(sizeof(char) * (data->map_data.m_width + 1));
        if (!data->map_data.map[i])
        {
            ft_error_msg(RED"Error: Dynamic allocation failed."RESET);
            free_map_data(&data->map_data);
        }
        strcpy(data->map_data.map[i], data->scene[mapStartedIndex + i]);
        // printf("data->map_data.map[%d]: %s\n", i, data->map_data.map[i]);
        // printf("mapStartedIndex + i: %d\n", mapStartedIndex + i);
        i++;
    }
    // empty_line_error(data);
    data->map_data.map[data->map_data.m_height] = NULL;
    check_map_valid_characters(data->map_data.map);
}


// void get_map(t_sceneData *data, int mapStartedIndex)
// {
//     int i;

//     i = 0;
//     map_allocate_memory(data, mapStartedIndex);
//     // printf("data->map_data.m_height: %d\n", data->map_data.m_height);
//     // printf("mapStartedIndex %d\n", mapStartedIndex);
//     while (i < data->map_data.m_height)
//     {
//         // printf("2\n");
//         data->map_data.map[i] = malloc(sizeof(char) * (data->map_data.m_width + 1));
//         // printf("3\n");
//         if (!data->map_data.map[i])
//         {
//             // printf("4\n");
//             ft_error_msg(RED"Error: Dynamic allocation failed."RESET);
//             // printf("5\n");
//             free_map_data(&data->map_data);
//             // printf("6\n");
//         }
//         // printf("7\n");
//         strcpy(data->map_data.map[i], data->scene[mapStartedIndex + i]);
//         // printf("data->map_data.map[%d]: %s\n", i, data->map_data.map[i]);
//         // printf("mapStartedIndex + i: %d\n", mapStartedIndex + i);
//         printf("8\n");
//         i++;
//         // printf("9\n");
//     }
//     // printf("10\n");
//     // empty_line_error(data);
//     printf("11\n");
//     data->map_data.map[data->map_data.m_height] = NULL;
//     // printf("12\n");
//     // Check for valid characters in the map
//     check_map_valid_characters(data->map_data.map);
//     // printf("13\n");
// }

// char **cpy_map(char **scene, int *height) 
// {
//     char **strs;
//     int i = 0;

//     strs = malloc(sizeof(char *));
//     if (!strs) {
//         exit(EXIT_FAILURE); // Change EXIT_SUCCESS to EXIT_FAILURE
//     }

//     while (scene[i]) {
//         strs = ft_realloc(strs,
//                 (i + 1) * sizeof(char *),
//                 (i + 2) * sizeof(char *));
//         if (!strs) {
//             exit(EXIT_FAILURE); // Change EXIT_SUCCESS to EXIT_FAILURE
//         }

//         strs[i] = strdup(scene[i]);
//         // printf("Loop iteration: %d\n", i);
//         i++;
//     }

//     strs[i] = NULL;
//     *height = i;
//     //  printf("Copied map contents:\n");
//     // for (int j = 0; j < i; j++) {
//     //     printf("%s\n", strs[j]);
//     // }
//     return strs;
// }