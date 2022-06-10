/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allign.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotherys <sotherys@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 15:09:05 by sotherys          #+#    #+#             */
/*   Updated: 2022/06/10 15:09:06 by sotherys         ###   ########.fr       */
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
