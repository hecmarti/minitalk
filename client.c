/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecmarti <hecmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:06:34 by hecmarti          #+#    #+#             */
/*   Updated: 2024/05/09 16:37:46 by hecmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
# include <signal.h>

int	ft_morse(int pid, int c)
{
	int	bit;

	bit = 7;
	while (bit != -1)
	{
		if ((c >> bit) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		bit--;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	int				pid;
	unsigned char	*str;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		str = (unsigned char *)argv[2];
		while (*str)
		{
			ft_morse(pid,*str++);
		}
	}
	else
	{
		write(1, "invalid args", 13);
	}
	return (0);
}