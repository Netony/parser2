#include "parser.h"

char	*ft_tok(const char *s, int *i, const char *set)
{
	char	*text;
	int		len;

	len = ft_toklen(s, *i, set);
	text = ft_substr(s, *i, len);
	*i += len;
	return (text);
}
