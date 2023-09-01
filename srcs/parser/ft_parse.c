/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 19:47:43 by dajeon            #+#    #+#             */
/*   Updated: 2023/09/01 19:47:44 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_list	*parser(const char *s)
{
	int	i;

	i = 0;
	i += ft_duplen(s, i, " ");
	if (s[i] == '|')
	{
		ft_error();
		return (NULL);
	}
	return (ft_parse_cmd_list(s, &i));
}

t_list	*ft_parse_cmd_list(const char *s, int *i)
{
	t_list	*node;
	t_list	*list;

	list = NULL;
	while (1)
	{
		i += ft_duplen(s, *i, " ");
		if (s[*i] == '\0')
			break ;
		node = ft_parse_cmd_node(s, i);
		if (node == NULL)
		{
			ft_lstclear(&list, ft_cmddel);
			return (NULL);
		}
		ft_lstadd_back(&list, node);
	}
	return (list);
}

t_list	*ft_parse_cmd_node(const char *s, int *i)
{
	t_list	*redi_list;
	t_list	*cmd_node;

	if (s[*i] == '|')
		*i += 1;
	*i += ft_duplen(s, *i, " ");
	if (s[*i] == '\0' || s[*i] == '|')
		return (NULL);
	redi_list = ft_parse_redi_list(s, i);
	if (redi_list == NULL)
		return (NULL);
	cmd_node = ft_lstnew(redi_list);
	if (cmd_node == NULL)
	{
		ft_lstclear(&redi_list, ft_redidel);
		return (NULL);
	}
	return (cmd_node);
}
