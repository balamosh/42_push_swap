/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allign.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balamosh <balamosh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 12:39:41 by balamosh          #+#    #+#             */
/*   Updated: 2022/06/10 12:39:54 by balamosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ps_allign(t_ps *tab)
{
	long	i;
	long	ir;
	t_snode	*curr;

	i = 0;
	curr = tab->a.head;
	while (curr)
	{
		if (curr->index == 0)
			break ;
		++i;
		curr = curr->next;
	}
	ir = ft_abs(i - tab->a.size);
	if (ir < i)
		ft_exec(tab, RRA, ir, TRUE);
	else
		ft_exec(tab, RA, i, TRUE);
}
