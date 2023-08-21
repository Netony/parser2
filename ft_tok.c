#include "parser.h"

char	*ft_tok(const char *s, int start, int size)
{
	return (ft_substr(s, start, size));
}
