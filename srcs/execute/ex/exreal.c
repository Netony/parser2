/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exreal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 16:05:17 by seunghy2          #+#    #+#             */
/*   Updated: 2023/08/21 16:05:19 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex.h"

char	**pathset(t_env *envlst)
{
	char	**result;
	char	*temp;
	int		i;
	t_env	*pathnode;

	pathnode = envlst;
	while (ft_strcmp(pathnode->name, "PATH"))
		pathnode = pathnode->next;
	result = ft_split(pathnode->value, ':');
	i = 0;
	while (result[i])
	{
		temp = result[i];
		result[i] = ft_strjoin(temp, "/");
		free(temp);
		i++;
	}
	return (result);
}

char	*pathmkr(char *origin, t_env *envlst)
{
	char	**path;
	char	*result;
	char	*temp;
	int		i;

	path = pathset(envlst);
	result = ft_strdup(origin);
	i = 0;
	while (path[i] && access(result, F_OK))
	{
		free(result);
		result = ft_strjoin(path[i], origin);
		i++;
	}
	twodfree(path);
	if (!(access(result, F_OK)))
		return (result);
	free(result);
	return (0);
}

char	**envpmkr(t_env *envlst)
{
	int		i;
	t_env	*temp;
	char	*middle;
	char	**result;

	i = 0;
	temp = envlst;
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	result = (char **)malloc(sizeof(char *) * (i + 1));
	temp = envlst;
	i = 0;
	while (temp)
	{
		middle = ft_strjoin(temp->name, "=");
		result[i] = ft_strjoin(middle, temp->value);
		free(middle);
		temp = temp->next;
		i++;
	}
	result[i] = NULL;
	return (result);
}

void	exreal(t_exnode *arg, t_env **envlst, int noend, int outpipe)
{
	int		well;
	char	*cmdpath;
	char	**envp;

	if (builtincheck((arg->command)[0]))
		exit(exbuiltin(arg, envlst, noend, outpipe));
	cmdpath = pathmkr((arg->command)[0], *envlst);
	if (!cmdpath)
		errorend();
	dup2(arg->read, 0);
	if (arg->write != 1)
		dup2(arg->write, 1);
	else if (noend)
		dup2(outpipe, 1);
	envp = envpmkr(*envlst);
	well = execve(cmdpath, arg->command, envp);
	if (well == -1)
		errorend();
}
