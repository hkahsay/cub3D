#include "../../cub3d.h"

void free_map_data(t_map *map_data)
{
    if (map_data->map)
    {
        for (int i = 0; i < map_data->m_height; i++)
        {
            free(map_data->map[i]); // Free each row of the map
        }
        free(map_data->map); // Free the array of row pointers
    }
    // reset the height and width
    map_data->m_height = 0;
    map_data->m_width = 0;
}

void    free_strs_array(char **strs)
{
    int i;

    i = 0;
    while (strs[i])
    {
        free(strs[i]);
        i++;
    }
    free(strs);
}

void free_line_list(t_lineNode *head)
{
    while (head != NULL)
    {
        t_lineNode *temp = head;  // Store the current node in a temporary variable.
        head = head->next;       // Move to the next node.
        free(temp->line);        // Free the line stored in the node.
        free(temp);              // Free the node itself.
    }
}