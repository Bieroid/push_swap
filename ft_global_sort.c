#include "push_swap.h"

void	ft_flag_move_red(linked_list *a, linked_list *b)
{
	if (ft_checker_b_side(b, a->next))
	{
		while (b->head->order != a->next)
			ft_rb(b, 0);
	}
	else
	{
		while (b->head->order != a->next)
			ft_rrb(b, 0);
	}
}

void	ft_flag_move_b(linked_list *a, linked_list *b)
{
	while (ft_lstsize(b) != 0)
	{
		if (ft_lstsize(b) == 3)
		{
			ft_sort_3_b(b);
			while (ft_lstsize(b) != 0)
			{
				ft_pa(a, b);
				ft_ra(a, 0);
				a->next++;
			}
			break ;
		}
		ft_flag_move_red(a, b);
		ft_pa(a, b);
		ft_ra(a, 0);
		a->next++;
	}
}

void	ft_first_move_ab(linked_list *a, linked_list *b)
{
	int	i;

	i = ft_lstsize(a);
	while (i > 0)
	{
		if (a->head->order <= a->mid)
			ft_pb(a, b);
		else
		{
			if (ft_checker_pos(a))
				ft_ra(a, 0);
			else
				break ;
		}
		i--;
	}
	ft_move_from_b(a, b);
}

void	ft_global_sort(linked_list *a, linked_list *b, int size)
{
	ft_first_move_ab(a, b);
	while (a->next != size)
	{
		while (a->head->flag != 0)
		{
			ft_move_to_b(a, b);
			ft_flag_move_b(a, b);
		}
		ft_separate_a(a, b, size);
		ft_reverse_a(a, b);
		ft_move_from_b(a, b);
	}
	if ((a->head->order == a->next) && (a->tail->order == a->next - 1))
	{
		ft_ra(a, 0);
		a->next++;
	}
}
