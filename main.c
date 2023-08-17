#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

typedef struct s_cmd
{
	char	**vars;
	t_list	*redi_lst;
}	t_cmd;

typedef struct s_redi
{
	char	*type;
	char	*path;
}

int	main(void)
{
	open("d", O_WRONLY | O_TRUNC);
	return (0);
}

int	parse(const char *str)
{
	t_list	*cmd;
	t_list	*redi;
	t_list	*chunk;
	int		i;

	i = 0;
	while (1)
	{
		while (str[i] == ' ')
			i++;
		if (str[i] == '>' || str[i] == '<')
		{
			redi = ft_redinew();
			if (redi == NULL)
				;
			i += ft_redisize();
			ft_lstadd_back(&(cmd->redi), redi);
		}
		else
		{
			chunk = ft_chunknew();
			i += ft_chunksize();
		}
	}
}

t_list	*ft_redinew(char *redi)
{
	int	i;
	int	write;

	i = 0;
	write = 0;
	while (redi[i] == ">|<")

}

t_list	*ft_getchunk(char *s)
{
	int		i;
	int		ret;
	t_list	*new;
	t_list	*lst;

	lst = NULL;
	while (1)
	{
		i = 0;
		j = ft_toklen(s + i, " $<>\"\'|");
		ft_substr_end(s, i, j);
		if (ft_isin(s[j], "\"\'$"))
		{
		else
			break ;

	}
}

int	ft_special(t_list **chunks, char *s)
{
	t_list	*new;
	int		ret;

	ret = 0;
	if (s[j] == '\"')
		new = ft_dquote(lst);
	else if (s[j] == '\'')
		new = ft_quote(lst);
	else if (s[j] == '$')
		new = ft_env();
	if (new == NULL)
		return ();
	return ();
}

char	*ft_lstjoin(t_list *lst)
{
	char	*join;
	char	*temp;

	join = NULL;
	while (lst)
	{
		temp = join;
		join = ft_strjoin(temp, lst->content);
		free(temp);
		if (join == NULL)
			return (NULL);
		lst = lst->next;
	}
	return (join);
}

