/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytavares <ytavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 18:59:51 by ytavares          #+#    #+#             */
/*   Updated: 2024/11/04 16:15:21 by ytavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len_s;
	char	*new_str;
	size_t	i;

	if (!s || !f)
		return (NULL);
	len_s = ft_strlen(s);
	new_str = (char *)malloc(len_s + 1);
	if (!new_str)
		return (NULL);
	i = 0;
	while (i < len_s)
	{
		new_str[i] = f(i, s[i]);
		i++;
	}
	new_str[len_s] = '\0';
	return (new_str);
}
