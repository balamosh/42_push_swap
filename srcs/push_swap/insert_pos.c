/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotherys <sotherys@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 23:40:04 by sotherys          #+#    #+#             */
/*   Updated: 2022/03/31 00:10:45 by sotherys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_ps_insert_pos(t_stack *stack, int val)
{
	t_snode	*curr;
	size_t	i;

	if (stack->size < 3)
		return (0);
	curr = stack->head;
	i = 0;
	while (curr)
	{
		if (ft_stack_prev(stack, curr)->val < val \
		&& ft_stack_next(stack, curr)->val > val)
			return (i);
		curr = curr->next;
		++i;
	}
	return (i);
}
