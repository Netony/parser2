t_redi	*ft_redinew(const char *s, int i)
{
	t_redi	*new;
	char	*type;
	char	*path;
	int		len;
	
	len = ft_redilen(s, i);
	type = ft_reditype(s[i], len);
	if (type == NULL)
		return (NULL);
	if (ft_strcmp(type, "error") == 0)
	{
		free(type);
		return (NULL);
	}
	i += len;
	path = ft_strtok(type, i, " ><|");
	if (


}

int	ft_redilen(const char *s, int i)
{
	int	len;

	if (s[i] == '>')
		len = ft_duplen(s, i, ">");
	else if (s[i] == '<')
		len = ft_duplen(s, i, "<");
	else
		len = -1;
	return (len);
}

char	*ft_reditype(char type, int len)
{
	if (type == '<')
	{
		if (len == 1)
			return (ft_strdup("infile"));
		else if (len >= 2)
			return (ft_strdup("here_doc"));
	}
	else if (type == '>')
	{
		if (len == 1)
			return (ft_strdup("outfile"));
		else if (len >= 2)
			return (ft_strdup("append"));
	}
	return (ft_strdup("error"));
}
