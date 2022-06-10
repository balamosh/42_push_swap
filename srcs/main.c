/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balamosh <balamosh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 23:37:22 by sotherys          #+#    #+#             */
/*   Updated: 2022/06/10 12:38:32 by balamosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_ps_test_print(t_ps *tab)
{
	t_snode	*curr_a;
	t_snode	*curr_b;

	curr_a = tab->a.head;
	curr_b = tab->b.head;
	printf("\n");
	while (curr_a || curr_b)
	{
		if (curr_a)
		{
			printf("%-5d", curr_a->val);
			curr_a = curr_a->next;
		}
		else
			printf("%5c", ' ');
		printf(" ");
		if (curr_b)
		{
			printf("%-5d", curr_b->val);
			curr_b = curr_b->next;
		}
		else
			printf("%5c", ' ');
		printf("\n");
	}
	printf("----- -----\n");
	printf("a     b    \n");
	printf("\n");
}

int	main(int ac, char **av)
{
	t_ps	tab;

	ft_ps_init(&tab);
	if (!ft_ps_parse(&tab, ac - 1, av + 1))
		printf("Error\n");
	
	ft_ps_test_print(&tab);
	
	ft_ps_set_index(&tab.a);
	ft_ps_markup(&tab, ft_ps_cmp_id);
	ft_ps_atob(&tab);
	ft_ps_btoa(&tab);
	ft_ps_allign(&tab);
	
	ft_ps_test_print(&tab);

	//printf("pos = %zu\n", ft_ps_insert_pos(&tab.a, 6));
	return (0);
}

/*
pb
pb
ra
pb
ra
pb
pa
pa
rrr
rra
pa
pa
*/