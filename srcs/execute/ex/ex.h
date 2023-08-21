/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 16:04:40 by seunghy2          #+#    #+#             */
/*   Updated: 2023/08/21 16:04:42 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX_h
# define EX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_exnode
{
	int	read;
	int	write;
	char	**command;
}	t_exnode;

typedef struct s_redi
{
	char	*type;
	char	*path;
}	t_redi;

typedef struct s_list
{
	void	*content;
	struct s_list	*next;
}	t_list;

typedef struct s_cmd
{
	t_list	*redilst;
	char	**command;
}	t_cmd;

typedef struct s_env
{
	char	*name;
	char	*value;
	struct s_env	*next;
}	t_env;

void	piping(t_cmd *lst, int size, t_env **envlst);

t_exnode	*exnodeset(t_cmd node, int inpipe);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
int	ft_strcmp(const char *s1, const char *s2);

void	exreal(t_exnode *arg, t_env **envlst, int noend, int outpipe);
char	**ft_split(char const *s, char c);
void	twodfree(char **twod);

int	exbuiltin(t_exnode *arg, t_env **envlst, int noend, int outpipe);

#endif
