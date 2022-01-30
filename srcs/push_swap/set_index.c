/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotherys <sotherys@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 20:02:20 by sotherys          #+#    #+#             */
/*   Updated: 2022/01/30 20:23:59 by sotherys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ps_set_index(t_stack *stack)
{
	t_snode	*node;
	t_snode	*min;
	size_t	i;

	i = 0;
	while (i < stack->size)
	{
		min = stack->head;
		node = stack->head->next;
		while (node)
		{
			if (node->val < min->val && node->index == -1)
				min = node;
			node = node->next;
		}
		min->index = i++;
	}
}
