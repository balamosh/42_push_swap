/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotherys <sotherys@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 21:34:40 by sotherys          #+#    #+#             */
/*   Updated: 2022/01/30 20:12:03 by sotherys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "libft.h"

typedef struct s_snode
{
	int				val;
	t_bool			keep;
	int				index;
	struct s_snode	*next;
	struct s_snode	*prev;
}				t_snode;

typedef struct s_stack
{
	t_snode	*head;
	t_snode	*tail;
	size_t	size;
}				t_stack;

void	ft_stack_init(t_stack *stack);
void	ft_stack_free(t_stack *stack);
t_snode	*ft_stack_new(int val);
t_bool	ft_stack_push_front(t_stack *stack, t_snode *elem);
t_bool	ft_stack_push_back(t_stack *stack, t_snode *elem);
t_snode	*ft_stack_pop(t_stack *stack);
void	ft_stack_rotate(t_stack *stack);
void	ft_stack_rrotate(t_stack *stack);
void	ft_stack_swap(t_stack *stack);

#endif
