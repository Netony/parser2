#include "parser.h"

t_list	*ft_chunks(const char *s, int *i)
{
	t_list	*list;
	t_list	*node;
	t_chunk	*chunk;

	list = NULL;
	while (s[*i] && s[*i] != '|')
	{
		chunk = ft_chunk(s, i);
		if (chunk == NULL)
		{
			ft_lstclear(&list, ft_chkdel);
			return (NULL);
		}
		node = ft_lstnew(chunk);
		if (node == NULL)
		{
			ft_chkdel(chunk);
			ft_lstclear(&list, ft_chkdel);
			return (NULL);
		}
		ft_lstadd_back(&list, node);
		*i += ft_duplen(s, *i, " ");
	}
	return (list);
}

t_chunk	*ft_chunk(const char *s, int *i)
{
	char	*type;
	char	*text;

	type = ft_type(s, i);
	if (type == NULL)
		return (NULL);
	text = ft_text(s, i);
	if (text == NULL)
	{
		free(type);
		return (NULL);
	}
	return (ft_chknew(type, text));
}
