#include <unistd.h>
#include <stdio.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    ft_putstr(char *str)
{
    while (*str)
    {
        ft_putchar(*str);
        str++;
    }
}

void    ft_putnbr(int nbr)
{
    if (nbr > 9)
    {
        ft_putnbr(nbr / 10);
        ft_putnbr(nbr % 10);
    }
    else
        ft_putchar(nbr + '0');
}

int main(int argc, char **argv)
{
    __pid_t s_pid_name;

    if (argc == 1)
    {
        s_pid_name = getpid();
        ft_putstr("PID: ");
        ft_putnbr(s_pid_name);
        ft_putchar('\n');
        pause();
    }
    return (0);
}