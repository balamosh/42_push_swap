/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atob.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balamosh <balamosh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 12:31:43 by balamosh          #+#    #+#             */
/*   Updated: 2022/06/10 12:41:03 by balamosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ps_atob(t_ps *tab)
{
	int	old_tail;

	old_tail = tab->a.tail->val;
	while (tab->a.head->val != old_tail)
	{
		if (!tab->a.head->keep)
			ft_exec(tab, PB, 1, TRUE);
		else
			ft_exec(tab, RA, 1, TRUE);
	}
	if (!tab->a.head->keep)
		ft_exec(tab, PB, 1, TRUE);
}
