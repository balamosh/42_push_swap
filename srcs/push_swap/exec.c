/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotherys <sotherys@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 15:36:37 by sotherys          #+#    #+#             */
/*   Updated: 2022/06/24 11:33:29 by sotherys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exec(t_ps *tab, t_ps_cmd cmd, long n, t_bool real)
{
	long	i;

	i = 0;
	while (i < n && !tab->error)
	{
		tab->exec[cmd](tab);
		if (real)
			tab->error = !ft_stack_push_back(&tab->cmds, ft_stack_new(cmd));
		++i;
	}
}
