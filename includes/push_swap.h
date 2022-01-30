/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotherys <sotherys@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 09:29:19 by sotherys          #+#    #+#             */
/*   Updated: 2022/01/30 20:03:35 by sotherys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stack.h"
# include "hash.h"

typedef struct s_ps
{
	t_stack	a;
	t_stack	b;
}				t_ps;

void	ft_ps_init(t_ps *tab);
void	ft_ps_free(t_ps *tab);
t_bool	ft_ps_parse(t_ps *tab, int ac, char **av);
void	ft_ps_set_index(t_stack *stack);

#endif
