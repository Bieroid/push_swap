#include "push_swap.h"

int	ft_colichestvo(char const *s)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	if (s[0] != ' ' && s[0] != '\t' && s[0] != '\0')
		b++;
	while (s[a] != '\0')
	{
		if ((s[a] == ' ' || s[a] == '\t') && (s[a + 1] != ' ' && \
			s[a + 1] != '\t') && (s[a + 1] != '\0'))
			b++;
		a++;
	}
	return (b);
}
