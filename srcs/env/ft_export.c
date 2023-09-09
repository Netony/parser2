/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 14:16:03 by seunghy2          #+#    #+#             */
/*   Updated: 2023/09/09 14:38:16 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*exponvmkr(t_env *node)
{
	char	*middle;
	char	*middle2;
	char	*result;

	if (!(node->value))
		return (ft_strdup(node->name));
	middle = ft_strjoin(node->name, "=\"");
	if (!middle)
		return (0);
	middle2 = ft_strjoin(middle, node->value);
	free(middle);
	if (!middle2)
		return (0);
	result = ft_strjoin(middle2, "\"");
	free(middle2);
	return (result);
}

char	**expomkr(t_env *envlst)
{
	int		i;
	char	**result;
	t_env	*temp;

	result = (char **)malloc(sizeof(char *) * (envsize(envlst) + 1));
	if (!result)
		return (0);
	temp = envlst;
	i = 0;
	while (temp)
	{
		result[i] = exponvmkr(temp);
		if (!(result[i]))
		{
			twodfree(result);
			return (0);
		}
		i++;
		temp = temp->next;
	}
	result[i] = NULL;
	return (result);
}

char	**exposort(t_env *envlst)
{
	char	*temp;
	char	**result;
	int		i;
	int		size;

	size = envsize(envlst);
	result = expomkr(envlst);
	if (!result)
		return (NULL);
	while (--size)
	{
		i = 0;
		while (i < size)
		{
			if (ft_strcmp(result[i], result[i + 1]) > 0)
			{
				temp = result[i];
				result[i] = result[i + 1];
				result[i + 1] = temp;
			}
			i++;
		}
	}
	return (result);
}

int	ft_export(char **command, t_env **envlst)
{
	int		i;
	char	**expo;

	i = 0;
	while (command[++i])
	{
		if (envadd(envlst, command[i]))
		{
			errormsg(MS_MALLOC, 0);
			return (1);
		}
	}
	if (i > 1)
		return (0);
	expo = exposort(*envlst);
	if (!expo)
	{
		errormsg(MS_MALLOC, 0);
		return (1);
	}
	i = -1;
	while (expo[++i])
		printf("%s\n", expo[i]);
	twodfree(expo);
	return (0);
}
