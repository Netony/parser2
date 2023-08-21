#include "parser.h"

t_list	*parser(const char *s)
{
	int		i;
	t_list	*list;
	t_list	*node;

	i = 0;
	list = NULL;
	i += ft_duplen(s, i, " ");
	if (s[i] == '|')
	{
		ft_error();
		return (NULL);
	}
	while (s[i])
	{
		node = ft_cmd(s, &i);
		if (node == NULL)
			ft_lstclear(&list, ft_cmddel);
		ft_lstadd_back(&list, node);
		i += ft_duplen(s, i, " ");
	}
	ft_print_cmd(list);
	return (0);
}

t_list	*ft_cmd(const char *s, int *i)
{
	t_list	*chunks;

	ft_pipe_check(s, i);
	chunks = ft_chunks(s, i);
	if (chunks == NULL)
		return (NULL);
	return (ft_lstnew(chunks));
}
