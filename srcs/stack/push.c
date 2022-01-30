/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotherys <sotherys@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 10:06:08 by sotherys          #+#    #+#             */
/*   Updated: 2022/01/30 17:58:15 by sotherys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_bool	ft_stack_push_front(t_stack *stack, t_snode *elem)
{
	if (!elem)
		return (FALSE);
	if (!stack->size)
	{
		stack->head = elem;
		stack->tail = elem;
	}
	else
	{
		stack->head->prev = elem;
		elem->next = stack->head;
		stack->head = elem;
	}
	++stack->size;
	return (TRUE);
}

t_bool	ft_stack_push_back(t_stack *stack, t_snode *elem)
{
	if (!elem)
		return (FALSE);
	if (!stack->size)
	{
		stack->head = elem;
		stack->tail = elem;
	}
	else
	{
		stack->tail->next = elem;
		elem->prev = stack->tail;
		stack->tail = elem;
	}
	++stack->size;
	return (TRUE);
}
