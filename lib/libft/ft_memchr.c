/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytavares <ytavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:22:23 by ytavares          #+#    #+#             */
/*   Updated: 2024/10/21 17:56:14 by ytavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			y;
	unsigned char	*ptr;

	y = 0;
	ptr = (unsigned char *)s;
	while (y < n)
	{
		if (ptr[y] == (unsigned char)c)
		{
			return ((void *)&ptr[y]);
		}
		y++;
	}	
	return (NULL);
}
