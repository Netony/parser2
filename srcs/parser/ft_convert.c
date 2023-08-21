#include "parser.h"

t_cmd	*ft_convert(t_list *cmd)
{
	t_cmd	*new;
	
	
}

int	ft_cmdsize(t_list *list)
{

}

char	**ft_vars(t_list *node)
{
	t_chunk	*chunk;
	char	**vars;
	int		size;
	int		i;

	size = ft_vars_size(cmd);
	vars = (char **)malloc(sizeof(char *) * (size + 1));
	if (vars == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		chunk = (t_chunk *)(cmd->content);
		if (ft_strcmp(chunk->type, "param"))
			vars[i++] = chunk->text;
		cmd = cmd->next;
	}
	vars[i] = NULL;
	return (vars);
}

t_list	*ft_redi(t_list *node)
{
	t_list	*redi;
	t_list	*chunk;

	redi = NULL;
	while (cmd)
	{
		chunk = (t_chunk *)(cmd->content);
		if (!ft_strcmp(chunk->type, "param"))
		{
			ft_
		}
		cmd = cmd->next;
	}
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


