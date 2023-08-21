t_list	*ft_cmdsnew(const char *s)
{
	t_list	*cmds;
	int		i;
	t_list	*new;
}

t_list	*parse_redi(const char *s)
{
	
}

t_list	*parse_param(const char *s)
{
	
}

t_list	*ft_spec(const char *s)
{

}

t_list	*ft_dquote(const char *s)
{
	
}

t_chunk	*ft_param(const char *s)
{
	t_list	*param;


}

char	*ft_content(const char *s, int start, int end, const char *set)
{
	t_list	*chunk;
	int		ret;

	chunk = NULL;
	while (start < end)
	{
		ret = 
	}
}


t_list	*ft_chunk(const char *s, int *i, const char *set)
{
	t_list	*node;
	char	*new;
	int		len;

	len = ft_toklen(s, *i, set);
	ft_substr(s, *i, len);
	*i += len;
	return 
}
