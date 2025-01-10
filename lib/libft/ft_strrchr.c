/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytavares <ytavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 16:35:55 by ytavares          #+#    #+#             */
/*   Updated: 2024/11/05 17:24:51 by ytavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last;

	last = NULL;
	while (*s)
	{
		if (*s == (char)c)
		{
			last = (char *)s;
		}
		s++;
	}
	if ((char)c == '\0')
	{
		return ((char *)s);
	}
	return (last);
}
