/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expipe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 16:05:07 by seunghy2          #+#    #+#             */
/*   Updated: 2023/08/22 15:20:33 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	waiting(void)
{
	pid_t	pid;

	pid = 1;
	while (pid != -1)
		pid = waitpid(0, 0, WNOHANG);
}

void	argfree(t_exnode *arg)
{
	if (arg->read != 0)
		close(arg->read);
	if (arg->write != 1)
		close(arg->write);
	free(arg);
}

int	nodepipefork(t_cmd origin, int fd[2], t_exnode **arg, pid_t *pid)
{
	*arg = exnodeset(origin, fd[0]);
	if (!(*arg))
		return (MS_PAST);
	if (pipe(fd) == -1)
	{
		free(arg);
		return (MS_ERRNO);
	}
	*pid = fork();
	if (*pid == -1)
	{
		free(arg);
		return (MS_ERRNO);
	}
	return (MS_SUCCESS);
}

int	expipe(t_cmd *lst, int size, t_env **envlst)
{
	t_exnode	*arg;
	int			fd[2];
	pid_t		pid;
	int			i;
	int			errorcode;

	i = 0;
	fd[0] = 0;
	errorcode = nodepipefork(lst[i], fd, *arg, *pid);
	if (errorcode)
		return (errorcode);
	while (pid && i < size - 1)
	{
		close(fd[1]);
		free(arg);
		i++;
		errorcode = nodepipefork(lst[i], fd, *arg, *pid);
		if (errorcode)
			return (errorcode);
	}
	close(fd[0]);
	if (!pid)
		exreal(arg, envlst, size - i - 1, fd[1]);
	free(arg);
	return (MS_SUCCESS);
}

void	piping(t_cmd *lst, int size, t_env **envlst)
{
	int	errorcode;

	errorcode = expipe(lst, size, envlst);
	if (errorcode)
		errormsg(errorcode, 0);
	waiting();
}
