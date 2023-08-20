#include "parser.h"

int	ft_toklen(const char *s, int start, const char *set)
{
	int	len;

	len = 0;
	while (s[start + len])
	{
		if (ft_isin(s[start + len], set))
			break ;
		len++;
	}
	return (len);
}

int	ft_toklen_zero(const char *s, int start, const char *set)
{
	int	len;

	len = 0;
	while (s[start + len])
	{
		if (ft_isin(s[start + len], set))
			return (len) ;
		len++;
	}
	return (-1);
}

int	ft_duplen(const char *s, int start, const char *set)
{
	int	len;

	len = 0;
	while (s[start + len])
	{
		if (!ft_isin(s[start + len], set))
			break ;
		len++;
	}
	return (len);
}

int	ft_isin(int a, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == a)
			return (1);
		i++;
	}
	return (0);
}
