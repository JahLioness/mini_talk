/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-cola <ede-cola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:42:14 by ede-cola          #+#    #+#             */
/*   Updated: 2024/03/15 16:57:25 by ede-cola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

void	handler(int signum, siginfo_t *info, void *context)
{
	static char	c;
	static int	i;

	(void)context;
	if (signum == SIGUSR1)
		c |= (1 << i);
	i++;
	if (i == 8)
	{
		if (c == '\0')
		{
			ft_printf("\n");
			kill(info->si_pid, SIGUSR2);
			i = 0;
			return ;
		}
		else
		{
			ft_printf("%c", c);
			i = 0;
			c = 0;
		}
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	int					pid;
	struct sigaction	act;

	pid = getpid();
	ft_printf("Server PID: %d\n", pid);
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = &handler;
	sigemptyset(&act.sa_mask);
	if (sigaction(SIGUSR1, &act, NULL) < 0)
		return (-1);
	if (sigaction(SIGUSR2, &act, NULL) < 0)
		return (-1);
	while (1)
	{
		pause();
	}
	return (0);
}
