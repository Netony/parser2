#include "parser.h"

int	ft_envsize(const char *s, int start)
{
	int	size;
	int	ret;

	size = 1;
	if (s[1] == '$')
		return (2);
	size += ft_toklen(s, start + size, " $\"\'|><");
	return (size);
}

char	*ft_env(const char *s, int start, int size)
{
	char	*temp;
	char	*env;

	if (size == 1)
		return (ft_strdup("$"));
	temp = ft_substr(s, start, size);
	if (temp == NULL)
		return (NULL);
	env = ft_getenv(temp);
	free(temp);
	return (env);
}

char	*ft_getenv(const char *s)
{
	return (ft_strdup("ENV_TEST"));
}

