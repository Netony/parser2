#include "parser.h"

t_list	*ft_parse_redi_list(const char *s, int *i)
{
	t_list	*list;
	t_list	*node;

	list = NULL;
	while (1)
	{
		*i += ft_duplen(s, *i, " ");
		if (s[*i] == '\0' || s[*i] == '|')
			break ;
		node = ft_parse_redi_node(s, i);
		if (node == NULL)
		{
			ft_lstclear(&list, ft_redidel);
			return (NULL);
		}
		ft_lstadd_back(&list, node);
	}
	return (list);
}

t_list	*ft_parse_redi_node(const char *s, int *i)
{
	t_list	*node;
	t_redi	*redi;
	char	*type;
	char	*text;

	type = ft_parse_type(s, i);
	if (type == NULL)
		return (NULL);
	text = ft_parse_path(s, i);
	if (text == NULL)
	{
		free(type);
		return (NULL);
	}
	redi = ft_redinew(type, text);
	if (redi == NULL)
	{
		free(type);
		free(text);
		return (NULL);
	}
	node = ft_lstnew(redi);
	if (node == NULL)
		ft_redidel(redi);
	return (node);
}
