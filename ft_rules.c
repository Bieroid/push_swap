/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rules.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htommy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 19:05:27 by htommy            #+#    #+#             */
/*   Updated: 2021/09/07 19:05:28 by htommy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(linked_list *list)
{
	int value;
	int data;

	if ((*list)->size <= 1)
		return (0);
	value = ft_del_front(list);
	data = ft_del_front(list);
	ft_push_front(list, value);
	ft_push_front(list, data);
}

void	ft_pa(linked_list *a, linked_list *b)
{
	int value;

	if ((*b)->size == 0)
		return (0);
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
	ft_push_front(list);
}