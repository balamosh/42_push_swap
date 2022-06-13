/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotherys <sotherys@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 23:50:41 by sotherys          #+#    #+#             */
/*   Updated: 2022/06/12 23:50:42 by sotherys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	ft_ps_sorted(t_stack *stack)
{
	t_snode	*curr;

	if (stack->size < 2)
		return (TRUE);
	curr = stack->head->next;
	while (curr)
	{
		if (curr->val <= curr->prev->val)
			return (FALSE);
		curr = curr->next;
	}
	return (TRUE);
}
