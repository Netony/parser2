#include "parser.h"

char	*ft_parse_path(const char *s, int *i)
{
	char	*path;
	t_list	*text_list;

	text_list = ft_parse_text_list(s, i);
	if (text_list == NULL)
		return (NULL);
	path = ft_lstjoin(text_list);
	ft_lstclear(&text_list, free);
	if (path == NULL)
		return (NULL);
	return (path);
}

t_list	*ft_parse_text_list(const char *s, int *i)
{
	t_list	*list;
	t_list	*node;

	*i += ft_duplen(s, *i, " ");
	list = NULL;
	while (1)
	{
		if (s[*i] == '\0' || ft_isin(s[*i], " <>|"))
			break ;
		node = ft_parse_text_node(s, i);
		if (node == NULL)
		{
			ft_lstclear(&list, free);
			return (NULL);
		}
		ft_lstadd_back(&list, node);
	}
	return (list);
}

t_list	*ft_parse_text_node(const char *s, int *i)
{
	t_list	*node;
	char	*text;
	
	if (s[*i] == '$')
		text = ft_parse_env(s, i);
	else if (s[*i] == '\'')
		text = ft_parse_quote(s, i);
	else if (s[*i] == '\"')
		text = ft_parse_dquote(s, i);
	else 
		text = ft_parse_tok(s, i, "$\'\" <>|");
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
