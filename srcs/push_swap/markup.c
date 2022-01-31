/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   markup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotherys <sotherys@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 05:49:18 by sotherys          #+#    #+#             */
/*   Updated: 2022/01/31 09:56:02 by sotherys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	ft_ps_cmp_id(t_snode *lhs, t_snode *rhs)
{
	return (lhs->index - rhs->index == 1);
}

t_bool	ft_ps_cmp_gt(t_snode *lhs, t_snode *rhs)
{
	return (lhs->val > rhs->val);
}

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
