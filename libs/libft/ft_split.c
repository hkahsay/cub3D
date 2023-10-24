/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 12:07:41 by hkahsay           #+#    #+#             */
/*   Updated: 2023/10/24 18:32:15 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(char const *s, char c)
{
	int	n;
	int	i;

	n = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			++n;
		++i;
	}
	return (n);
}

static char	*ft_str_size(const char *str, int start, int end)
{
	char	*dst;
	int		i;

	i = 0;
	dst = malloc((end - start + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	while (start < end)
		dst[i++] = str[start++];
	dst[i] = '\0';
	return (dst);
}

static char	**allocate_split_array(int size)
{
	char	**split;

	split = malloc(size * sizeof(char *));
	if (!split)
		return (NULL);
	return (split);
}

static void	populate_split_array(char **split, const char *s, char c)
{
	size_t	i;
	size_t	j;
	int		start;
	int		size;

	i = 0;
	j = 0;
	start = 0;
	size = ft_strlen(s);
	while (i < size)
	{
		if (s[i] == c)
		{
			split[j] = ft_str_size(s, start, i);
			++j;
			start = i + 1;
		}
		++i;
	}
	split[j] = ft_str_size(s, start, i);
	split[j + 1] = NULL;
}



char	**ft_split(const char *s, char c)
{
	int		n_words;
	char	**split;

	if (!s)
		return (NULL);
	n_words = ft_count(s, c) + 2;
	split = allocate_split_array(n_words);
	if (!split)
		return (NULL);
	populate_split_array(split, s, c);
	return (split);
}





// char	**ft_split(const char *s, char c)
// {
// 	size_t	i;
// 	size_t	j;
// 	int		start;
// 	char	**split;
// 	int		size;
// 	int		n_words;

// 	if (!s)
// 		return (NULL);
// 	n_words = ft_count(s, c) + 2;
// 	split = malloc(n_words * sizeof(char *));
// 	if (!split)
// 		return (NULL);
// 	i = 0;
// 	j = 0;
// 	start = 0;
// 	size = ft_strlen(s);
// 	while (i < size)
// 	{
// 		if (s[i] == c)
// 		{
// 			split[j] = ft_str_size(s, start, i);
// 			++j;
// 			start = i + 1;
// 		}
// 		++i;
// 	}
// 	split[j] = ft_str_size(s, start, i);
// 	split[j + 1] = NULL;
// 	return (split);
// }
