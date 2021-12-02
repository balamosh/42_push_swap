/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotherys <sotherys@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 10:07:14 by sotherys          #+#    #+#             */
/*   Updated: 2021/12/02 11:51:23 by sotherys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	ft_stack_swap(t_stack *stack)
{
	t_snode	*new_head;

	if (stack->size < 2)
		return ;
	new_head = stack->head->next;
	stack->head->next = new_head->next;
	stack->head->prev = new_head;
	new_head->next = stack->head;
	new_head->prev = NULL;
	stack->head = new_head;
	if (stack->size == 2)
		stack->tail = new_head->next;
}
