t_list	*ft_dolnew(const char *s, int i, const char *set)
{
	char	*setnew;

	if (s[i] == '$')
		i++;
	setnew = ft_strjoin(set, " ");
	ft_toknew(s, i, setnew);
}
