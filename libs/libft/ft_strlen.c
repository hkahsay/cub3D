/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 16:40:19 by hkahsay           #+#    #+#             */
/*   Updated: 2023/09/06 13:03:56 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	// printf("str: %s\n", str);

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