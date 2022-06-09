/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balamosh <balamosh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 23:40:04 by sotherys          #+#    #+#             */
/*   Updated: 2022/06/09 18:50:46 by balamosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_stack_index(t_stack *stack, t_snode *node)
{
	t_snode	*curr;
	size_t	i;

	i = 0;
	curr = stack->head;
	while (curr)
	{
		if (curr == node)
			return (i);
		++i;
		curr = curr->next;
	}
	return (i);
}

size_t	ft_ps_insert_pos_edges(t_stack *stack, \
								int val, \
								t_snode *min, \
								t_snode *max)
{
	if (val < min->val)
		return (ft_stack_index(stack, min));
	if (val > max->val)
		return (ft_stack_index(stack, ft_stack_next(stack, max)));
	return (0);
}

size_t	ft_ps_insert_pos(t_stack *stack, int val)
{
	t_snode	*curr;
	t_snode	*min;
	t_snode	*max;
	size_t	i;

	if (stack->size < 3)
		return (0);
	curr = stack->head;
	min = curr;
	max = curr;
	i = 0;
	while (curr)
	{
		if (ft_stack_prev(stack, curr)->val < val && curr->val > val)
			return (i);
		if (curr->val < min->val)
			min = curr;
		if (curr->val > max->val)
			max = curr;
		curr = curr->next;
		++i;
	}
	return (ft_ps_insert_pos_edges(stack, val, min, max));
}
