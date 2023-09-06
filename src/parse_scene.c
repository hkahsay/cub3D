#include "../cub3d.h"
#include "../parser.h"
#include <string.h>


int lineContainsNonWhitespace(const char *line) {
    int k;

    k = 0;
    while(line[k] != '\0') {
        if (!is_space((unsigned char)line[k])) {
            return 1; // Found a non-whitespace character
        }
        k++;
    }
    return 0; // No non-whitespace characters found
}

void get_scene(t_sceneData *data)
{
    int i = 0;
    int mapStartedIndex = 0;
    int mapstarted = 0;
    int shouldIncrementHeight = 1; // Flag to control height incrementing

	check_map_elm(data);
    while (data->scene[i] != NULL)
    {
        // printf("Loop iteration: %d\n", i);
        if (mapstarted == 0)
        {
            if (is_map(data->scene[i]) == 1)
            {
                mapStartedIndex = i;
                // printf("map is started at index %d\n", mapStartedIndex);
                mapstarted = 1;
            }
        
        }
        if (mapstarted == 1 && shouldIncrementHeight == 1)
        {
            printf("data->scene[i][0]vv: %c\n", data->scene[i][0]);
            // printf("map is ended at index %d\n", i);
            data->map_data.m_height++;
            // printf("data->scene[i], data->map_data_field %s%s\n", data->scene[i], data->map_data_field.map[i]);
            //get_map(data, &data->map_data_field);
            // printf("data->map_data_field.map[i]: %s\n", data->map_data_field.map[i]);
        }
        else if (mapstarted == 1)
        {
             // Check if the line contains any non-whitespace characters
            // int containsNonWhitespace = 0;
            if (lineContainsNonWhitespace(data->scene[i]) == 0)
            {
                shouldIncrementHeight = 0;
                /* code */
            }
            
            // containsNonWhitespace = lineContainsNonWhitespace(data->scene[i]);
        }
        else
        {

            if (data->scene[i][0] != '\0')
            {
                // printf("data->scene[i][0]: %c\n", data->scene[i][0]);
               
                char *identifier = strtok(data->scene[i], " "); // Assuming identifiers are followed by a space
                char *dataLine = strtok(NULL, ""); // Remaining part of the line
                // printf("data->scene[i], data->scene[i + 1]: %s, %s\n", data->scene[i], data->scene[i + 1]);
                // printf("identifier: %s\n", identifier);
                // printf("dataline: %s\n", dataLine);
                
                get_file(identifier, dataLine, data);
                // miss_color_set(data, "floor");
                // miss_color_set(data, "ceiling");
                // printf("data->scene[i]: %s\n", data->scene[i]); 
                // printf("Loop iteration: %d\n", i);
                
                // printf("identifier after get_file: %s\n", identifier);
                data->elm++;
            }
        }
           
        // printf("data->scene[i]: %s\n", data->scene[i]); 
        // printf("Loop iteration: %d\n", i);
        i++; // Move to the next identifier/data pair
    }
  
    get_map(data, mapStartedIndex);
    
    print_map(&data->map_data);

    // printf("data->win_mlx: %s\n", (char *) data->win_mlx);
    // printf("data->texture->path: %s\n", data->north_texture.path);

}


// void get_scene(t_sceneData *data) {
//     int i = 0;
//     int mapStartedIndex = 0;
//     int mapstarted = 0;
//     int shouldIncrementHeight = 1; // Flag to control height incrementing
//     int inMapSection = 0; // Flag to indicate whether we are inside the map section

//     check_map_elm(data);

//     while (data->scene[i] != NULL) {
//         if (mapstarted == 0) {
//             if (is_map(data->scene[i]) == 1) {
//                 mapStartedIndex = i;
//                 mapstarted = 1;
//             }
//         }

//         if (mapstarted == 1) {
//             if (!inMapSection) {
//                 // Check if we are entering the map section
//                 inMapSection = 1;
//             } else {
//                 // Check if the line contains any non-whitespace characters
//                 if (lineContainsNonWhitespace(data->scene[i]) == 0) {
//                     shouldIncrementHeight = 0;
//                 }
//             }
//         }

//         // Check if we are exiting the map section
//         if (inMapSection && data->scene[i][0] == '\0') {
//             inMapSection = 0;
//         }

//         if (mapstarted == 1 && shouldIncrementHeight == 1) {
//             data->map_data.m_height++;
//         }

//         i++; // Move to the next line
//     }

//     // After scanning the map, check if it's valid based on the presence of empty lines within the map section
//     if (data->map_data.m_height < 1) {
//         printf(RED "Invalid map: No map data found.\n" RESET);
//         exit(EXIT_FAILURE);
//     }

//     get_map(data, mapStartedIndex);
//     print_map(&data->map_data);
// }
