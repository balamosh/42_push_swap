/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotherys <sotherys@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 23:37:22 by sotherys          #+#    #+#             */
/*   Updated: 2021/12/02 00:15:44 by sotherys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	t_stack	a;
	t_snode	*elem;
	size_t	i;

	if (ac == 1)
		return (0);
	a = (t_stack){.head = NULL, .tail = NULL, .size = 0};
	i = ac - 1;
	while (i > 0)
		ft_stack_push_front(&a, ft_stack_new(ft_atoi(av[i--])));
	elem = a.head;
	while (elem)
	{
		ft_putnbr_fd(elem->val, 1);
		write(1, "\n", 1);
		elem = elem->next;
	}
	return (0);
}
