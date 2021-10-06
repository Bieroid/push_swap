#include "push_swap.h"

int	*ft_mas_sort(int *num, int size)
{
	int	i;
	int	j;
	int	*buff;

	i = -1;
	j = -1;
	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		exit (1);
	while (++j < size)
		buff[j] = num[j];
	while (++i < size - 1)
	{
		j = -1;
		while (++j < size - i - 1)
		{
			if (buff[j] > buff[j + 1])
			{
				buff[j] = buff[j] + buff[j + 1];
				buff[j + 1] = buff[j] - buff[j + 1];
				buff[j] = buff[j] - buff[j + 1];
			}
		}
	}
	return (buff);
}

void	ft_duplicate_check(int *num, int size)
{
	int	i;

	i = 0;
	while (i != size)
	{
		if (num[i] == num[i + 1])
			ft_error();
		i++;
	}
}

int	ft_is_sorted(int *num, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (num[i] > num[i + 1])
			return (1);
		else if (num[i] == num[i + 1])
			ft_error ();
		i++;
	}
	return (0);
}

int	ft_lstsize_to_order(linked_list *lst)
{
	node	*b;
	int		a;

	a = 0;
	b = lst->head;
	while (b->order != 1)
	{
		b = b->next;
		a++;
	}
	return (a);
}
