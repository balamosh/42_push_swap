/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotherys <sotherys@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 15:09:25 by sotherys          #+#    #+#             */
/*   Updated: 2022/06/10 15:09:27 by sotherys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_ps_btoa_try(t_ps *tab, long ia, long ib)
{
	long	min_ops;
	long	co_dir;

	co_dir = 0;
	if ((ia * ib) >= 0)
	{
		min_ops = ft_max(ft_abs(ia), ft_abs(ib));
		co_dir = ft_lsign(ia) * ft_min(ft_abs(ia), ft_abs(ib));
	}
	else
		min_ops = ft_abs(ia) + ft_abs(ib);
	if (min_ops < tab->min_ops)
	{
		tab->min_ops = min_ops;
		tab->co_dir = co_dir;
		tab->ia = ia - co_dir;
		tab->ib = ib - co_dir;
	}
}

static void	ft_ps_btoa_update(t_ps *tab, long ia, long ib)
{
	ft_ps_btoa_try(tab, ia, ib);
	ft_ps_btoa_try(tab, ia - tab->a.size, ib);
	ft_ps_btoa_try(tab, ia, ib - tab->b.size);
	ft_ps_btoa_try(tab, ia - tab->a.size, ib - tab->b.size);
}

static void	ft_ps_btoa_find(t_ps *tab)
{
	long	ia;
	long	ib;
	t_snode	*curr;

	curr = tab->b.head;
	ib = 0;
	ia = ft_ps_insert_pos(&tab->a, curr->val);
	tab->min_ops = ia;
	tab->co_dir = 0;
	tab->ia = ia;
	tab->ib = ib;
	ft_ps_btoa_update(tab, ia, ib);
	while ((size_t)ib < tab->b.size)
	{
		ia = ft_ps_insert_pos(&tab->a, curr->val);
		ft_ps_btoa_update(tab, ia, ib);
		++ib;
		curr = curr->next;
	}
}

void	ft_ps_btoa(t_ps *tab)
{
	while (tab->b.size > 0)
	{
		ft_ps_btoa_find(tab);
		if (tab->co_dir < 0)
			ft_exec(tab, RRR, -tab->co_dir, TRUE);
		else
			ft_exec(tab, RR, tab->co_dir, TRUE);
		if (tab->ia < 0)
			ft_exec(tab, RRA, -tab->ia, TRUE);
		else
			ft_exec(tab, RA, tab->ia, TRUE);
		if (tab->ib < 0)
			ft_exec(tab, RRB, -tab->ib, TRUE);
		else
			ft_exec(tab, RB, tab->ib, TRUE);
		ft_exec(tab, PA, 1, TRUE);
	}
}
