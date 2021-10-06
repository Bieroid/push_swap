#include "push_swap.h"

char	**ft_del(char **l, int a)
{
	while (a >= 0)
	{
		free(l[a]);
		a--;
	}
	free(l);
	return (0);
}

void	ft_increm(int *k, int *d)
{
	*k = *k + 1;
	*d = *d + 1;
}

int	ft_return_value(char const *s, int b)
{
	int	d;

	d = 0;
	if ((s[b] == ' ' || s[b] == '\t') && (s[b + 1] != '\0') && \
		(s[b + 1] != ' ' && s[b + 1] != '\t'))
		d = b + 1;
	return (d);
}

char	**ft_socras(char **l, char const *s, int a)
{
	int	b;
	int	d;
	int	k;

	b = -1;
	while (s[++b] != '\0')
	{
		d = ft_return_value(s, b);
		if ((s[b] != ' ' && s[b] != '\t') && ((s[b + 1] == ' ' || \
			s[b + 1] == '\t') || (s[b + 1] == '\0')))
		{
			k = 0;
			l[a] = ft_calloc(sizeof(char), b - d + 2);
			if (l[a] == 0)
				return (ft_del(l, a));
			while (d <= b)
			{
				l[a][k] = s[d];
				ft_increm(&k, &d);
			}
			a++;
		}
	}
	return (l);
}

char	**ft_split(char const *s)
{
	int		a;
	char	**l;

	if (s == 0)
		return (0);
	a = ft_colichestvo(s);
	l = ft_calloc(sizeof(char *), (a + 1));
	if (l == 0)
		return (0);
	a = 0;
	return (ft_socras(l, s, a));
}
