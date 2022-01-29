/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotherys <sotherys@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 20:10:27 by sotherys          #+#    #+#             */
/*   Updated: 2022/01/29 21:13:29 by sotherys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	ft_ps_parse(t_ps *tab, int ac, char **av)
{
	t_hash	set;
	int		i;
	long	n;

	ft_hash_init(&set);
	i = 0;
	while (i < ac)
	{
		n = ft_atol(av[i++]);
		if (n > INT_MAX || n < INT_MIN || ft_hash_contains(&set, n))
			return (!ft_stack_free(&tab->a));
		if (!(ft_hash_insert(&set, n) && ft_stack_push_back(&tab->a, n)))
			return (!ft_stack_free(&tab->a));
	}
	ft_hash_free(&set);
	return (TRUE);
}
