/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotherys <sotherys@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 10:06:50 by sotherys          #+#    #+#             */
/*   Updated: 2021/12/02 10:06:51 by sotherys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_snode	*ft_stack_pop(t_stack *stack)
{
	t_snode	*elem;

	if (!stack->size)
		return (NULL);
	elem = stack->head;
	stack->head = elem->next;
	--stack->size;
	if (stack->size)
		stack->head->prev = NULL;
	else
		stack->tail = NULL;
	elem->prev = NULL;
	elem->next = NULL;
	return (elem);
}
