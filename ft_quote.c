#include "parser.h"

t_list	*ft_dquote_parse(const char *s, int *i);

char	*ft_dquote(const char *s, int *i)
{
	t_list	*list;
	t_list	*node;
	char	*text;

	*i += 1;
	if (ft_toklen_zero(s, *i, "\"") < 0)
		return (NULL);
	list = NULL;
	while (s[*i] && s[*i] != '\"')
	{
		node = ft_dquote_parse(s, i);
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

t_list	*ft_dquote_parse(const char *s, int *i)
{
	char	*text;
	
	if (s[*i] == '$')
		text = ft_env(s, i);
	else 
		text = ft_tok(s, i, "$\"");
	if (text == NULL)
		return (NULL);
	return (ft_lstnew(text));
}

char	*ft_quote(const char *s, int *i)
{
	char	*text;

	*i += 1;
	text = ft_tok(s, i, "\'");
	*i += 1;
	return (text);
}
