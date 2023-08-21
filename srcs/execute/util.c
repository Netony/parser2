/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 16:03:53 by seunghy2          #+#    #+#             */
/*   Updated: 2023/08/21 18:38:22 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	char	*str1;
	char	*str2;
	size_t	i;
	int		c;

	i = 0;
	str1 = s1;
	str2 = s2;
	if (!s1 && !s2)
		return (0);
	if (!s1)
		str1 = "";
	if (!s2)
		str2 = "";
	while (str1[i] != 0 || str2[i] != 0)
	{
		c = (unsigned char)str1[i] - (unsigned char)str2[i];
		if (c)
			return (c);
		i++;
	}
	return (0);
}

void	twodfree(char **twod)
{
	int	i;

	i = 0;
	while (twod[i])
	{
		free(twod[i]);
		i++;
	}
	free(twod);
}
