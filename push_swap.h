#ifndef	PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

typedef	struct	s_node
{
	int	value;
	int	order;
	int flag;
	struct s_node *next;
	struct s_node *prev;
}				node;

typedef	struct	s_stack
{
	unsigned int	size;
	node			*head;
	node			*tail;
}				linked_list;

linked_list *ft_create_list(void);
void ft_delete_list(linked_list **list);
void ft_push_front(linked_list *list, int data);
int ft_del_front(linked_list *list);
void ft_push_back(linked_list *list, int data);
int ft_del_back(linked_list *list);

#endif