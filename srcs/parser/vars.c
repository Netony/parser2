#include "parser.h"

int	ft_varsdel(char **vars, int size)
{
	int	i;

	i = 0;
	while (i < size)
		free(vars[i++]);
	free(vars);
	return (0);
}

int	ft_varsclear(char **vars)
{
	int	i;

	i = 0;
	while (vars[i])
		free(vars[i++]);
	free(vars);
}

char	**ft_varsconv(t_list *node)
{
	t_chunk	*chunk;
	char	**vars;
	int		i;

	vars = (char **)malloc(sizeof(char *) * (ft_vars_size(cmd) + 1));
	if (vars == NULL)
		return (NULL);
	i = 0;
	while (chunk)
	{
		chunk = (t_chunk *)(cmd->content);
		if (ft_strcmp(chunk->type, "param"))
		{
			vars[i] = ft_strdup(chunk->text);
			if (vars[i] == NULL)
			{
				ft_varsdel(vars, i);
				return (NULL);
			}
			i++;
		}
		cmd = cmd->next;
	}
	vars[i] = NULL;
	return (vars);
}
