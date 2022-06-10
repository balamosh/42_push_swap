/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   markup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balamosh <balamosh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 05:49:18 by sotherys          #+#    #+#             */
/*   Updated: 2022/06/10 12:36:55 by balamosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_ps_mcount(t_stack *stack, \
						t_snode *m, \
						t_bool (*cmp)(t_snode*, t_snode *))
{
	size_t	cnt;
	t_snode	*curr;
	t_snode	*new_m;

	cnt = 1;
	curr = ft_stack_next(stack, m);
	new_m = m;
	while (curr != m)
	{
		if (cmp(curr, new_m))
		{
			++cnt;
			new_m = curr;
		}
		curr = ft_stack_next(stack, curr);
	}
	return (cnt);
}

t_snode	*ft_ps_mfind(t_stack *stack, t_bool (*cmp)(t_snode*, t_snode *))
{
	size_t	max;
	t_snode	*m;
	size_t	cnt;
	t_snode	*curr;

	m = stack->head;
	max = ft_ps_mcount(stack, m, cmp);
	curr = m;
	while (curr)
	{
		cnt = ft_ps_mcount(stack, curr, cmp);
		if (cnt > max || (cnt == max && curr->index < m->index))
		{
			max = cnt;
			m = curr;
		}
		curr = curr->next;
	}
	return (m);
}

void	ft_ps_mupdate(t_stack *stack, \
						t_snode *m, \
						t_bool (*cmp)(t_snode*, t_snode *))
{
	t_snode	*curr;
	t_snode	*new_m;

	curr = ft_stack_next(stack, m);
	new_m = m;
	while (curr != m)
	{
		if (cmp(curr, new_m))
		{
			curr->keep = TRUE;
			new_m = curr;
		}
		else
			curr->keep = FALSE;
		curr = ft_stack_next(stack, curr);
	}
}

void	ft_ps_markup(t_ps *tab, t_bool (*cmp)(t_snode*, t_snode *))
{
	t_snode	*m;
	size_t	cnt;

	m = ft_ps_mfind(&tab->a, cmp);
	cnt = ft_ps_mcount(&tab->a, m, cmp);
	ft_exec(tab, SA, 1, FALSE);
	if (ft_ps_mcount(&tab->a, m, cmp) > cnt)
	{
		ft_exec(tab, SA, 1, FALSE);
		ft_exec(tab, SA, 1, TRUE);
	}
	ft_ps_mupdate(&tab->a, m, cmp);
}
