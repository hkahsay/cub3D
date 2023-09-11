#include "../parser.h"
#include "../cub3d.h"



int ft_isdigit_strict(const char *str)
{
    if (*str == '-' || *str == '+')
        str++;
    
    while (*str)
    {
        if (!ft_isdigit(*str))
            return (0);
        str++;
    }
    return (1);
    
}

void    empty_color(char *str)
{
   if(!str)
    {
        printf(RED"Error: color is not set.\n"RESET);
        exit(EXIT_FAILURE);
    }
}

// static void    skip_spaces(char *str, int i)
// {
//     while (is_space(str[i]))
//         ++i;
// }