#include "../../cub3d.h"


// Function to trim whitespace and newline characters from both ends of a string
// char *trim(char *str)
// {
//     while (isspace(*str)) {
//         str++;
//     }
    
//     char *end = str + ft_strlen(str) - 1;
//     while (end > str && isspace(*end)) {
//         end--;
//     }
    
//     *(end + 1) = '\0';
    
//     return str;
// }

int	ft_check_char(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
        {
            // printf("ft_check_char: %c\n", str[i]);
			return (1);// Character found
        }
		i++;
	}
	return (0);// Character not found
}

int is_space(char c)
{
    if (c == 32 || (c >= 9 && c <= 13) || c == '\0')
        return(1);
    return(0);
}

void    skip_spaces(char *str)
{
	int i;

	i = 0;
    while (is_space((str[i])))
        i++;
}



int ft_strcmp(const char *s1, const char *s2)
{
	int i = 0;
	while (s1[i] == s2[i]) {
		if (s1[i] == '\0') {
			return 0;
		}
		i++;
	}
	return (s1[i] - s2[i]);
}

static int  find_length(char *str, char *charset)
{
	int count;

	count = 0;
	while (*str)
		if (!ft_strchr(charset, *str++))
			count++;
	return (count);
}

void	*ft_realloc(void *ptr, size_t orig_size, size_t new_size)
{
	void	*new_ptr;

	new_ptr = 0;
	if (new_size == 0)
		free(ptr);
	else if (!ptr)
	{
		if (!(new_ptr = malloc(new_size)))
			return (0);
	}
	else if (new_size <= orig_size)
		return (ptr);
	else if (ptr && new_size > orig_size)
	{
		if (!(new_ptr = malloc(new_size)))
			return (0);
		ft_memcpy(new_ptr, ptr, orig_size);
		free(ptr);
	}
	return (new_ptr);
}

char	*ft_strncpy(char *dest, char *src, size_t n)
{
	char *sav_dest;
	char *sav_src;

	sav_dest = dest;
	sav_src = src;
	if (n != 0)
	{
		while (1)
		{
			if ((*sav_dest++ = *sav_src++) == 0)
			{
				while (--n != 0)
					*sav_dest++ = 0;
				break ;
			}
			if (--n == 0)
				break ;
		}
	}
	return (dest);
}

static void		import_str(char **dest, char *src, int start, int end)
{
	if (!(*dest = malloc(((end - start + 1) * sizeof(char)))))
		return ;
	ft_strncpy(*dest, src, end - start);
	(*dest)[end - start] = '\0';
}

char			**ft_split2(char *str, char *charset)
{
	char	**strs;
	int		i;
	int		j;
	int		k;

	j = 0;
	k = 0;
	if (str == 0)
		return (0);
	if (!(strs = malloc((find_length(str, charset) + 1) * sizeof(char *))))
		return (0);
	while (str[j] != '\0')
	{
		i = j;
		while (!ft_strchr(charset, str[j]) && str[j] != '\0')
			j++;
		if (i != j)
			import_str(&strs[k++], &str[i], i, j);
		else
			j++;
	}
	strs[k] = 0;
	// printf("ft_split strs[0]: %s\n", strs[0]);
	return (strs);
}

// static void    skip_spaces(char *str, int i)
// {
//     while (is_space(str[i]))
//         ++i;
// }