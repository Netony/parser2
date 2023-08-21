int	ft_toksize(const char *s)
{
	if (*s == '$')
		return (ft_toksize_dollor(s));
	else if (*s == '\"')
		return (ft_toksize_dquote(s));
	else if (*s == '\'')
		return (ft_toksize_quote(s));
	else if (*s == '>' || *s == '<')
		return (ft_toksize_redi(s));
	else if (*s == '|')
		return (-2);
	else
		return (ft_toklen(s, "$\"\'>|<"));
}

t_list	*ft_toknew(const char *s, const char *set)
{
	if (*s == '$')
		return (ft_tokenv(s));
	else if (*s == '\'')
		return (ft_tokquote(s));
	else if (*s == '\"')
		return (ft_tokdquote(s));
	else if (*s == '<' || *s == '>')
		return (ft_tokredi(s));
	else
		return (ft_tokchunk(s, set));
}

int	ft_toksize_dollor(const char *s)
{
	if (s[1] == '$')
		return (2);
	return (ft_toklen(s, " "));
}

char	*ft_tokchunk(const char *s, const char *set)
{
	int	len;

	len = ft_toklen(s, set);

}
