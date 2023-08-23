#include "../cub3d.h"

static int  find_length(char *str, char *charset)
{
	int count;

	count = 0;
	while (*str)
		if (!ft_strchr(charset, *str++))
			count++;
	return (count);
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
	return (strs);
}