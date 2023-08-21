#ifndef CHUNK_H
# define CHUNK_H

typedef struct s_chunk
{
	char	*type;
	char	*text;
}	t_chunk;

t_chunk	*ft_chknew(char *type, char *text);
void	ft_chkdel(void *param);

#endif
