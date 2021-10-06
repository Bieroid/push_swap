#include "push_swap.h"

void	ft_red_move_from_b(linked_list *a, linked_list *b)
{
	if (b->head->order <= a->mid)
		ft_rb(b, 0);
	else
	{
		b->head->flag = a->flag;
		ft_pa(a, b);
	}
}

void	ft_red_b_next(linked_list *a, linked_list *b)
{
	b->head->flag = a->flag;
	ft_pa(a, b);
	ft_ra(a, 0);
	a->next++;
}

void	ft_move_from_b(linked_list *a, linked_list *b)
{
	int	i;
	
	while (ft_lstsize(b) != 0)
	{
		i = ft_lstsize(b) + 1;
		a->max = a->mid;
		a->mid = (((a->max - a->next) / 2) + a->next);
		a->flag++;
		while (--i > 0)
		{
			if (b->head->order == a->next)
				ft_red_b_next(a, b);
			else
				ft_red_move_from_b(a, b);
		}
	}
}
