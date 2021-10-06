#include "push_swap.h"

void	ft_sort(linked_list *a, linked_list *b, int size)
{
	if (size <= 5)
		ft_sort_min(a, b, size);
	else
		ft_global_sort(a, b, size);
}

void	ft_main_reduce(int argc, char **argv, linked_list *a, linked_list *b)
{
	int			*num;
	int			*buff;

	buff = NULL;
	num = malloc(sizeof(int) * (argc - 1));
	if (num == NULL)
		exit (1);
	if (ft_checker(argc, argv))
	{
		ft_separate_argv(argc, argv, num);
		if (ft_is_sorted(num, argc - 1))
		{
			buff = ft_mas_sort(num, argc - 1);
			ft_duplicate_check(buff, argc - 1);
			ft_null_list(a, b, argc - 1);
			ft_list_fill(a, num, buff, argc - 1);
			ft_sort(a, b, argc - 1);
		}
	}
	ft_delete_list(&a);
	ft_delete_list(&b);
	free(num);
	free(buff);
}

int	main(int argc, char **argv)
{
	linked_list	*a;
	linked_list	*b;

	if (argc < 2)
		exit (1);
	a = malloc(sizeof(linked_list) * 1);
	if (a == NULL)
		exit (1);
	b = malloc(sizeof(linked_list) * 1);
	if (b == NULL)
		exit (1);
	ft_main_reduce(argc, argv, a, b);
	return (0);
}
