/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 16:40:19 by hkahsay           #+#    #+#             */
/*   Updated: 2023/10/24 17:20:22 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

/*int	main()
{
	char c[20] = "-";
	char b[20]={'P','r','o','g','r','a','m','\0'};


	printf ("%d \n", ft_strlen(c));
	printf("Length of string %lu \n",strlen(b));
}*/