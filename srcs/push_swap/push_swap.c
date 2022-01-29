/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotherys <sotherys@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 21:36:32 by sotherys          #+#    #+#             */
/*   Updated: 2022/01/29 21:36:33 by sotherys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ps_init(t_ps *tab)
{
	ft_stack_init(&tab->a);
	ft_stack_init(&tab->b);
}

void	ft_ps_free(t_ps *tab)
{
	ft_stack_free(&tab->a);
	ft_stack_free(&tab->b);
}
