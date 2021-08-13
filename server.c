/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanastac <tanastac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 13:25:01 by tanastac          #+#    #+#             */
/*   Updated: 2021/08/13 13:25:02 by tanastac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

void	ft_putnbr(int nbr)
{
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	else
		ft_putchar(nbr + '0');
}

void	priem(int sig)
{
	static int	chislo;
	static int	i;

	if (sig == -1)
	{
		i = 0;
		chislo = 0;
	}
	else
	{
		if (sig == SIGUSR2)
			chislo += 1 << (7 - i);
		i++;
		if (i == 8)
		{
			ft_putchar(chislo);
			chislo = 0;
			i = 0;
		}
	}
}

int	main(int argc, char **argv)
{
	pid_t	s_pid_name;

	(void)argv;
	if (argc == 1)
	{
		s_pid_name = getpid();
		ft_putstr("PID: ");
		ft_putnbr(s_pid_name);
		ft_putchar('\n');
		priem(-1);
		signal(SIGUSR1, priem);
		signal(SIGUSR2, priem);
		while (1)
			pause();
	}
	return (0);
}
