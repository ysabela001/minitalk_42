/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytavares <ytavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 19:07:52 by ytavares          #+#    #+#             */
/*   Updated: 2024/11/08 12:48:07 by ytavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str);

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	y;
	size_t	x;

	y = 0;
	x = 0;
	if (!big && !little)
		return (NULL);
	if (*little == '\0')
		return ((char *)big);
	while (y < len && big[y] != '\0')
	{
		x = 0;
		while (x < ft_strlen(little) && y + x < len && big[y + x] != '\0'
			&& big[y + x] == little[x])
			x++;
		if (x == ft_strlen(little))
			return ((char *)&big[y]);
		y++;
	}
	return (NULL);
}
