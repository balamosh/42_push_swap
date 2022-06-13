/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotherys <sotherys@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 23:37:22 by sotherys          #+#    #+#             */
/*   Updated: 2022/06/13 03:47:19 by sotherys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	ft_ps_free(&tab_gt);
	ft_ps_free(&tab_id);
	return (0);
}
