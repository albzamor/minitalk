/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albzamor <albzamor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 16:05:11 by albzamor          #+#    #+#             */
/*   Updated: 2021/06/07 16:22:19 by albzamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	size;
	size_t	i;

	i = 0;
	if (s == NULL)
		return ;
	size = ft_strlen(s);
	while (i < size)
	{
		write(fd, &s[i], 1);
		i++;
	}
}
