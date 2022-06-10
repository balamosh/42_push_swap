/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_r.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotherys <sotherys@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 15:09:41 by sotherys          #+#    #+#             */
/*   Updated: 2022/06/10 15:09:43 by sotherys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exec_ra(t_ps *tab)
{
	ft_stack_rotate(&tab->a);
}

void	ft_exec_rb(t_ps *tab)
{
	ft_stack_rotate(&tab->b);
}

void	ft_exec_rr(t_ps *tab)
{
	ft_stack_rotate(&tab->a);
	ft_stack_rotate(&tab->b);
}
