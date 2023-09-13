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
        ft_error_msg(RED"Error\n color is not set."RESET);
    }
}

void empty_reso(char *str)
{
    if(!str)
    {
        ft_error_msg(RED"Error\n resolution is not set."RESET);
    }
}

// static void    skip_spaces(char *str, int i)
// {
//     while (is_space(str[i]))
//         ++i;
// }