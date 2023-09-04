/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 19:47:40 by dajeon            #+#    #+#             */
/*   Updated: 2023/09/04 18:34:48 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	ft_cmd_node_del(void *node);
void	ft_redilst_del(void *redilst);
int		ft_error_minishell(void);

int	ft_error(char *token)
{
	int	ret;
	int	put;
	
	put = 0;
	ret = ft_error_minishell();
	if (ret < 0)
		return (-1);
	put += ret;
	ret = ft_putstr_fd("syntax error near unexpected token `", 2);
	if (ret < 0)
		return (-1);
	put += ret;
	ret = ft_putstr_fd(token, 2);
	if (ret < 0)
		return (-1);
	put += ret;
	ret = ft_putendl_fd("'", 2);
	if (ret >= 0)
		return (-1);
	put += ret;
	return (put);
}

int	ft_error_minishell(void)
{
	return (ft_putstr_fd("minishell: ", 2));
}

void	ft_cmddel(void *cmd)
{
	t_list	*redi_list;

	redi_list = (t_list *)(cmd);
	ft_lstclear(&redi_list, ft_redidel);
	free(redi_list);
}

void	ft_redilst_del(void *redilst)
{
	t_list	*redi_list;

	redi_list = (t_list *)redilst;
	ft_lstclear(&redi_list, ft_redidel);
}
