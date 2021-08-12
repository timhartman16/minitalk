#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void    ft_putstr(char *str)
{
    while (*str)
    {
        write(1, str, 1);
        str++;
    }
}

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

void	otpravka(int pid_name, char c)
{
	int i;
	int num;

	i = 7;
	num = c;
	while (i >= 0)
	{
		if (num >> i & 1)
			kill(pid_name, SIGUSR2);
		else
			kill(pid_name, SIGUSR1);
		usleep(100);
		i--;
	}
}

int main(int argc, char **argv)
{
	int	pid_name;
	int i;

	i = 0;
	if (argc == 3)
	{
		pid_name = ft_atoi(argv[1]);
		if (pid_name == 0)
		{
			ft_putstr("Your input is not correct.\n");
			ft_putstr("Usage: ./client *PID* *message*\n");
			exit(1);
		}
		while (argv[2][i])
		{
			otpravka(pid_name, argv[2][i]);
			i++;
		}
	}
	else
	{
		ft_putstr("Your input is not correct.\n");
		ft_putstr("Usage: ./client *PID* *message*\n");
		exit(1);
	}
	exit(0);
}