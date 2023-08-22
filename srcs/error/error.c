/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 19:10:16 by seunghy2          #+#    #+#             */
/*   Updated: 2023/08/22 19:12:16 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	errormsg(int errorcode, char *msg)
{
	if (errorcode == MS_ERRNO)
	{
		perror("minishell :");
		if (msg)
			ft_putendl_fd(msg, 2);
	}
}

void	errorend(int errorcode, char *msg)
{
	errormsg(errorcode, msg);
	exit(-1);
}
