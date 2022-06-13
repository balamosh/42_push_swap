/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotherys <sotherys@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 05:00:03 by sotherys          #+#    #+#             */
/*   Updated: 2022/06/13 03:25:10 by sotherys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int ac, char **av)
{
	t_ps	tab;

	ft_checker(&tab, ac, av);
	if (tab.error)
		ft_putstr_fd("Error\n", 2);
	else if (ft_ps_sorted(&tab.a) && tab.b.size == 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	return (0);
}
