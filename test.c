#include "push_swap.h"

linked_list	*ft_create_list(void)
{
	linked_list *stack;

	stack = malloc(sizeof(linked_list));
	stack->size = 0;
	stack->head = NULL;
	stack->tail = NULL;
	return (stack);
}

void ft_delete_list(linked_list **list)
{
	node *tmp;
	node *next;

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

void ft_push_front(linked_list *list, int data)
{
	node *tmp;

	tmp = malloc(sizeof(node));
	if (tmp == NULL)
		exit (0);
	tmp->value = data;
	tmp->next = list->head;
	tmp->prev = NULL;
	if (list->head)
		list->head->prev = tmp;
	list->head = tmp;
	if (list->tail == NULL)
		list->tail = tmp;
	list->size++;
}

int ft_del_front(linked_list *list)
{
	node	*prev;
	int		tmp;

	if (list->head == NULL)
		exit (0);
	prev = list->head;
	list->head = list->head->next;
	if (list->head)
		list->head->prev = NULL;
	if (prev == list->tail)
		list->tail = NULL;
	tmp = prev->value;
	free(prev);
	list->size--;
	return (tmp);
}

void ft_push_back(linked_list *list, int data)
{
	node *tmp;

	tmp = malloc(sizeof(node));
	if (tmp == NULL)
		exit (0);
	tmp->value = data;
	tmp->next = NULL;
	tmp->prev = list->tail;
	if (list->tail)
		list->tail->next = tmp;
	list->tail = tmp;
	if (list->head == NULL)
		list->head = tmp;
	list->size++;
}

int ft_del_back(linked_list *list)
{
	node *next;
	int	tmp;

	if (list->tail == NULL)
		exit (0);
	next = list->tail;
	list->tail = list->tail->prev;
	if (list->tail)
		list->tail->next = NULL;
	if (next == list->head)
		list->head = NULL;
	tmp = next->value;
	free(next);
	list->size--;
	return (tmp);
}

void	ft_sa(linked_list *list)
{
	int value;
	int data;

	if (list->size <= 1)
		exit (0);
	value = ft_del_front(list);
	data = ft_del_front(list);
	ft_push_front(list, value);
	ft_push_front(list, data);
}

void	ft_pa(linked_list *a, linked_list *b)
{
	int value;

	if (b->size == 0)
		exit (0);
	value = ft_del_front(b);
	ft_push_front(a, value);
}

void	ft_ra(linked_list *list)
{
	int value;

	value = ft_del_front(list);
	ft_push_back(list, value);
}

void	ft_rra(linked_list *list)
{
	int value;

	value = ft_del_back(list);
	ft_push_front(list, value);
}

void ft_print_list(linked_list *list)
{
	node *tmp = list->head;
	while (tmp)
	{
		printf("%d\n", tmp->value);
		tmp = tmp->next;
	}
}

int main(int argc, char *argv[])
{
	linked_list *list;
	int i = 0;
	int a;

	list = ft_create_list();
	while (++i < argc)
	{
		a = argv[i][0] - 48;
		ft_push_front(list, a);
	}
	ft_print_list(list);
	ft_sa(list);
	printf("\n");
	ft_print_list(list);
}