#include "parser.h"

char	*ft_text(const char *s, int *i)
{
	t_list	*list;
	t_list	*node;
	char	*text;

	*i += ft_duplen(s, *i, " ");
	list = NULL;
	while (s[*i] && !ft_isin(s[*i], " <>|"))
	{
		node = ft_text_parse(s, i);
		if (node == NULL)
		{
			ft_lstclear(&list, free);
			return (NULL);
		}
		ft_lstadd_back(&list, node);
	}
	text = ft_lstjoin(list);
	ft_lstclear(&list, free);
	return (text);
}

t_list	*ft_text_parse(const char *s, int *i)
{
	char	*text;
	
	if (s[*i] == '$')
		text = ft_env(s, i);
	else
		text = ft_tok(s, i);
	if (text == NULL)
		return (NULL);
	return (ft_lstnew(text));
}
