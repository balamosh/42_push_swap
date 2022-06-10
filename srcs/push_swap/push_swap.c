/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotherys <sotherys@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 21:36:32 by sotherys          #+#    #+#             */
/*   Updated: 2022/06/10 17:23:31 by sotherys         ###   ########.fr       */
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
	tab->error = FALSE;
	ft_stack_init(&tab->cmds);
	ft_stack_init(&tab->a);
	ft_stack_init(&tab->b);
	ft_ps_exec_init(tab);
}

void	ft_ps_free(t_ps *tab)
{
	ft_stack_free(&tab->a);
	ft_stack_free(&tab->b);
}

void	ft_ps_print_cmds(t_ps *tab)
{
	t_snode		*curr;
	static char	*cmds[11] = \
	{"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra", "rrb", "rrr"};

	curr = tab->cmds.head;
	while (curr)
	{
		ft_putstr_fd(cmds[curr->val], 1);
		ft_putchar_fd('\n', 1);
		curr = curr->next;
	}
}

void	ft_push_swap(t_ps *tab, \
						int ac, \
						char **av, \
						t_bool (*mode)(t_snode*, t_snode *))
{
	ft_ps_init(tab);
	if (!ft_ps_parse(tab, ac - 1, av + 1))
		tab->error = TRUE;
	ft_ps_set_index(&tab->a);
	ft_ps_markup(tab, mode);
	ft_ps_atob(tab);
	ft_ps_btoa(tab);
	ft_ps_allign(tab);
}
