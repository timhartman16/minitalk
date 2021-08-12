#ifndef MINITALK_H
# define MINITALK_H

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void    ft_putchar(char c);
void    ft_putstr(char *str);
void    ft_putnbr(int nbr);
void	ft_print(int sig);
int		ft_atoi(char *str);
void	otpravka(int pid_name, char c);

#endif