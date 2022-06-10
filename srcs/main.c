/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balamosh <balamosh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 23:37:22 by sotherys          #+#    #+#             */
/*   Updated: 2022/06/10 03:24:41 by balamosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_ps_test_print(t_ps *tab)
{
	t_snode	*curr_a;
	t_snode	*curr_b;

	curr_a = tab->a.head;
	curr_b = tab->b.head;
	printf("\n");
	while (curr_a || curr_b)
	{
		if (curr_a)
		{
			printf("%-5d", curr_a->val);
			curr_a = curr_a->next;
		}
		else
			printf("%5c", ' ');
		printf(" ");
		if (curr_b)
		{
			printf("%-5d", curr_b->val);
			curr_b = curr_b->next;
		}
		else
			printf("%5c", ' ');
		printf("\n");
	}
	printf("----- -----\n");
	printf("a     b    \n");
	printf("\n");
}

void	ft_ps_atob(t_ps *tab)
{
	int	old_tail;

	old_tail = tab->a.tail->val;
	while(tab->a.head->val != old_tail)
	{
		if(!tab->a.head->keep)
			ft_exec(tab, PB, 1, TRUE);
		else
			ft_exec(tab, RA, 1, TRUE);
	}
	if(!tab->a.head->keep)
		ft_exec(tab, PB, 1, TRUE);
}

void	ft_ps_btoa_update(t_ps *tab, long ia, long ib)
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
	if (min_ops <= tab->min_ops)
	{
		tab->min_ops = min_ops;
		tab->co_dir = co_dir;
		tab->ia = ia - co_dir;
		tab->ib = ib - co_dir;
	}
}

void	ft_ps_btoa_find(t_ps *tab)
{
	long	ia;
	long	ib;
	t_snode	*curr;

	ib = 0;
	curr = tab->b.head;
	tab->min_ops = ft_ps_insert_pos(&tab->a, curr->val);
	while((size_t)ib < tab->b.size)
	{
		ia = ft_ps_insert_pos(&tab->a, curr->val);
		ft_ps_btoa_update(tab, ia, ib);
		ft_ps_btoa_update(tab, ia - tab->a.size, ib);
		ft_ps_btoa_update(tab, ia, ib - tab->b.size);
		ft_ps_btoa_update(tab, ia - tab->a.size, ib - tab->b.size);
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

void	ft_ps_allign(t_ps *tab)
{
	long	i;
	long	ir;
	t_snode	*curr;

	i = 0;
	curr = tab->a.head;
	while(curr)
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

int	main(int ac, char **av)
{
	t_ps	tab;

	ft_ps_init(&tab);
	if (!ft_ps_parse(&tab, ac - 1, av + 1))
		printf("Error\n");
	
	ft_ps_test_print(&tab);
	
	ft_ps_set_index(&tab.a);
	t_snode	*m;
	m = ft_ps_mfind(&tab.a, ft_ps_cmp_gt);
	//printf("val = %d\ncnt = %ld\n\n", m->val, ft_ps_mcount(&tab.a, m, ft_ps_cmp_gt));
	ft_ps_mupdate(&tab.a, m, ft_ps_cmp_gt);
	ft_ps_atob(&tab);

	//ft_ps_test_print(&tab);

	ft_ps_btoa(&tab);
	ft_ps_allign(&tab);
	
	ft_ps_test_print(&tab);

	//printf("pos = %zu\n", ft_ps_insert_pos(&tab.a, 6));
	return (0);
}
