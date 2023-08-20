#ifndef PARSER_H
# define PARSER_H

#include <stdio.h>
#include "libft/incs/libft.h"

typedef struct s_cmd
{
	char	**vars;
	t_list	*redis;
}	t_cmd;

typedef struct s_redi
{
	char	*type;
	char	*path;
}	t_redi;

int	ft_isin(int a, const char *set);
int	ft_toklen(const char *s, int start, const char *set);
int	ft_toklen_zero(const char *s, int start, const char *set);
int	ft_duplen(const char *s, int start, const char *set);

#endif
