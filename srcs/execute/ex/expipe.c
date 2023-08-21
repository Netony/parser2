/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expipe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 16:05:07 by seunghy2          #+#    #+#             */
/*   Updated: 2023/08/21 18:43:18 by seunghy2         ###   ########.fr       */
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

void	piping(t_cmd *lst, int size, t_env **envlst)
{
	t_exnode	*arg;
	int			fd[2];
	pid_t		pid;
	int			i;

	i = 0;
	arg = exnodeset(lst[i], 0);
	if (pipe(fd) == -1)
		errnoend();
	pid = fork();
	while (pid && i < size - 1)
	{
		if (pid == -1)
			errorend();
		close(fd[1]);
		argfree(arg);
		i++;
		arg = exnodeset(lst[i], fd[0]);
		if (pipe(fd) == -1)
			errnoend();
		pid = fork();
	}
	close(fd[0]);
	if (!pid)
		exreal(arg, envlst, size - i - 1, fd[1]);
	argfree(arg);
	waiting();
}
// size 1인데 builtin 인 경우는 따로 분리.
