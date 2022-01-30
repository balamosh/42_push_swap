/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotherys <sotherys@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 20:10:27 by sotherys          #+#    #+#             */
/*   Updated: 2022/01/30 18:29:10 by sotherys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	ft_ps_parse(t_ps *tab, int ac, char **av)
{
	t_bool	flag;
	t_hash	set;
	int		i;
	long	n;

	ft_hash_init(&set);
	i = 0;
	flag = TRUE;
	while (i < ac && flag)
	{
		n = ft_atol(av[i++]);
		flag = (n <= INT_MAX && n >= INT_MIN && !ft_hash_contains(&set, n) && \
				ft_hash_insert(&set, n) && \
				ft_stack_push_back(&tab->a, ft_stack_new(n)));
	}
	ft_hash_free(&set);
	if (!flag)
		ft_stack_free(&tab->a);
	return (flag);
}
