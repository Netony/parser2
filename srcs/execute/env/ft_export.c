/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 14:16:03 by seunghy2          #+#    #+#             */
/*   Updated: 2023/08/21 18:37:38 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_export(char **command, t_env **envlst)
{
	int	i;
	t_env	*temp;

	i = 1;
	while (command[i])
	{
		envadd(envlst, command[i]);
		i++;
	}
	if (i == 1)
	{
		temp = *envlst;
		while (temp)
		{
			printf("%s", temp->name);
			if (temp->value)
				printf("=%s", temp->value);
			printf("\n");
			temp = temp->next;
		}
	}
	return (0);
}
