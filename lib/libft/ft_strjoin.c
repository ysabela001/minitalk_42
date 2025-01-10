/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytavares <ytavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 18:35:03 by ytavares          #+#    #+#             */
/*   Updated: 2024/10/29 19:20:39 by ytavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dest, const char *src, size_t size);

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*junction;
	size_t	lens1;
	size_t	lens2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	junction = (char *)malloc(lens1 + lens2 + 1);
	if (junction == NULL)
		return (NULL);
	ft_strlcpy(junction, s1, lens1 + 1);
	ft_strlcat(junction, s2, lens1 + lens2 + 1);
	return (junction);
}
