/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albzamor <albzamor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:50:45 by albzamor          #+#    #+#             */
/*   Updated: 2021/11/05 18:57:03 by albzamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

/**
 * each sigusR1 signal  is recived enter here
 *
 * @param i static wait until 8 (8 bits per character);
 * @param sig signal numeric value (fixed)
 * @param c  |= Assignment with binary OR
 * 			 character = character | (sig == SIGUSR2);
*/
void	ft_sigusr_handler(int sig)
{
	static int		i;
	static unsigned char	character;

	character |= (sig == SIGUSR2);
	character = character | (sig == SIGUSR2);

	if (++i == 8)
	{
		i = 0;
		ft_putchar_fd(character, 1);
		character = 0;
	}
	else
		character <<= 1;
}


/**
 * Server shows PID
 *
 * @param i;
 *
*/

int	main(void)
{
	ft_putstr_fd("Process ID(PID): ", 1);
	ft_putnbr_fdnl(getpid(), 1);
	printf("holi");
	ft_putstr_fd("el caracter es: ", 1);
	while (1)
	{
		signal(SIGUSR1, &ft_sigusr_handler);
		signal(SIGUSR2, &ft_sigusr_handler);
		//printf(" ... esperando algo\n");
		//sleep(2);
		//printf("      ...  algo ...\n");
		//sleep(1);
	}
	return (0);
}
