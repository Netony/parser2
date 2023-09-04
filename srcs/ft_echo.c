/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 16:03:09 by seunghy2          #+#    #+#             */
/*   Updated: 2023/09/04 19:45:29 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_echo(char **command)
{
	int	i;

	i = 1;
	if (!(ft_strcmp(command[i], "-n")))
		i++;
	while (command[i])
	{
		printf("%s", command[i]);
		i++;
		if (command[i])
			printf(" ");
	}
	if (ft_strcmp(command[1], "-n"))
		printf("\n");
	return (0);
}
