#include <stdlib.h>
#include "chunk.h"

t_chunk	*ft_chknew(const char *type, const char *content)
{
	t_chunk	*chk;

	chk = (t_chunk *)malloc(sizeof(t_chunk));
	if (chk == NULL)
		return (NULL);
	chk->type = type;
	chk->type = content;
	return (chk);
}

void	ft_chkdel(t_chunk *chk)
{
	free(chk->type);
	free(chk->content);
	return (0);
}
