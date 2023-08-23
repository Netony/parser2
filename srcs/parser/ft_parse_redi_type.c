#include "parser.h"

char	*ft_parse_type(const char *s, int *i)
{
	char	*type;
	
	type = ft_parse_type_set(s, i);
	if (type == NULL)
		return (NULL);
	if (s[*i] == '\0' || ft_isin(s[*i], "<>|"))
	{
		free(type);
		ft_error();
		return (NULL);
	}
	return (type);
}

char	*ft_parse_type_set(const char *s, int *i)
{
	char	*type;

	if (ft_duplen(s, *i, "<") == 1)
	{
		*i += 1;
		type = ft_strdup("infile");
	}
	else if (ft_duplen(s, *i, ">") == 1)
	{
		*i += 1;
		type = ft_strdup("outfile");
	}
	else if (ft_duplen(s, *i, "<") > 1)
	{
		*i += 2;
		type = ft_strdup("here_doc");
	}
	else if (ft_duplen(s, *i, ">") > 1)
	{
		*i += 2;
		type = ft_strdup("append");
	}
	else
		type = ft_strdup("param");
	return (type);
}
