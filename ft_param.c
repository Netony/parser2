char	*ft_param(const char *s, int start, int size)
{
	t_list	*chunks;
	int		i;
	int		len;
	char	*param;
	char	*temp;

	i = 0;
	chunks = NULL;
	while (i < size)
	{
		if (s[start + i] == '$')
			len = ft_envsize(s, start + i);
		else
			len = ft_toklen(s, start + i, "$\"\'|><");
		if (len < 0)
		{
			ft_lstclear(&chunks, ft_chkdel);
			return (-1);
		}
		if (s[start + i] == '$')
			temp = ft_env(s, start, len);
		else
			temp = ft_tok(s, start, len);
		if (temp == NULL)
		{
			ft_lstclear(&chunks, ft_chkdel);
			return (-1);
		}
		ft_lstadd_back_status(&chunks, temp);
		i += len;
	}
	param = ft_lstjoin(chunks);
	ft_lstclear(&chunks, ft_chkdel);
	return (param);

}

char	*ft_lstjoin(t_list *lst)
{
	char	*join;
	char	*new;
	char	*temp;

	join = ft_strdup("");
	while (*lst)
	{
		new = lst->content;
		temp = join;
		join = ft_strjoin(join, new);
		free(temp);
		if (join == NULL)
			return (NULL);
		lst = lst->next;
	}
	return (join);
}
