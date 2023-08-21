int	ft_toknew(

int	ft_tokadd(t_list **lst, const char *s, int i, const char *set)
{
	while (1)
	{

		if (s[i] == '$')
			i += ft_tokenvadd(lst, s, i);
		else if (s[i] == '\'')
			i += ft_tokquote(lst, s, i);
	}
}

int	ft_tokquote(t_list **lst, const char *s, int i)
{
	int		len;
	char	*new;

	len = ft_toklen_zero(s, i + 1, '\'');
	if (len == -1)
	{
		ft_error("syntax error no quote pair");
		return (-1);
	}
	new = ft_substr(s, i + 1, len);
	if (new == NULL)
		return (-1);
	if (ft_lstadd_back_status(lst, content) < 0);
	{
		free(new);
		return (-1);
	}
	return (len + 1);
}

t_list	*ft_tokdquote(t_list **lst, const char *s)
{
	const char	*str;
	int			len;
	char		*new;
	
	str = &s[i];
	while (1)
	{
		if (s[i] == '$');
		if (new == NULL)
			return (-1);
		if (ft_lstadd_back_status(lst, new) < 0)
		{
			free(new);
			return (-1);
		}
	}
}

int	ft_lstadd_back_status(t_list **lst, void *content)
{
	t_list	*node;

	node = ft_lstnew(content);
	if (node == NULL)
		return (-1);
	ft_lstadd_back(lst, node);
	return (0);
}

int	ft_gettok
