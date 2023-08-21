#ifndef PARSER_H
# define PARSER_H

#include <stdio.h>
#include "libft/incs/libft.h"
#include "chunk.h"
#include "test.h"

int	ft_error(void);
void	ft_cmddel(void *lst);
int	ft_pipe_check(const char *s, int *i);

int	ft_isin(int a, const char *set);
int	ft_toklen(const char *s, int start, const char *set);
int	ft_toklen_zero(const char *s, int start, const char *set);
int	ft_duplen(const char *s, int start, const char *set);

t_list	*parser(const char *s);
t_list	*ft_cmd(const char *s, int *i);
t_list	*ft_chunks(const char *s, int *i);
t_chunk	*ft_chunk(const char *s, int *i);
char	*ft_text(const char *s, int *i);
char	*ft_type(const char *s, int *i);
t_list	*ft_text_parse(const char *s, int *i);
char	*ft_tok(const char *s, int *i);
char	*ft_env(const char *s, int *i);
char	*ft_lstjoin(t_list *lst);

#endif
