/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 11:08:09 by seunghy2          #+#    #+#             */
/*   Updated: 2023/09/06 11:08:10 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "parser.h"
# include "execute_env.h"
# include "execute_ex.h"
# include "execute_util.h"
# include "error.h"
# include "../libft/incs/libft.h"
# include <readline/history.h>
# include <readline/readline.h>
# include <termios.h>

int		ft_termexit(t_info *info);
int		ft_termset(t_info *info, int argc, char **argv, char **envp);
void	handler(int signum);
void	sigquit_handler(int sigquit);

#endif
