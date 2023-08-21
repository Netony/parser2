#ifndef CHUNK_H
# define CHUNK_H

typedef struct s_chunk
{
	char	*type;
	char	*content;
}	t_chunk;

t_chunk	*ft_chknew(const char *type, const char *content);
void	ft_chkdel(t_chunk *chk);

#endif
