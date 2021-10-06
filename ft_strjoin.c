#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	int	a;

	a = 0;
	while (s[a] != '\0')
		a++;
	return (a);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	size_t		a;
	size_t		b;
	size_t		c;
	char		*s;

	c = -1;
	a = ft_strlen(s1);
	b = ft_strlen(s2);
	s = ft_calloc((a + b) + 1, sizeof(char));
	if (s == 0)
		return (0);
	while (++c < a)
		s[c] = s1[c];
	c--;
	a = 0;
	while (a <= b)
	{
		c++;
		s[c] = s2[a];
		a++;
	}
	return (s);
}
