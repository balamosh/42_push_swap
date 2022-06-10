/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_rr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotherys <sotherys@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 15:09:49 by sotherys          #+#    #+#             */
/*   Updated: 2022/06/10 15:09:50 by sotherys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exec_rra(t_ps *tab)
{
	ft_stack_rrotate(&tab->a);
}

void	ft_exec_rrb(t_ps *tab)
{
	ft_stack_rrotate(&tab->b);
}

void	ft_exec_rrr(t_ps *tab)
{
	ft_stack_rrotate(&tab->a);
	ft_stack_rrotate(&tab->b);
}
