#include "push_swap.h"

void	ft_list_fill(linked_list *a, int *num, int *buff, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (buff[j] != num[i])
			j++;
		ft_push_back(a, num[i], j + 1, 0);
		i++;
	}
}

void	ft_null_list(linked_list *a, linked_list *b, int size)
{
	a->flag = 0;
	a->next = 1;
	a->max = size;
	a->mid = ((size / 2) + a->next);
	a->head = NULL;
	a->tail = NULL;
	b->flag = 0;
	b->next = 0;
	b->mid = 0;
	b->max = 0;
	b->head = NULL;
	b->tail = NULL;
}
