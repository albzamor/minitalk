/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albzamor <albzamor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:50:39 by albzamor          #+#    #+#             */
/*   Updated: 2021/11/11 18:03:03 by albzamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	ft_sigaction(int sig, siginfo_t *siginfo, void *context)
{
/* 	(void) sig;
	static int		i;
	i += 1;
	ft_putstr_fd("señal recibida", 1); */
	(void) context;
	(void) siginfo;
	static int	received;

	if (sig == SIGALRM)
		++received;
	else
	{
		ft_putnbr_fd(received, 1);
		ft_putchar_fd('\n', 1);
		exit(0);
	}
	exit(0);

}

static void ft_kill(int pid, char *message)
{
	int		i;
	char	character;
	int		bit;

	i = 0;
	while (message[i] != '\0')
	{
		bit = 7;
		character = message[i];
		while (bit >= 0)
		{
			if (character >> bit & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(100);
			bit--;
		}
		i++;
	}
	bit = 0;
	while (bit < 8)
	{
		kill(pid, SIGUSR1);
		usleep(100);
		bit++;
	}
}



/**
 * Param 1 PID ->server
 * Param 2 message
 *
 * @param i;
 *
*/
int	main(int argc,	char **argv)
{
	struct sigaction signal_struct;
	pid_t	pid_server;

	pid_server = ft_atoi(argv[1]);
	signal_struct.sa_flags = SA_SIGINFO;
	signal_struct.__sigaction_u.__sa_sigaction = &ft_sigaction;


	ft_putstr_fdnl("Process ID(PID_client): ", 1);
	ft_putnbr_fdnl(getpid(), 1);

	if (argc == 3)
	{
		pid_server = ft_atoi(argv[1]);
		ft_kill(pid_server, argv[2]);

	}
	else
	{
		ft_putstr_fd("Arguments Error", 1);
		return (-1);
	}
	ft_putstr_fd("Bites recibidos: ", 1);
	while (1)
	{
		sigaction(SIGUSR1, &signal_struct, 0);
		//printf(" ... esperando algo\n");
		//sleep(2);
		//printf("      ...  algo ...\n");
		//sleep(1);
	}

	return (0);
}

