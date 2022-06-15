/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotherys <sotherys@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 23:50:41 by sotherys          #+#    #+#             */
/*   Updated: 2022/06/14 17:31:25 by sotherys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	ft_ps_sorted(t_stack *stack)
{
	t_snode	*curr;

	curr = stack->head;
	while (curr && curr->next)
	{
		if (curr->val >= curr->next->val)
			return (FALSE);
		curr = curr->next;
	}
	return (TRUE);
}
