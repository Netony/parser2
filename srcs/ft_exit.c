/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 15:39:32 by seunghy2          #+#    #+#             */
/*   Updated: 2023/08/24 16:48:16 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_exit(char **command)
{
	int	temp;
	unsigned char	result;

	result = 0;
	if (command && command[1])
	{
		temp = ft_atoi(command[1]);
		result = (unsigned char)temp;
	}
	exit(result);
}
