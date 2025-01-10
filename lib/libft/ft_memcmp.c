/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytavares <ytavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 18:01:01 by ytavares          #+#    #+#             */
/*   Updated: 2024/11/08 12:05:53 by ytavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	size_t			y;

	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	y = 0;
	while (y < n)
	{
		if (ptr1[y] != ptr2[y])
		{
			return (ptr1[y] - ptr2[y]);
		}
		y++;
	}
	return (0);
}
