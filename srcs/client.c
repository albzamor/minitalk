/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albzamor <albzamor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:50:39 by albzamor          #+#    #+#             */
/*   Updated: 2021/11/06 13:49:34 by albzamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"


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
	pid_t	pid;

	pid = ft_atoi(argv[1]);

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		ft_kill(pid, argv[2]);

	}
	else
	{
		ft_putstr_fd("Arguments Error", 1);
		return (-1);
	}
	return (0);
}

