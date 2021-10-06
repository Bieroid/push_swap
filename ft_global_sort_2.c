#include "push_swap.h"

void	ft_separate_a(linked_list *a, linked_list *b, int size)
{
	int	i;

	a->max = size;
	a->mid = (((a->max - a->next) / 2) + a->next);
	i = ft_lstsize_to_order(a);
	while (i > 0)
	{
		if (a->head->order <= a->mid)
			ft_pb(a, b);
		else
			ft_ra(a, 0);
		i--;
	}
}

void	ft_reverse_a(linked_list *a, linked_list *b)
{
	while (a->tail->order > a->next)
	{
		while ((b->head->order != a->next) && (a->tail->order > a->next))
			ft_rrr(a, b);
		if (a->tail->order > a->next)
			ft_rra(a, 0);
	}
}

void	ft_move_to_b(linked_list *a, linked_list *b)
{
	int	j;

	j = a->head->flag;
	while (a->head->flag == j)
	{
		if ((a->head->order == a->next) && (a->tail->order == a->next - 1))
		{
			ft_ra(a, 0);
			a->next++;
		}
		else
			ft_pb(a, b);
	}
}

int	ft_checker_b_side(linked_list *b, int d)
{
	int		i;
	node	*c;

	i = 1;
	c = b->head;
	while (c->order != d)
	{
		c = c->next;
		i++;
	}
	if (i <= (ft_lstsize(b) / 2))
		return (1);
	else
		return (0);
}

int	ft_checker_pos(linked_list *a)
{
	node	*c;

	c = a->head;
	while (c)
	{
		if (c->order <= a->mid)
			return (1);
		c = c->next;
	}
	return (0);
}
