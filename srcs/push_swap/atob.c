/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atob.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotherys <sotherys@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 15:09:13 by sotherys          #+#    #+#             */
/*   Updated: 2022/06/10 15:09:15 by sotherys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ps_atob(t_ps *tab)
{
	int	old_tail;

	old_tail = tab->a.tail->val;
	while ((tab->a.head->val != old_tail) && (tab->keep_cnt < tab->a.size))
	{
		if (!tab->a.head->keep)
			ft_exec(tab, PB, 1, TRUE);
		else
			ft_exec(tab, RA, 1, TRUE);
	}
	if (!tab->a.head->keep)
		ft_exec(tab, PB, 1, TRUE);
}
