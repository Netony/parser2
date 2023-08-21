/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envutil.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 14:15:37 by seunghy2          #+#    #+#             */
/*   Updated: 2023/08/21 18:52:01 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// 할당 실패 시 에러처리 추가 필요
 
void	envseparate(char *nv, char **name, char **value)
{
	char	*str;
	char	*temp;

	str = ft_strdup(nv);
	temp = ft_strchr(str, '=');
	if (temp)
	{
		*temp = '\0';
		*value = temp + 1;
		temp = str;
		*name = ft_strdup(temp);
		temp = *value;
		*value = ft_strdup(temp);
		free(str);
	}
	else
	{
		*name = str;
		*value = 0;
	}
}

t_env	*envsearch(t_env *envlst, char *name)
{
	t_env	*temp;

	temp = envlst;
	while (temp && ft_strcmp(temp->name, name))
		temp = temp->next;
	return (temp);
}

void	envfree(t_env *node)
{
	if (!node)
		return ;
	free(node->name);
	free(node->value);
	free(node);
}
