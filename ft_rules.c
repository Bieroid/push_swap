#include "push_swap.h"

void	ft_sa(linked_list *list)
{
	int	*numb;

	if (list->head == NULL || list->head->next == NULL)
		return ;
	numb = malloc(sizeof(int) * 6);
	if (numb == NULL)
		exit (1);
	numb[1] = list->head->order;
	numb[2] = list->head->flag;
	numb[0] = ft_del_front(list);
	numb[4] = list->head->order;
	numb[5] = list->head->flag;
	numb[3] = ft_del_front(list);
	ft_push_front(list, numb[0], numb[1], numb[2]);
	ft_push_front(list, numb[3], numb[4], numb[5]);
	free(numb);
	ft_putstr("sa\n");
}

void	ft_sb(linked_list *list)
{
	int	*numb;

	if (list->head == NULL || list->head->next == NULL)
		return ;
	numb = malloc(sizeof(int) * 6);
	if (numb == NULL)
		exit (1);
	numb[1] = list->head->order;
	numb[2] = list->head->flag;
	numb[0] = ft_del_front(list);
	numb[4] = list->head->order;
	numb[5] = list->head->flag;
	numb[3] = ft_del_front(list);
	ft_push_front(list, numb[0], numb[1], numb[2]);
	ft_push_front(list, numb[3], numb[4], numb[5]);
	free(numb);
	ft_putstr("sb\n");
}

void	ft_pa(linked_list *a, linked_list *b)
{
	int	*numb;

	if (b->head == NULL)
		return ;
	numb = malloc(sizeof(int) * 3);
	if (numb == NULL)
		exit (1);
	numb[1] = b->head->order;
	numb[2] = b->head->flag;
	numb[0] = ft_del_front(b);
	ft_push_front(a, numb[0], numb[1], numb[2]);
	free(numb);
	ft_putstr("pa\n");
}

void	ft_pb(linked_list *a, linked_list *b)
{
	int	*numb;

	if (a->head == NULL)
		return ;
	numb = malloc(sizeof(int) * 3);
	if (numb == NULL)
		exit (1);
	numb[1] = a->head->order;
	numb[2] = a->head->flag;
	numb[0] = ft_del_front(a);
	ft_push_front(b, numb[0], numb[1], numb[2]);
	free(numb);
	ft_putstr("pb\n");
}

void	ft_ra(linked_list *list, int k)
{
	int	*numb;

	if (list->head == NULL || list->head->next == NULL)
		return ;
	numb = malloc(sizeof(int) * 3);
	if (numb == NULL)
		exit (1);
	numb[1] = list->head->order;
	numb[2] = list->head->flag;
	numb[0] = ft_del_front(list);
	ft_push_back(list, numb[0], numb[1], numb[2]);
	free(numb);
	if (k == 0)
		ft_putstr("ra\n");
}
