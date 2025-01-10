/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytavares <ytavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:35:51 by ytavares          #+#    #+#             */
/*   Updated: 2024/11/05 15:28:51 by ytavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n);

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				a;

	s = (const unsigned char *)src;
	d = (unsigned char *)dest;
	a = 0;
	if (dest == NULL && src == NULL)
	{
		return (NULL);
	}
	while (a < n)
	{
		d[a] = s[a];
		a++;
	}
	return (dest);
}
