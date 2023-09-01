/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 19:47:24 by dajeon            #+#    #+#             */
/*   Updated: 2023/09/01 19:47:37 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_list	*ft_redi(t_list *cmd);
char	**ft_varsconv(t_list *node);
int		ft_cmdsize(t_list *cmd);

t_cmd	*ft_convert(t_list *cmd_list)
{
	t_cmd	*cmds;
	t_list	*redi_list;
	int		i;

	cmds = (t_cmd *)malloc(sizeof(t_cmd) * ft_cmdsize(cmd_list));
	if (cmds == NULL)
		return (NULL);
	i = 0;
	while (cmd_list)
	{
		redi_list = cmd_list->content;
		cmds[i].command = ft_conv_vars(redi_list);
		if (cmds[i].command == NULL)
		{
			ft_cmdsdel(cmds, i);
			break ;
		}
		cmds[i].redilst = ft_conv_redi(redi_list);
		i++;
		cmd_list = cmd_list->next;
	}
	return (cmds);
}
