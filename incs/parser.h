#ifndef PARSER_H
# define PARSER_H

#include <stdio.h>
#include "../libft/incs/libft.h"
#include "redi.h"

typedef struct s_cmd
{
	t_list	*redilst;
	char	**command;
}	t_cmd;

int		ft_cmdsdel(t_cmd *cmds, int size);
int		ft_cmdsclear(t_cmd *cmds);

int		ft_cmdsize(t_list *cmd);
void	ft_cmddel(void *lst);
int		ft_error(void);

t_list	*parser(const char *s);
t_list	*ft_parse_cmd_node(const char *s, int *i);
t_list	*ft_parse_cmd_list(const char *s, int *i);

t_list	*ft_parse_redi_list(const char *s, int *i);
t_list	*ft_parse_redi_node(const char *s, int *i);

char	*ft_parse_path(const char *s, int *i);
char	*ft_parse_type(const char *s, int *i);
char	*ft_parse_type_set(const char *s, int *i);

t_list	*ft_parse_text_list(const char *s, int *i);
t_list	*ft_parse_text_node(const char *s, int *i);

char	*ft_parse_tok(const char *s, int *i, const char *set);
char	*ft_parse_env(const char *s, int *i);
char	*ft_parse_dquote(const char *s, int *i);
t_list	*ft_parse_dquote_node(const char *s, int *i);
char	*ft_parse_quote(const char *s, int *i);

char	*ft_lstjoin(t_list *lst);

int		ft_isin(int a, const char *set);
int		ft_toklen(const char *s, int start, const char *set);
int		ft_toklen_zero(const char *s, int start, const char *set);
int		ft_strcmp(char *s1, char *s2);
int		ft_duplen(const char *s, int start, const char *set);

t_cmd	*ft_convert(t_list *list);
t_list	*ft_conv_redi(t_list *redi_list);
char	**ft_conv_vars(t_list *node);
int		ft_varslen(t_list *node);
int		ft_varsclear(char **vars);
int		ft_varsdel(char **vars, int size);
#endif
