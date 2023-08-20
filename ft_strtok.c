char	*ft_new(const char *s, int i, const char *set)
{
	t_list	*list;
	t_list	*new;
	int		len;
	char	*new;

	while (s[i])
	{
		i += ft_duplen(s, i, " ");
		len = ft_toklen(s, i, set);
		new = ft_toknew(s, i, set);
		if (new == NULL)
			ft_lstclear(&list, free);
		i += len;
	}
}

t_list	*ft_toknew(const char *s, int i, const char *set)
{
	int		len;
	char	*token;

	i += ft_duplen(s, i, " ");
	len = ft_toklen(s, i, set);
	token = ft_substr(s, i, len);
	if (token == NULL)
		return (NULL);
	return (ft_lstnew(token));
}
