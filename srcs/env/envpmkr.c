/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envpmkr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:49:24 by seunghy2          #+#    #+#             */
/*   Updated: 2023/08/23 16:16:39 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	envsize(t_env *envlst)
{
	int		result;
	t_env	*temp;

	result = 0;
	temp = envlst;
	while (temp)
	{
		temp = temp->next;
		result++;
	}
	return (result);
}

char	**envpmkr(t_env *envlst)
{
	int		i;
	char	*middle;
	char	**result;
	t_env	*temp;

	i = envsize(envlst);
	result = (char **)malloc(sizeof(char *) * (i + 1));
	if (!result)
		return (0);
	temp = envlst;
	i = 0;
	while (temp)
	{
		if (temp->value)
		{
			middle = ft_strjoin(temp->name, "=");
			result[i] = ft_strjoin(middle, temp->value);
			free(middle);
			if (!(result[i]))
			{
				twodfree(result);
				return (0);
			}
			i++;
		}
		temp = temp->next;
	}
	result[i] = NULL;
	return (result);
}
