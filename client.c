#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

int	ft_atoi(char *str)
{
	long	i;
	long	sign;
	long	num;

	i = 0;
	sign = 1;
	num = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		num = num * 10 + (str[i++] - '0');
	return (sign * num);
}

int main(int argc, char **argv)
{
	int	pid_name;
	int	i;

	if (argc == 2)
	{
		pid_name = ft_atoi(argv[1]);
		kill(pid_name, SIGUSR1);
	}
	exit(0);
}