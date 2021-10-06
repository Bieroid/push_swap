#include "push_swap.h"

void	ft_separate_argv(int argc, char **argv, int *num)
{
	int		a;
	int		i;
	int		count;
	char	**buff;

	i = 1;
	a = 0;
	while (i < argc)
	{
		count = 0;
		buff = ft_split(argv[i]);
		while (buff[count] != NULL)
		{
			num[a] = ft_atoi(buff[count]);
			free(buff[count]);
			a++;
			count++;
		}
		free(buff);
		i++;
	}
}
