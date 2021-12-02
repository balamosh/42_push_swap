/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotherys <sotherys@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 23:37:22 by sotherys          #+#    #+#             */
/*   Updated: 2021/12/02 11:35:43 by sotherys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stdio.h>

void	ft_stack_print(t_stack *stack)
{
	t_snode	*elem;

	elem = stack->head;
	while (elem)
	{
		ft_putnbr_fd(elem->val, 1);
		write(1, "\n", 1);
		elem = elem->next;
	}
	write(1, "_\n", 2);
}

int	main(int ac, char **av)
{
	t_stack	a;
	char	c;
	size_t	i;

	if (ac == 1)
		return (0);
	a = (t_stack){.head = NULL, .tail = NULL, .size = 0};
	i = ac - 1;
	while (i > 0)
		ft_stack_push_front(&a, ft_stack_new(ft_atoi(av[i--])));
	ft_stack_print(&a);
	while (TRUE)
	{
		scanf("%c\n", &c);
		if (c == 's')
			ft_stack_swap(&a);
		else if (c == 'r')
			ft_stack_rotate(&a);
		else if (c == 'e')
			ft_stack_rrotate(&a);
		else if (c == 'q')
			break ;
		ft_stack_print(&a);
	}
	return (0);
}
