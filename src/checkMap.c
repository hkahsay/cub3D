#include "../cub3d.h"
#include "../parser.h"

#include <string.h>

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

int is_map(char *line)
{
    int i = 0;
    
    // Check if the line starts with '1' (assuming it's a map element)
    if (ft_check_char(line, '1') == 1)
    {
        while (line[i])
        {
            // Check if the character is not one of the valid map characters
            if (!ft_strchr("01NSEW \n\t\v\f\r", line[i]))
            {
                // Invalid character found in the map line
                printf("%s ismap:\n", line);
                // printf("%s%s%s\n", RED, "Invalid map", RESET);
                return 0;
            }
            printf("%s ismap:\n", line);
            return 1; // Valid map line
            // i++;
            line++;
        }
    }
    return 0; // Not a map line
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