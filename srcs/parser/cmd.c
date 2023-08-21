#include "minishell.h"

int	ft_cmdsdel(t_cmd *cmds, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_varsclear(cmds[i].vars);
		ft_lstclear(&(cmds[i].list), ft_chkdel);
		i++;
	}
	free(cmds);
	return (0);
}

int	ft_cmdsclear(t_cmd *cmds)
{
	int	i;

	i = 0;
	while (cmds[i])
	{
		ft_varsclear(cmds[i].vars);
		ft_lstclear(&(cmds[i].list), ft_chkdel);
		i++;
	}
	free(cmds);
	return (0);
}
