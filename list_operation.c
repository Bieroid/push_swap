/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htommy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 17:16:30 by htommy            #+#    #+#             */
/*   Updated: 2021/09/07 17:16:31 by htommy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		return (0);
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
		return (0);
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
		return (0);
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
		return (0);
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