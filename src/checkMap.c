#include "../cub3d.h"
// #include "../parser.h"

#include <string.h>

int is_map(char *line)
{
    int i;
    int valid_char;
    
    i = 0;
    valid_char = 0; // Initialize valid_char to 0
    if (ft_check_char(line, '1') == 1)
    {
        // Check if the character is not one of the valid map characters
        if (!ft_strchr("01NSEW \n\t\v\f\r", line[i]))
            return (0);
        if (line[i] == '1' || line[i] == ' ')
            valid_char = 1; // Set valid_char to 1 if '1' is found
    }
    return (valid_char); // Return the value of valid_char
}

void check_map_elm(t_sceneData *data)
{
    int i;
    int found;

    i = 0;
    found = 0;
    while (data->scene[i] != NULL)
    {
        if (is_map(data->scene[i]) == 0)
            data->elm++;
        else if(is_map(data->scene[i]) == 1)
        {
            found = 1;
            break;
        }
        i++;
    }
    if (!found)
    {
        printf("%s%s%s\n", RED, "Map should be the last element", RESET);
        exit(EXIT_FAILURE);
    }
}


void    check_map_validty(char **map, int m_height, int row, int col)
{
   
    if (row < 0 || row >= m_height || col < 0 || col >= (int)ft_strlen(map[row]))
    {
        printf(RED"Invalid map: (%d, %d) is outside of the map or map is not surrounded by 1.\n"RESET, row, col);
        exit(EXIT_FAILURE);
    }
    if (map[row][col] == ' ')
    {
        // map[row][col] = '1';
        printf(RED"Invalid map: (%d, %d) is an empty space.\n"RESET, row, col);
        exit(EXIT_FAILURE);
    }
}

void    check_map_valid_characters(char **map)
{
    int i;
    int j;
    int start_postion;

    i = -1;
    start_postion = 0;
    while (map[++i])
    {
        j = -1;
        while (map[i][++j])
        {
            if (!ft_strchr("01NSEW ", map[i][j]))
                ft_error_msg(RED"Invalid map: Invalid character found in the map."RESET);
            if(ft_strchr("NSEW", map[i][j]))
                start_postion++;
        }
    }
    if(start_postion != 1)
        ft_error_msg(RED"Invalid map: There should be exactly one starting point (NSWE)."RESET);
}



void    check_map(t_map *map_data)
{
    int i;
    int j;

    i = 0;
    while (i < map_data->m_height)
    {
        j = 0;
        while (map_data->map[i][j])
        {
            if (map_data->map[i][j] == '0' || ft_strchr("NSEW", map_data->map[i][j]))
            {
                check_map_validty(map_data->map, map_data->m_height, i, j - 1);
                check_map_validty(map_data->map, map_data->m_height, i, j + 1);
                check_map_validty(map_data->map, map_data->m_height, i - 1, j);
                check_map_validty(map_data->map, map_data->m_height, i + 1, j);
            }
            j++;
        }
        i++;
    }
}
