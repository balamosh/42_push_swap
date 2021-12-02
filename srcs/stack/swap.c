/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotherys <sotherys@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 10:07:14 by sotherys          #+#    #+#             */
/*   Updated: 2021/12/02 10:36:06 by sotherys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	ft_stack_swap(t_stack *stack)
{
	t_snode	*new_head;

	if (stack->size == 2)
	{
		stack->head->next = NULL;
		stack->tail->prev = NULL;
		new_head = stack->tail;
		stack->tail = stack->head;
		stack->head = new_head;
	}
	else if (stack->size > 2)
	{
		new_head = stack->head->next;
		stack->head->next = new_head->next;
		stack->head->prev = new_head;
		new_head->next = stack->head;
		new_head->prev = NULL;
		stack->head = new_head;
	}
}
