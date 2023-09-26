/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 12:07:41 by hkahsay           #+#    #+#             */
/*   Updated: 2023/09/26 11:57:27 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 	int	word;
	int	flag;

	word = 0;
	flag = 0;
	if (!s)
		return (0);
	while (*s)
	{
		if (*s != c && flag == 0)
		{
			flag = 1;
			word++;
		}
		else if (*s == c)
			flag = 0;
		s++;
	}		
	return (word); */
	
static int	ft_count(char const *s, char c)
{

	int n;
	int i;
	
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

char	**ft_split(const char *s, char c)
{
	size_t		i;
	size_t		j;
	int			start;
	char		**split;
	int         size;
	int         n_words;
	
	if (!s)
		return (NULL);
	n_words = ft_count(s, c) + 2;
	split = malloc(n_words * sizeof(char *));
	if (!split)
		return (NULL);
	i = 0; // Current index in s
	j = 0; // Current index in split
	start = 0; // Start of the current string
	size = ft_strlen(s);
	while (i < size)
	{
		if (s[i] == c) {
			split[j] = ft_str_size(s, start, i);
			++j;
			start = i + 1;
		}
		++i;
	}
	split[j] = ft_str_size(s, start, i);
	split[j + 1] = NULL;
	return (split);
}

