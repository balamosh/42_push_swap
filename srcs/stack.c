/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotherys <sotherys@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 22:02:20 by sotherys          #+#    #+#             */
/*   Updated: 2021/12/02 00:19:17 by sotherys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_snode	*ft_stack_new(int val)
{
	t_snode	*new;

	if (!ft_malloc((void *)&new, sizeof(t_snode)))
		return (NULL);
	new->val = val;
	new->keep = FALSE;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

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

t_snode	*ft_stack_pop(t_stack *stack)
{
	t_snode	*elem;

	if (!stack->size)
		return (NULL);
	elem = stack->head;
	elem->prev = NULL;
	elem->next = NULL;
	stack->head = NULL;
	if (stack->size == 1)
		stack->tail = NULL;
	--stack->size;
	return (elem);
}
