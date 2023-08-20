int	ft_toklen_zero(const char *s, int start, const char *set);

int	ft_isin(int c, const char *set);

t_list	*ft_cmdlst(const char *s)
{
	t_list	*cmds;
	int	i;
	int	len;

	i = 0;
	while (1)
	{
		i = ft_duplen(s, i, " ");
		len = ft_getsize(s, i);
		if (len < 0)
			end();
		ft_getchunk(s, i, len);
		i += len;
	}
}

int	ft_getsize(const char *s, int i, int flag)
{
	if (ft_isin(s[i], "<>") && flag >= 1)
		;
	else if (ft_isin(s[i], "|") && flag >= 1)
		;
	else if (s[i] == '$' && flag <= 1)
		;
	else if (s[i] == '\\' && flag <= 1)
		;
	else if (s[i] == '\"' && flag == 0)
		;
	else if (s[i] == '\'' && flag == 0)
		;
	else if (s[i] == '\0')
		;
	return (0);
}

t_list	*ft_getchunk(const char *s, int i)
{

}

t_list	*ft_chunk(const char *s, int i, int j)
{
	char	*content;

	content = ft_substr(s, i, j - i);
	if (content == NULL)
		return (NULL);
	return (ft_lstnew(content));
}

t_list	*ft_dquote(const char *s, int i, int, j)
{
	int	len;

	len = ft_toklen_zero(s, start, "\"");
}

t_list	*ft_redinew(const char *s, int start, int end)
{
	
}

int	ft_toklen(const char *s, int start, const char *set)
{
	int	len;

	len = 0;
	while (s[start + len])
	{
		if (ft_isin(s[start + len], set))
			return (len);
		len++;
	}
	return (len);
}

int	ft_toklen_zero(const char *s, int start, const char *set)
{
	int	len;

	len = 0;
	while (s[start + len])
	{
		if (ft_isin(s[start + len], set))
			return (len);
		len++;
	}
	return (-1);
}

int	ft_isin(int c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i++])
			return (1);
	}
	return (0);
}
