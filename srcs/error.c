/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 19:10:16 by seunghy2          #+#    #+#             */
/*   Updated: 2023/09/06 10:50:12 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	errormsg(int errorcode, char *msg)
{
	if (errorcode == MS_ERRNO)
	{
		if (msg)
		{
			ft_putstr_fd("minishell: ", 2);
			perror(msg);
		}
		else
			perror("minishell");
	}
	else if (errorcode == MS_MALLOC)
		ft_putendl_fd("malloc error", 2);
	else if (errorcode == MS_MANUAL)
		ft_putstr_fd(msg, 2);
}

void	errorend(int errorcode, char *msg, int exitcode)
{
	errormsg(errorcode, msg);
	exit(exitcode);
}
