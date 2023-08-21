#include "parser.h"
char	*ft_getenv(const char *s);

char	*ft_env(const char *s, int *i)
{
	int		len;
	char	*temp;
	char	*env;

	*i += 1;
	len = ft_toklen(s, *i, "$\"\' <>|");
	if (len == 0)
	{
		if (s[*i] == '$')
			ft_getenv("$");
		else if (s[*i] == '\0' || s[*i] == ' ')
			return (ft_strdup("$"));
		else
			return (ft_strdup(""));
	}
	temp = ft_substr(s, *i, len);
	if (temp == NULL)
		return (NULL);
	env = ft_getenv(temp);
	free(temp);
	return (env);
}

char	*ft_getenv(const char *s)
{
	(void)s;
	return (ft_strdup("ENV_TEST"));
}

