/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 19:42:56 by dajeon            #+#    #+#             */
/*   Updated: 2023/09/01 19:43:02 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	ft_redilst_del(void *redilst);

int	ft_cmdsdel(t_cmd *cmds, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_redilst_del(cmds[i].redilst);
		i++;
	}
	free(cmds);
	return (0);
}

int	ft_cmdsize(t_list *cmd)
{
	int	size;

	size = 0;
	while (cmd)
	{
		cmd = cmd->next;
		size++;
	}
	return (size);
}
