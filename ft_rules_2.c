#include "push_swap.h"

void	ft_rb(linked_list *list, int k)
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
		ft_putstr("rb\n");
}

void	ft_rr(linked_list *b)
{
	ft_rb(b, 1);
	ft_putstr("rr\n");
}

void	ft_rra(linked_list *list, int k)
{
	int	*numb;

	if (list->head == NULL || list->head->next == NULL)
		return ;
	numb = malloc(sizeof(int) * 3);
	if (numb == NULL)
		exit (1);
	numb[1] = list->tail->order;
	numb[2] = list->tail->flag;
	numb[0] = ft_del_back(list);
	ft_push_front(list, numb[0], numb[1], numb[2]);
	free(numb);
	if (k == 0)
		ft_putstr("rra\n");
}

void	ft_rrb(linked_list *list, int k)
{
	int	*numb;

	if (list->head == NULL || list->head->next == NULL)
		return ;
	numb = malloc(sizeof(int) * 3);
	if (numb == NULL)
		exit (1);
	numb[1] = list->tail->order;
	numb[2] = list->tail->flag;
	numb[0] = ft_del_back(list);
	ft_push_front(list, numb[0], numb[1], numb[2]);
	free(numb);
	if (k == 0)
		ft_putstr("rrb\n");
}

void	ft_rrr(linked_list *a, linked_list *b)
{
	ft_rrb(b, 1);
	ft_rra(a, 1);
	ft_putstr("rrr\n");
}
