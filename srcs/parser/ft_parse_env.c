/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 19:47:49 by dajeon            #+#    #+#             */
/*   Updated: 2023/09/04 19:16:09 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		env_getkey(char **key, const char *s, int *i);
char	*env_getval(t_info *info, char *key);
char	*env_getfrominfo(t_info *info, char *key);

char	*ft_parse_env(t_info *info, const char *s, int *i)
{
	char	*val;
	char	*key;

	if (env_getkey(&key, s, i) < 0)
		return (NULL);
	val = env_getval(info, key);
	free(key);
	if (val == NULL)
		return (NULL);
	return (val);
}

int	env_getkey(char **key, const char *s, int *i)
{
	int		len;

	*i += 1;
	len = ft_toklen(s, *i, "\"\' <|>?!$");
	if (len == 0)
	{
		if (ft_isin(s[*i], " <|>"))
		{
			*key = NULL;
			return (0);
		}
		else if (ft_isin(s[*i], "\"\'"))
			*key = ft_substr(s, *i, 0);
		else if (ft_isin(s[*i], "!?$"))
			*key = ft_substr(s, *i, 1);
		*i += 1;
	}
	else
	{
		*key = ft_substr(s, *i, len);
		*i += len;
	}
	if (*key == NULL)
		return (-1);
	return (0);
}

char	*env_getval(t_info *info, char *key)
{
	if (key == NULL)
		return (ft_strdup("$"));
	else if (key[0] == '\0')
		return (ft_strdup(""));
	else if (ft_strcmp(key, "$") == 0)
		return (ft_strdup(""));
	else if (ft_strcmp(key, "?") == 0)
		return (ft_itoa(info->status));
	else if (ft_strcmp(key, "!") == 0)
		return (ft_itoa(info->lastpid));
	else
		return (env_getfrominfo(info, key));
}

char	*env_getfrominfo(t_info *info, char *key)
{
	t_env	*node;
	
	if (key == NULL)
		return (ft_strdup(""));
	else if (key[0] == '\0')
		return (ft_strdup(""));
	node = envsearch(info->envlst, key);
	if (node == NULL || node->value == NULL)
		return (ft_strdup(""));
	return (ft_strdup(node->value));
}
