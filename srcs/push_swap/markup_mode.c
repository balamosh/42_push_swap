/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   markup_mode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotherys <sotherys@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 15:10:06 by sotherys          #+#    #+#             */
/*   Updated: 2022/06/10 15:10:07 by sotherys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	ft_ps_cmp_id(t_snode *lhs, t_snode *rhs)
{
	return (lhs->index - rhs->index == 1);
}

t_bool	ft_ps_cmp_gt(t_snode *lhs, t_snode *rhs)
{
	return (lhs->val > rhs->val);
}
