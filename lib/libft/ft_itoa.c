/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytavares <ytavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:04:26 by ytavares          #+#    #+#             */
/*   Updated: 2024/11/04 15:47:58 by ytavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static unsigned int	get_len(int num)
{
	unsigned int	len_num;

	len_num = 0;
	if (num == 0)
		return (1);
	if (num < 0)
		len_num = 1;
	while (num != 0)
	{
		num = num / 10;
		len_num++;
	}
	return (len_num);
}

char	*ft_itoa(int n)
{
	char	*int_to_string;
	int		result_len_n;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	result_len_n = get_len(n);
	int_to_string = (char *)malloc(result_len_n + 1);
	if (!int_to_string)
		return (NULL);
	int_to_string[result_len_n] = '\0';
	if (n < 0)
	{
		int_to_string[0] = '-';
		n = -n;
	}
	if (n == 0)
	{
		int_to_string[0] = '0';
	}
	while (n > 0)
	{
		int_to_string[--result_len_n] = (n % 10) + '0';
		n = n / 10;
	}
	return (int_to_string);
}
