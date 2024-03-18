/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-cola <ede-cola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:42:14 by ede-cola          #+#    #+#             */
/*   Updated: 2024/03/18 18:02:27 by ede-cola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

void	ft_print_str(char *str, siginfo_t *info)
{
	ft_printf("%s\n", str);
	free(str);
	kill(info->si_pid, SIGUSR2);
}

void	handler(int signum, siginfo_t *info, void *context)
{
	static char	c;
	static int	i;
	static char	*str;

	(void)context;
	if (signum == SIGUSR1)
		c |= (1 << i);
	i++;
	if (i == 8)
	{
		if (c == '\0')
		{
			ft_print_str(str, info);
			i = 0;
			str = NULL;
			return ;
		}
		if (!str)
			str = ft_strdup_str(&c);
		else
			str = ft_strjoin_str(str, &c);
		i = 0;
		c = 0;
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
