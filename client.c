/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-cola <ede-cola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:49:09 by ede-cola          #+#    #+#             */
/*   Updated: 2024/03/05 16:32:20 by ede-cola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

static	void	ft_server_confirmation(int signum)
{
	if (signum == SIGUSR1)
		g_sig = 1;
	if (signum == SIGUSR2)
	{
		ft_printf("Message received by server\n");
		exit (0);
	}
}

void	ft_send_char(int pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		c >>= 1;
		usleep(100);
		i++;
		while (g_sig == 0)
			sleep(1);
		g_sig = 0;
	}
}

int	main(int ac, char **av)
{
	int					pid;
	int					i;
	struct sigaction	act;

	if (ac != 3)
	{
		ft_printf("Format attendu: ./client [PID] [message]\n");
		return (1);
	}
	act.sa_flags = SA_SIGINFO;
	act.sa_handler = &ft_server_confirmation;
	sigemptyset(&act.sa_mask);
	if (sigaction(SIGUSR1, &act, NULL) < 0)
		exit(1);
	if (sigaction(SIGUSR2, &act, NULL) < 0)
		exit(1);
	pid = ft_atoi(av[1]);
	i = 0;
	while (av[2][i])
	{
		ft_send_char(pid, av[2][i]);
		i++;
	}
	ft_send_char(pid, '\0');
	return (0);
}
