/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expipe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 16:05:07 by seunghy2          #+#    #+#             */
/*   Updated: 2023/09/09 19:34:55 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	argfree(t_exnode *arg)
{
	if (arg->read != 0)
		close(arg->read);
	if (arg->write != 1)
		close(arg->write);
	free(arg);
}

void	pidsig(pid_t pid)
{
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
	}
	else
	{
		signal(SIGINT, SIG_IGN);
		signal(SIGQUIT, sigquit_handler);
	}
}

pid_t	nodepipefork(t_cmd origin, int fd[2], t_exnode *arg, pid_t *pid)
{
	pid_t	past;

	past = *pid;
	arg->redilst = origin.redilst;
	arg->read = fd[0];
	arg->write = 1;
	if (pipe(fd) == -1)
	{
		exnodeclose(arg);
		errormsg(MS_ERRNO, 0);
		return (past);
	}
	*pid = fork();
	if (*pid == -1)
	{
		exnodeclose(arg);
		close(fd[0]);
		close(fd[1]);
		errormsg(MS_ERRNO, 0);
		return (past);
	}
	pidsig(*pid);
	return (0);
}

pid_t	expipe(t_exnode *arg, t_cmd *lst, int size, t_env **envlst)
{
	int			fd[2];
	pid_t		pid;
	int			i;
	pid_t		expid;

	i = 0;
	fd[0] = 0;
	pid = -1;
	expid = nodepipefork(lst[i], fd, &(arg[i]), &pid);
	if (expid)
		return (expid);
	while (pid && i < size - 1)
	{
		close(fd[1]);
		exnodeclose(&(arg[i]));
		i++;
		expid = nodepipefork(lst[i], fd, &(arg[i]), &pid);
		if (expid)
			return (expid);
	}
	close(fd[0]);
	if (!pid)
		exreal(&(arg[i]), envlst, size - i - 1, fd[1]);
	exnodeclose(&(arg[i]));
	return (pid);
}

void	piping(t_cmd *lst, int size, t_info *info)
{
	t_exnode	*exlst;
	char		*tmpfilepath;
	pid_t		pid;
	int			i;

	exlst = (t_exnode *)malloc(sizeof(t_exnode) * size);
	tmpfilepath = nonexitpath();
	if (!exlst || !tmpfilepath)
		errormsg(MS_MALLOC, 0);
	i = 0;
	while (i < size)
	{
		(exlst[i]).command = (lst[i]).command;
		(exlst[i]).tmpfilepath = tmpfilepath;
		i++;
	}
	if (exlst && tmpfilepath)
		info->lastpid = expipe(exlst, lst, size, &(info->envlst));
	if (exlst && tmpfilepath && info->lastpid > 0)
		waitpid(info->lastpid, &(info->status), 0);
	exlstfree(exlst, size);
	unlink(tmpfilepath);
	free(tmpfilepath);
	pid = 1;
	while (pid != -1)
	{
		signal(SIGINT, handler);
		signal(SIGQUIT, SIG_IGN);
		pid = waitpid(0, 0, WNOHANG);
	}
}
