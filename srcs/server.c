/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albzamor <albzamor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:50:45 by albzamor          #+#    #+#             */
/*   Updated: 2021/11/04 17:03:03 by albzamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int	main()
{
	printf("holi");
	while (1)
	{
		printf(" ... esperando algo\n");
		sleep(2);
		printf("      ...  algo ...\n");
		sleep(1);
	}
	return(0);
}
