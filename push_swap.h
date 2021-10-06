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
	int				flag;
	int				next;
	int				mid;
	int				max;
	node			*head;
	node			*tail;
}				linked_list;

int		ft_colichestvo(char const *s);
char	**ft_split(char const *s);
void	*ft_calloc(size_t num, size_t size);
int		ft_atoi(const char	*str);
void	ft_error(void);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char const *s2);
int		ft_lstsize(linked_list *lst);
int		ft_lstsize_to_order(linked_list *lst);
int		ft_lstsize_to_flag(linked_list *lst);
void	ft_putstr(char *str);
void	ft_putchar(char c);

void		ft_null_list(linked_list *a, linked_list *b, int size);
void		ft_delete_list(linked_list **list);
void		ft_push_front(linked_list *list, int value, int order, int flag);
int			ft_del_front(linked_list *list);
void		ft_push_back(linked_list *list, int value, int order, int flag);
int			ft_del_back(linked_list *list);
void		ft_sa(linked_list *list);
void		ft_sb(linked_list *list);
void		ft_pa(linked_list *a, linked_list *b);
void		ft_pb(linked_list *a, linked_list *b);
void		ft_ra(linked_list *list, int k);
void		ft_rb(linked_list *list, int k);
void		ft_rr(linked_list *b);
void		ft_rra(linked_list *list, int k);
void		ft_rrb(linked_list *list, int k);
void		ft_rrr(linked_list *a, linked_list *b);
int			*ft_mas_sort(int *buff, int size);
void		ft_separate_argv(int argc, char **argv, int *num);
int			ft_checker(int argc, char **argv);
void		ft_duplicate_check(int *num, int size);
void		ft_list_fill(linked_list *a, int *num, int *buff, int size);
void		ft_sort_min(linked_list *a, linked_list *b, int size);
void		ft_sort_3_b(linked_list *a);
int			ft_is_sorted(int *num, int size);
void		ft_global_sort(linked_list *a, linked_list *b, int size);
void		ft_separate_a(linked_list *a, linked_list *b, int size);
void		ft_reverse_a(linked_list *a, linked_list *b);
void		ft_move_to_b(linked_list *a, linked_list *b);
int			ft_checker_b_side(linked_list *b, int d);
int			ft_checker_pos(linked_list *a);
void		ft_move_from_b(linked_list *a, linked_list *b);

#endif