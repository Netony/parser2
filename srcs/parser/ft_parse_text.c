#include "parser.h"

char	*ft_parse_dquote(const char *s, int *i)
{
	t_list	*list;
	t_list	*node;
	char	*text;

	*i += 1;
	if (ft_toklen_zero(s, *i, "\"") < 0)
	{
		ft_error();
		return (NULL);
	}
	list = NULL;
	while (s[*i] && s[*i] != '\"')
	{
		node = ft_parse_dquote_node(s, i);
		if (node == NULL)
		{
			ft_lstclear(&list, free);
			return (NULL);
		}
		ft_lstadd_back(&list, node);
	}
	text = ft_lstjoin(list);
	ft_lstclear(&list, free);
	*i += 1;
	return (text);
}

t_list	*ft_parse_dquote_node(const char *s, int *i)
{
	char	*text;
	t_list	*node;
	
	if (s[*i] == '$')
		text = ft_parse_env(s, i);
	else 
		text = ft_parse_tok(s, i, "$\"");
	if (text == NULL)
		return (NULL);
	node = ft_lstnew(text);
	if (node == NULL)
	{
		free(text);
		return (NULL);
	}
	return (node);
}

char	*ft_parse_quote(const char *s, int *i)
{
	char	*text;

	*i += 1;
	if (ft_toklen_zero(s, *i, "\'") < 0)
	{
		ft_error();
		return (NULL);
	}
	text = ft_parse_tok(s, i, "\'");
	*i += 1;
	return (text);
}

char	*ft_parse_tok(const char *s, int *i, const char *set)
{
	char	*text;
	int		len;

	len = ft_toklen(s, *i, set);
	text = ft_substr(s, *i, len);
	*i += len;
	return (text);
}

char	*ft_getenv(const char *s)
{
	(void)s;
	return (ft_strdup(""));
}

char	*ft_parse_env(const char *s, int *i)
{
	int		len;
	char	*temp;
	char	*env;

	*i += 1;
	len = ft_toklen(s, *i, "$\"\' <>|");
	if (len == 0)
	{
		if (s[*i] == '$')
			ft_getenv("$");
		else if (s[*i] == '\0' || s[*i] == ' ')
			return (ft_strdup("$"));
		else
			return (ft_strdup(""));
	}
	*i += len;
	temp = ft_substr(s, *i, len);
	if (temp == NULL)
		return (NULL);
	env = ft_getenv(temp);
	free(temp);
	return (env);
}
