/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albzamor <albzamor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:50:39 by albzamor          #+#    #+#             */
/*   Updated: 2021/11/12 11:02:52 by albzamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	ft_sigaction(int sig)
{
	if (sig == SIGUSR1)
	{
		ft_putstr_fd("*", 1);
		usleep(100);
	}
}

static void ft_kill(int pid, char *message, struct sigaction signal_struct)
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
			usleep(100);
			if (character >> bit & 1)
			{
				kill(pid, SIGUSR2);
				sigaction(SIGUSR1, &signal_struct, 0);
			}
			else
			{
				kill(pid, SIGUSR1);
				sigaction(SIGUSR1, &signal_struct, 0);
			}
			usleep(100);
			bit--;
		}
		i++;
	}
	bit = 0;
}
/**
 * @param 1 PID ->server
 * @param 2 message " "
 * @param i;
 *
*/
int	main(int argc,	char **argv)
{
	struct sigaction signal_struct;
	pid_t	pid_server;
	pid_server = ft_atoi(argv[1]);
	ft_putstr_fdnl("Process ID(PID_client): ", 1);
	ft_putnbr_fdnl(getpid(), 1);
	ft_putstr_fd("\nBits Received (\"*\" per bit):\n", 1);
	signal_struct.__sigaction_u.__sa_handler = &ft_sigaction;

	if (argc == 3 && ft_strlen(argv[2]))
	{
		pid_server = ft_atoi(argv[1]);
		ft_kill(pid_server, argv[2], signal_struct);
	}
	else
	{
		ft_putstr_fd("Error", 1);
		return (-1);
	}
	return (0);
}

