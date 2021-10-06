#include "push_swap.h"

void	ft_red_move_from_b(linked_list *a, linked_list *b, int *k)
{
	if (b->head->order <= a->mid)
	{
		if (*k == 1)
		{
			ft_rr(b);
			*k = 0;
		}
		else
			ft_rb(b, 0);
	}
	else
	{
		b->head->flag = a->flag;
		if (*k == 1)
		{
			ft_putstr("ra\n");
			*k = 0;
		}
		ft_pa(a, b);
	}
}

void	ft_red_b_next(linked_list *a, linked_list *b, int *k)
{
	b->head->flag = a->flag;
	ft_pa(a, b);
	if (*k == 1)
		ft_putstr("ra\n");
	ft_ra(a, 1);
	*k = 1;
	a->next++;
}

void	ft_move_from_b(linked_list *a, linked_list *b)
{
	int	i;
	int	k;

	k = 0;
	while (ft_lstsize(b) != 0)
	{
		i = ft_lstsize(b) + 1;
		a->max = a->mid;
		a->mid = (((a->max - a->next) / 2) + a->next);
		a->flag++;
		while (--i > 0)
		{
			if (b->head->order == a->next)
				ft_red_b_next(a, b, &k);
			else
				ft_red_move_from_b(a, b, &k);
		}
	}
}
