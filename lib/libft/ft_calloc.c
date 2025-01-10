/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytavares <ytavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:44:16 by ytavares          #+#    #+#             */
/*   Updated: 2024/11/07 14:47:34 by ytavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	result_size;

	if (nmemb != 0 && size != 0 && nmemb > (size_t) - 1 / size)
		return (NULL);
	result_size = nmemb * size;
	ptr = malloc(result_size);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, 0, result_size);
	return (ptr);
}
