/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytavares <ytavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:44:45 by ytavares          #+#    #+#             */
/*   Updated: 2024/11/08 12:54:26 by ytavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	str_len;
	char	*duplicate_str;

	str_len = ft_strlen(str);
	duplicate_str = (char *)malloc((str_len + 1) * sizeof(char));
	if (duplicate_str == NULL)
		return (NULL);
	ft_strlcpy(duplicate_str, str, str_len + 1);
	return (duplicate_str);
}
