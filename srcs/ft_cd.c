/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 13:14:30 by seunghy2          #+#    #+#             */
/*   Updated: 2023/09/09 13:22:11 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*envsearchadd(t_env **envlst, char *name)
{
	t_env	*result;

	result = envsearch(*envlst, name);
	if (!result)
	{
		if (envadd(envlst, name))
			return (NULL);
		result = envsearch(*envlst, name);
	}
	return (result);
}

int	pwdchange(t_env **envlst)
{
	t_env	*oldpwd;
	t_env	*pwd;
	char	*present;

	present = getcwd(NULL, 0);
	if (!present)
		return (MS_ERRNO);
	oldpwd = envsearchadd(envlst, "OLDPWD");
	if (!oldpwd)
		return (MS_MALLOC);
	free(oldpwd->value);
	pwd = envsearchadd(envlst, "PWD");
	if (!pwd)
		return (MS_MALLOC);
	oldpwd->value = pwd->value;
	pwd->value = present;
	if (!(oldpwd->value))
		oldpwd->value = ft_strdup("");
	if (!(oldpwd->value))
		return (MS_MALLOC);
	return (MS_SUCCESS);
}

int	ft_cd(char **command, t_env **envlst)
{
	int		result;
	t_env	*home;

	if (command[1])
		result = chdir(command[1]);
	else
	{
		home = envsearch(*envlst, "HOME");
		result = chdir(home->value);
	}
	if (result == -1)
	{
		if (command[1])
			errormsg(MS_ERRNO, command[1]);
		else
			errormsg(MS_ERRNO, 0);
		return (1);
	}
	result = pwdchange(envlst);
	if (result)
	{
		errormsg(result, 0);
		return (1);
	}
	return (0);
}
