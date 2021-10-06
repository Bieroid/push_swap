#include "push_swap.h"

void	ft_sort_3_b(linked_list *a)
{
	if ((a->head->next->value > a->tail->value) && \
		(a->tail->value > a->head->value))
	{
		ft_sb(a);
		ft_rb(a, 0);
	}
	if ((a->head->value > a->tail->value) && \
		(a->tail->value > a->head->next->value))
		ft_rb(a, 0);
	if ((a->tail->value > a->head->value) && \
		(a->head->value > a->head->next->value))
		ft_sb(a);
	if ((a->head->value > a->head->next->value) && \
		(a->head->next->value > a->tail->value))
	{
		ft_sb(a);
		ft_rrb(a, 0);
	}
	if ((a->head->next->value > a->head->value) && \
		(a->head->value > a->tail->value))
		ft_rrb(a, 0);
}

void	ft_sort_3(linked_list *a)
{
	if ((a->head->next->value > a->tail->value) && \
		(a->tail->value > a->head->value))
	{
		ft_sa(a);
		ft_ra(a, 0);
	}
	if ((a->head->value > a->tail->value) && \
		(a->tail->value > a->head->next->value))
		ft_ra(a, 0);
	if ((a->tail->value > a->head->value) && \
		(a->head->value > a->head->next->value))
		ft_sa(a);
	if ((a->head->value > a->head->next->value) && \
		(a->head->next->value > a->tail->value))
	{
		ft_sa(a);
		ft_rra(a, 0);
	}
	if ((a->head->next->value > a->head->value) && \
		(a->head->value > a->tail->value))
		ft_rra(a, 0);
}

void	ft_sort_4(linked_list *a, linked_list *b, int i)
{
	while (a->head->order != i)
		ft_ra(a, 0);
	ft_pb(a, b);
	ft_sort_3(a);
	ft_pa(a, b);
}

void	ft_sort_5(linked_list *a, linked_list *b)
{
	while (a->head->order != 1)
		ft_ra(a, 0);
	ft_pb(a, b);
	ft_sort_4(a, b, 2);
	ft_pa(a, b);
}

void	ft_sort_min(linked_list *a, linked_list *b, int size)
{
	if (size == 2)
		ft_sa(a);
	else if (size == 3)
		ft_sort_3(a);
	else if (size == 4)
		ft_sort_4(a, b, 1);
	else
		ft_sort_5(a, b);
}
