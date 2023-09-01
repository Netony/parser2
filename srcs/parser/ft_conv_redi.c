/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_redi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 19:43:04 by dajeon            #+#    #+#             */
/*   Updated: 2023/09/01 19:47:20 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	ft_conv_add(t_list **redi_list, t_redi *redi);

char	**ft_conv_vars(t_list *redi_list)
{
	t_redi	*redi;
	char	**vars;
	int		i;

	vars = (char **)malloc(sizeof(char *) * (ft_varslen(redi_list) + 1));
	if (vars == NULL)
		return (NULL);
	i = 0;
	while (redi_list)
	{
		redi = (t_redi *)(redi_list->content);
		if (ft_strcmp(redi->type, "param") == 0)
		{
			vars[i] = ft_strdup(redi->path);
			if (vars[i] == NULL)
			{
				ft_varsdel(vars, i);
				return (NULL);
			}
			i++;
		}
		redi_list = redi_list->next;
	}
	vars[i] = NULL;
	return (vars);
}

t_list	*ft_conv_redi(t_list *redi_list)
{
	t_list	*list;
	t_redi	*node;

	list = NULL;
	while (redi_list)
	{
		node = (t_redi *)(redi_list->content);
		if (ft_strcmp(node->type, "param"))
			ft_conv_add(&list, node);
		redi_list = redi_list->next;
	}
	return (list);
}

int	ft_conv_add(t_list **list, t_redi *redi)
{
	t_redi	*redi_new;
	t_list	*new;

	redi_new = ft_redicopy(redi);
	if (redi_new == NULL)
	{
		ft_lstclear(list, ft_redidel);
		return (-1);
	}
	new = ft_lstnew(redi_new);
	if (new == NULL)
	{
		ft_redidel(redi_new);
		ft_lstclear(list, ft_redidel);
		return (-1);
	}
	ft_lstadd_back(list, new);
	return (0);
}
