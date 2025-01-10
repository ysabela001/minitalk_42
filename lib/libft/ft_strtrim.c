/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytavares <ytavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:03:55 by ytavares          #+#    #+#             */
/*   Updated: 2024/11/01 17:57:54 by ytavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*result;
	size_t		start;
	size_t		end;
	size_t		len_s;

	if (!s1 && !set)
		return (NULL);
	len_s = ft_strlen(s1);
	start = 0;
	while (start < len_s && ft_strchr(set, s1[start]))
		start++;
	end = len_s - 1;
	while (end > start && ft_strchr(set, s1[end]))
		end--;
	result = (char *)malloc(sizeof(char) * (end - start + 2));
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1 + start, end - start + 2);
	return (result);
}
