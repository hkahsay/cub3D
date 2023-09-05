#include "../parser.h"
#include "../cub3d.h"

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

void    emprty_str(char *str)
{
   if(!str)
    {
        printf("Error: color is not set.\n\n");
        exit(1);
    }
}