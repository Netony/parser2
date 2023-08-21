#include "minishell.h"
#include "parser.h"

t_list	*ft_redi(t_list *cmd);
char	**ft_varsconv(t_list *node);
int		ft_cmdsize(t_list *cmd);

t_cmd	*ft_convert(t_list *list)
{
	t_cmd	*cmds;
	int		i;
	
	cmds = (t_cmd *)malloc(sizeof(t_cmd) * (ft_cmdsize(cmd) + 1));
	i = 0;
	while (list)
	{
		cmds[i].vars = ft_varsconv(list);
		if (cmds[i].command == NULL)
		{
			ft_cmdsdel(cmds, i);
			break ;
		}
		cmds[i].list = ft_rediconv(list);
		if (cmds[i].list == NULL)
		{
			ft_varsclear(cmds[i].vars);
			ft_cmdsdel(cmds, i);
			break ;
		}
		i++;
		list = list->next;
	}
	cmds[i] = NULL;
	return (cmds);
}

int	ft_cmdsize(t_list *cmd)
{
	int	size;

	size = 0;
	while (cmd)
	{
		cmd = cmd->next;
		size++;
	}
	return (size);
}

t_list	*ft_rediconv(t_list *node)
{
	t_list	*list;
	t_list	*new;
	t_chunk	*chunk;
	t_chunk	*chunk_new;

	list = NULL;
	while (node)
	{
		chunk = (t_chunk *)(node->content);
		if (!ft_strcmp(chunk->type, "param"))
		{
			chunk_new = ft_chkcopy(chunk);
			if (chunk_new == NULL)
			{
				ft_lstclear(&list, ft_chkdel);
				return (NULL);
			}
			new = ft_lstnew(chunk_new);
			if (new == NULL)
			{
				ft_chkdel(chunk_new);
				ft_lstclear(&list, ft_chkdel);
				return (NULL);
			}
			ft_lstadd_back(&list, new);
		}
		node = node->next;
	}
	return (list);
}

int	ft_vars_size(t_list *node)
{
	t_chunk	*chunk;
	int		size;

	size = 0;
	while (cmd)
	{
		chunk = (t_chunk *)(cmd->content);
		if (ft_strcmp(chunk->type, "param"))
			size++;
		cmd = cmd->next;
	}
	return (size);
}


