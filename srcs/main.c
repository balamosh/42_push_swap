/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotherys <sotherys@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 23:37:22 by sotherys          #+#    #+#             */
/*   Updated: 2022/03/31 00:04:41 by sotherys         ###   ########.fr       */
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
	printf("pos = %zu\n", ft_ps_insert_pos(&tab.a, 6));
	return (0);
}
