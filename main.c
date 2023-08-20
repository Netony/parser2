#include "parser.h"

int	test(t_list *list)
{
	printf("");
	return (0);
}

int	main(int argc, char *argv)
{
	t_list	*cmds;

	if (argc == 2)
		parser(argv[1]);
	return (0);
}

t_cmd	*parser(char *s)
{
	t_cmd	*cmds;
	int		i;

	i = 0;
	while (s[i])
	{
		i += ft_duplen(s, i, " ");

	}
	return ();
}

t_cmd	*ft_lsttocmds(t_list *lst)
{
	
}
