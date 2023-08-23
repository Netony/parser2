#include <stdlib.h>
#include "parser.h"

t_redi	*ft_redinew(char *type, char *path)
{
	t_redi	*redi;

	redi = (t_redi *)malloc(sizeof(t_redi));
	if (redi == NULL)
		return (NULL);
	redi->type = type;
	redi->path = path;
	return (redi);
}

void	ft_redidel(void *param)
{
	t_redi	*redi;

	redi = (t_redi *)param;
	free(redi->type);
	free(redi->path);
}

t_redi	*ft_redicopy(t_redi *redi)
{
	t_redi	*copy;
	char	*type;
	char	*path;

	type = ft_strdup(redi->type);
	if (type == NULL)
		return (NULL);
	path = ft_strdup(redi->path);
	if (path == NULL)
	{
		free(type);
		return (NULL);
	}
	copy = ft_redinew(type, path);
	if (copy == NULL)
	{
		free(type);
		free(path);
		return (NULL);
	}
	return (copy);
}
