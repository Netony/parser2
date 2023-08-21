#include <stdlib.h>
#include "chunk.h"

t_chunk	*ft_chknew(char *type, char *text)
{
	t_chunk	*chk;

	chk = (t_chunk *)malloc(sizeof(t_chunk));
	if (chk == NULL)
		return (NULL);
	chk->type = type;
	chk->text = text;
	return (chk);
}

void	ft_chkdel(void *param)
{
	t_chunk	*chk;

	chk = (t_chunk *)param;
	free(chk->type);
	free(chk->text);
}
