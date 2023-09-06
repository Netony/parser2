/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 11:08:09 by seunghy2          #+#    #+#             */
/*   Updated: 2023/09/06 20:36:46 by dajeon           ###   ########.fr       */
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

int		ft_terminit(t_info *info, char **envp);
int		ft_termexit(t_info *info);

int		ft_termset(void);
int		ft_termunset(void);

int		ft_infoinit(t_info *info, char **envp);

void	handler(int signum);
void	sigquit_handler(int sigquit);

#endif
