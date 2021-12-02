/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotherys <sotherys@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 10:37:15 by sotherys          #+#    #+#             */
/*   Updated: 2021/12/02 11:01:19 by sotherys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	ft_stack_rotate(t_stack *stack)
{
	if (stack->size < 2)
		return ;
	stack->tail->next = stack->head;
	stack->head = stack->head->next;
	stack->head->prev = NULL;
	stack->tail->next->next = NULL;
	stack->tail->next->prev = stack->tail;
	stack->tail = stack->tail->next;
}

void	ft_stack_rrotate(t_stack *stack)
{
	if (stack->size < 2)
		return ;
	stack->head->prev = stack->tail;
	stack->tail = stack->tail->prev;
	stack->tail->next = NULL;
	stack->head->prev->prev = NULL;
	stack->head->prev->next = stack->head;
	stack->head = stack->head->prev;
}
