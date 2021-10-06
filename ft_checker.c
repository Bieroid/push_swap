#include "push_swap.h"

int	ft_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
			|| str[i] == ' ' || str[i] == '\r' || str[i] == '\f')
			i++;
		else
			return (1);
	}
	return (0);
}

void	ft_number_check(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			return ;
		i++;
	}
	ft_error();
}

void	ft_valid_check(char *str)
{
	int	i;
	int	number;
	int	sign;

	i = 0;
	number = 0;
	sign = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			number++;
		else if (str[i] == ' ' || str[i] == '\t')
		{
			if (sign != 0 && number == 0)
				ft_error();
			number = 0;
			sign = 0;
		}
		else if ((str[i] == '+' || str[i] == '-') && \
				(sign == 0 && number == 0) && (str[i + 1] != '\0'))
			sign++;
		else
			ft_error();
		i++;
	}
}

int	ft_checker(int argc, char **argv)
{
	int	i;
	int	a;

	i = 1;
	a = 0;
	while (i < argc)
	{
		if (argv[i][0] == 0)
		{
			ft_putchar('\n');
			exit (1);
		}
		if (ft_space(argv[i]))
		{
			ft_number_check(argv[i]);
			ft_valid_check(argv[i]);
			a = 1;
		}
		i++;
	}
	return (a);
}
