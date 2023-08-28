#include "parser.h"

t_list	*ft_parse_env_list(const char *s)
{
	t_list	*list;
	t_list	*node;
	int		flag;
	int		i;

	list = NULL;
	i = 0;
	flag = 0;
	while (s[i])
	{
		node = ft_parse_env_node(s, &i, &flag);
		if (node == NULL)
		{
			ft_lstclear(&list, free);
			return (NULL);
		}
		ft_lstadd_back(&list, node);
	}
	if (flag == 1)
	{
		ft_error();
		return (NULL);
	}
	return (list);
}

t_list	*ft_parse_env_node(const char *s, int *i, int *flag)
{
	t_list	*node;
	char	*text;

	if (s[*i] == '\'')
		text = ft_skip(i, flag);
	else if (*flag == 0)
	{
		if (s[*i] == '$')
			text = ft_parse_env_get(s, i);
		else
			text = ft_parse_tok(s, i, "\'$");
	}
	else
		text = ft_parse_tok(s, i, "\'");
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

char	*ft_parse_env_skip(int *i, int *flag)
{
	if (*flag == 1)
		*flag = 0;
	else
		*flag = 1;
	*i += 1;
	return (ft_strdup("\'"));
}

char	*ft_parse_env_get(const char *s, int *i)
{
	int		len;
	char	*temp;
	char	*env;

	*i += 1;
	len = ft_toklen(s, *i, "$\"\' <>|");
	if (len == 0)
	{
		if (s[*i] == '$')
			env = ft_getenv("$");
		else if (s[*i] == '\0' || ft_isin(s[*i], " <|>"))
			return (ft_strdup("$"));
		else // (ft_isin(s[*i], "\'\""))
			return (ft_strdup(""));
		*i += 1;
	}
	else
	{
		temp = ft_substr(s, *i, len);
		*i += len;
		if (temp == NULL)
			return (NULL);
		env = ft_getenv(temp);
		free(temp);
	}
	return (env);
}
