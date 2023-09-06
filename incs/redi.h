/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redi.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 11:08:17 by dajeon            #+#    #+#             */
/*   Updated: 2023/09/06 11:08:33 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDI_H
# define REDI_H

typedef struct s_redi
{
	char	*type;
	char	*path;
}	t_redi;

t_redi	*ft_redinew(char *type, char *path);
void	ft_redidel(void *param);
t_redi	*ft_redicopy(t_redi *redi);

#endif
