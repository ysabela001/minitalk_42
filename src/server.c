/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytavares <ytavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:24:44 by ytavares          #+#    #+#             */
/*   Updated: 2025/01/13 16:07:51 by ytavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_client_message	g_msg = {0, 0};

void	signal_manipulation(int signal, siginfo_t *siginfo, void *context)
{
	(void)context;
	if (signal == SIGUSR1)
		g_msg.c &= ~(1 << g_msg.i);
	else if (signal == SIGUSR2)
		g_msg.c |= (1 << g_msg.i);
	g_msg.i++;
	if (g_msg.i == 8)
	{
		if (g_msg.c == '\0')
			write(1, "\n", 1);
		else
			write(1, &g_msg.c, 1);
		g_msg.c = 0;
		g_msg.i = 0;
	}
	if (kill(siginfo->si_pid, SIGUSR1))
		exit(EXIT_FAILURE);
}

int	main(void)
{
	struct sigaction	sign_server;
	int					pid;

	sigemptyset(&sign_server.sa_mask);
	sign_server.sa_sigaction = signal_manipulation;
	sign_server.sa_flags = SA_SIGINFO;
	pid = getpid();
	ft_putstr_fd("*** WELCOME TO YTAVARES'S SERVER ***\n", 1);
	ft_putstr_fd("My server PID is: ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd("\n", 1);
	sigaction(SIGUSR1, &sign_server, NULL);
	sigaction(SIGUSR2, &sign_server, NULL);
	while (TRUE)
		pause();
	return (0);
}
