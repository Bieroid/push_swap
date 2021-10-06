#include "push_swap.h"

void	ft_delete_list(linked_list **list)
{
	node	*tmp;
	node	*next;

	tmp = (*list)->head;
	next = NULL;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	free(*list);
	(*list) = NULL;
}

void	ft_push_front(linked_list *list, int value, int order, int flag)
{
	node	*tmp;

	tmp = malloc(sizeof(node));
	if (tmp == NULL)
		exit (1);
	tmp->value = value;
	tmp->order = order;
	tmp->flag = flag;
	tmp->next = list->head;
	tmp->prev = NULL;
	if (list->head)
		list->head->prev = tmp;
	list->head = tmp;
	if (list->tail == NULL)
		list->tail = tmp;
}

int	ft_del_front(linked_list *list)
{
	node	*prev;
	int		tmp;

	if (list->head == NULL)
		exit (1);
	prev = list->head;
	list->head = list->head->next;
	if (list->head)
		list->head->prev = NULL;
	if (prev == list->tail)
		list->tail = NULL;
	tmp = prev->value;
	free(prev);
	return (tmp);
}

void	ft_push_back(linked_list *list, int value, int order, int flag)
{
	node	*tmp;

	tmp = malloc(sizeof(node));
	if (tmp == NULL)
		exit (1);
	tmp->value = value;
	tmp->order = order;
	tmp->flag = flag;
	tmp->next = NULL;
	tmp->prev = list->tail;
	if (list->tail)
		list->tail->next = tmp;
	list->tail = tmp;
	if (list->head == NULL)
		list->head = tmp;
}

int	ft_del_back(linked_list *list)
{
	node	*next;
	int		tmp;

	if (list->tail == NULL)
		exit (1);
	next = list->tail;
	list->tail = list->tail->prev;
	if (list->tail)
		list->tail->next = NULL;
	if (next == list->head)
		list->head = NULL;
	tmp = next->value;
	free(next);
	return (tmp);
}
