/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotherys <sotherys@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 21:36:37 by sotherys          #+#    #+#             */
/*   Updated: 2022/06/10 17:38:53 by sotherys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	ft_stack_init(t_stack *stack)
{
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;
}

void	ft_stack_free(t_stack *stack)
{
	t_snode	*tmp;

	while (stack->head)
	{
		tmp = stack->head->next;
		free(stack->head);
		stack->head = tmp;
	}
	ft_stack_init(stack);
}

t_snode	*ft_stack_next(t_stack *stack, t_snode *node)
{
	node = node->next;
	if (!node)
		return (stack->head);
	return (node);
}

t_snode	*ft_stack_prev(t_stack *stack, t_snode *node)
{
	node = node->prev;
	if (!node)
		return (stack->tail);
	return (node);
}
