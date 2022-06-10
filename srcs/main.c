/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotherys <sotherys@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 23:37:22 by sotherys          #+#    #+#             */
/*   Updated: 2022/06/10 18:02:03 by sotherys         ###   ########.fr       */
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
	t_ps	tab_gt;
	t_ps	tab_id;

	ft_push_swap(&tab_gt, ac, av, ft_ps_cmp_gt);
	ft_push_swap(&tab_id, ac, av, ft_ps_cmp_id);
	if (tab_gt.error || tab_id.error)
		ft_putstr_fd("Error\n", 2);
	else if (tab_gt.cmds.size < tab_id.cmds.size)
		ft_ps_print_cmds(&tab_gt);
	else
		ft_ps_print_cmds(&tab_id);
	//ft_ps_test_print(&tab_gt);
	ft_ps_free(&tab_gt);
	ft_ps_free(&tab_id);
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

/*
ARG=`shuf -i 0-2147483647 -n 500 | tr '\n' ' '`; ./push_swap $ARG | wc -l
*/