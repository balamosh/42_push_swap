/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotherys <sotherys@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 23:37:22 by sotherys          #+#    #+#             */
/*   Updated: 2022/01/31 10:03:09 by sotherys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	t_ps	tab;

	ft_ps_init(&tab);
	if (!ft_ps_parse(&tab, ac - 1, av + 1))
		printf("Error\n");
	ft_ps_set_index(&tab.a);
	t_snode	*m;
	m = ft_ps_mfind(&tab.a, ft_ps_cmp_gt);
	printf("val = %d\ncnt = %ld\n", m->val, ft_ps_mcount(&tab.a, m, ft_ps_cmp_gt));
	ft_ps_mupdate(&tab.a, m, ft_ps_cmp_gt);
	return (0);
}
