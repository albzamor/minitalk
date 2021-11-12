/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albzamor <albzamor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:50:45 by albzamor          #+#    #+#             */
/*   Updated: 2021/11/12 12:44:36 by albzamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

/**
 * each sigusR1 signal  is recived enter here
 *
 * @param i static wait until 8 (8 bits per character);
 * @param sig signal numeric value (fixed)
 * @param character ==  character = character | (sig == SIGUSR2);
*/
void	ft_sigaction(int sig, siginfo_t *siginfo, void *context)
{
	static int				i;
	static unsigned char	character;

	(void) context;
	character |= (sig == SIGUSR2);
	if (++i == 8)
	{
		i = 0;
		ft_putchar_fd(character, 1);
		character = 0;
	}
	else
	{
		character <<= 1;
	}
	usleep(100);
	kill (siginfo->si_pid, SIGUSR1);
}

/**
 * @param signal_struct to change handler since signal to sigaction
*/

int	main(void)
{
	struct sigaction	signal_struct;

	signal_struct.sa_flags = SA_SIGINFO;
	signal_struct.__sigaction_u.__sa_sigaction = ft_sigaction;
	ft_putstr_fd("Process ID(PID): ", 1);
	ft_putnbr_fdnl(getpid(), 1);
	ft_putstr_fdnl("", 1);
	sigaction(SIGUSR1, &signal_struct, 0);
	sigaction(SIGUSR2, &signal_struct, 0);
	while (1)
		usleep(1);
	return (0);
}
