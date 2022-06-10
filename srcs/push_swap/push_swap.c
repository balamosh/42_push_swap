/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balamosh <balamosh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 21:36:32 by sotherys          #+#    #+#             */
/*   Updated: 2022/06/10 11:58:06 by balamosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_ps_exec_init(t_ps *tab)
{
	tab->exec[SA] = &ft_exec_sa;
	tab->exec[SB] = &ft_exec_sb;
	tab->exec[SS] = &ft_exec_ss;
	tab->exec[PA] = &ft_exec_pa;
	tab->exec[PB] = &ft_exec_pb;
	tab->exec[RA] = &ft_exec_ra;
	tab->exec[RB] = &ft_exec_rb;
	tab->exec[RR] = &ft_exec_rr;
	tab->exec[RRA] = &ft_exec_rra;
	tab->exec[RRB] = &ft_exec_rrb;
	tab->exec[RRR] = &ft_exec_rrr;
}

void	ft_ps_init(t_ps *tab)
{
	ft_stack_init(&tab->a);
	ft_stack_init(&tab->b);
	ft_ps_exec_init(tab);
}

void	ft_ps_free(t_ps *tab)
{
	ft_stack_free(&tab->a);
	ft_stack_free(&tab->b);
}

#include <stdio.h>

void	ft_exec(t_ps *tab, t_ps_cmd cmd, long n, t_bool real)
{
	static char	*cmds[11] = \
	{"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra", "rrb", "rrr"};
	long		i;

	i = 0;
	while (i < n)
	{
		tab->exec[cmd](tab);
		if (real)
			printf("%s\n", cmds[cmd]);
		++i;
	}
}
