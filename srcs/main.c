/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotherys <sotherys@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 23:37:22 by sotherys          #+#    #+#             */
/*   Updated: 2022/03/31 00:04:41 by sotherys         ###   ########.fr       */
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
			ft_exec(tab, PB, TRUE);
		else
			ft_exec(tab, RA, TRUE);
	}
	if(!tab->a.head->keep)
		ft_exec(tab, PB, TRUE);
}

void	ft_ps_btoa_update(t_ps *tab, int ia, int ib)
{
	int		min_ops;

	if ((ia * ib) >= 0)
		min_ops = ft_max(ft_abs(ia), ft_abs(ib));
	else
		min_ops = ft_abs(ia) + ft_abs(ib);
	if (min_ops <= tab->min_ops)
	{
		tab->min_ops = min_ops;
		tab->ia = ia;
		tab->ib = ib;
	}
}

void	ft_ps_btoa_find(t_ps *tab)
{
	int		ia;
	int		ib;
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
	int	i;

	while (tab->b.size > 0)
	{
		ft_ps_btoa_find(tab);
		i = 0;
		while (i++ < ft_abs(tab->ia))
		{
			if (tab->ia < 0)
				ft_exec(tab, RRA, TRUE);
			else
				ft_exec(tab, RA, TRUE);
		}
		i = 0;
		while (i++ < ft_abs(tab->ib))
		{
			if (tab->ib < 0)
				ft_exec(tab, RRB, TRUE);
			else
				ft_exec(tab, RB, TRUE);
		}
		ft_exec(tab, PA, TRUE);
		ft_ps_test_print(tab);
	}
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

	ft_ps_test_print(&tab);

	ft_ps_btoa(&tab);
	
	ft_ps_test_print(&tab);

	//printf("pos = %zu\n", ft_ps_insert_pos(&tab.a, 6));
	return (0);
}
