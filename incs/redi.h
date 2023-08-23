#ifndef REDI_H
# define REDI_H

typedef struct s_redi
{
	char	*type;
	char	*path;
}	t_redi;

t_redi	*ft_redinew(char *type, char *path);
void	ft_redidel(void *param);
t_redi	*ft_redicopy(t_redi *redi);

#endif
