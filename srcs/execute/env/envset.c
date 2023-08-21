/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 14:15:53 by seunghy2          #+#    #+#             */
/*   Updated: 2023/08/21 14:21:33 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

// 할당 실패 시 에러처리 추가 필요

t_env	*envlist(char **envp)
{
	t_env	*result;
	t_env	**temp;
	size_t	i;

	i = 0;
	result = 0;
	temp = &result;
	while (envp[i + 1])
	{
		*temp = (t_env *)malloc(sizeof(t_env));
		envseparate(envp[i], &((*temp)->name), &((*temp)->value));
		(*temp)->next = 0;
		i++;
		temp = &((*temp)->next);
	}
	return (result);
}
// + OLDPWD value값 할당해제 및 NULL

void	envadd(t_env **envlst, char *nv)
{
	t_env	*envedit;
	char	*name;
	char	*value;

	envseparate(nv, &name, &value);
	envedit = envsearch(*envlst, name);
	if (envedit)
	{
		free(name);
		if (value)
		{
			free(envedit->value);
			envedit->value = value;
		}
	}
	else
	{
		envedit = *envlst;
		*envlst = (t_env *)malloc(sizeof(t_env));
		(*envlst)->name = name;
		(*envlst)->value = value;
		(*envlst)->next = envedit;
	}
}

void	envdelete(t_env **envlst, char *name)
{
	t_env	*temp1;
	t_env	*temp2;

	temp1 = *envlst;
	if (!temp1)
		return ;
	else if (!(ft_strcmp(temp1->name, name)))
	{
		envfree(temp1);
		*envlst = 0;
		return ;
	}
	while (temp1->next && ft_strcmp(temp1->next->name, name))
		temp1 = temp1->next;
	if (!(temp1->next))
		return ;
	temp2 = temp1->next->next;
	envfree(temp1->next);
	temp1->next = temp2;
}
