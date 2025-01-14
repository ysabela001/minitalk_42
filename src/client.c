/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytavares <ytavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 18:40:33 by ytavares          #+#    #+#             */
/*   Updated: 2025/01/13 12:44:28 by ytavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_the_bit_is_recive = FALSE;

void	recive_signal(int sign)
{
	if (sign == SIGUSR1)
		g_the_bit_is_recive = TRUE;
}

void	send_bit_by_bit(int pid, char *str, size_t len_str)
{
	size_t		i_str;
	int			bit_from_caracter;

	i_str = 0;
	while (i_str <= len_str)
	{
		bit_from_caracter = 0;
		while (bit_from_caracter < 8)
		{
			if ((str[i_str] >> bit_from_caracter) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			bit_from_caracter++;
			usleep(10000);
			while (!g_the_bit_is_recive)
				;
			g_the_bit_is_recive = FALSE;
		}
		i_str++;
	}
}

int	main(int argc, char **argv)
{
	int					pid_server;
	struct sigaction	sign_client;

	if (argc == 3)
	{
		pid_server = ft_atoi(argv[1]);
		sign_client.sa_handler = recive_signal;
		sign_client.sa_flags = 0;
		sigemptyset(&sign_client.sa_mask);
		sigaction(SIGUSR1, &sign_client, NULL);
		send_bit_by_bit(pid_server, argv[2], ft_strlen(argv[2]));
	}
	else
		ft_putstr_fd("Something is missing: ./client, <PID>, <message>\n", 1);
	return (0);
}
