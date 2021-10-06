#include "push_swap.h"

void	*ft_calloc(size_t num, size_t size)
{
	size_t	a;
	char	*s;

	a = 0;
	s = malloc(size * num);
	if (s == 0)
		return (0);
	while (a < (size * num))
	{
		s[a] = 0;
		a++;
	}
	return (s);
}

int	ft_sum(const char *str, int a, int minus)
{
	unsigned int	sum;

	sum = 0;
	while ((str[a] >= 48) && (str[a] <= 57))
	{
		sum = (sum * 10) + (str[a] - 48);
		a++;
		if ((str[a] < 48) || (str[a] > 57))
		{
			if (minus == 0)
			{
				if (sum > 2147483647)
					ft_error ();
				return (sum);
			}
			else
			{
				if (sum > 2147483648)
					ft_error ();
				return (-sum);
			}
		}
	}
	return (0);
}

int	ft_atoi(const char	*str)
{
	int	a;
	int	minus;

	a = 0;
	minus = 0;
	while ((str[a] == ' ') || (str[a] == '\n') || (str[a] == '\t')
		|| (str[a] == '\v') || (str[a] == '\f') || (str[a] == '\r'))
		a++;
	if ((str[a] == '+') || (str[a] == '-'))
	{
		if (str[a] == '-')
			minus = 1;
		a++;
	}
	return (ft_sum(str, a, minus));
}

int	ft_lstsize(linked_list *lst)
{
	node	*b;
	int		a;

	a = 0;
	b = lst->head;
	while (b)
	{
		b = b->next;
		a++;
	}
	return (a);
}
