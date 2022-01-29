/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotherys <sotherys@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 10:05:39 by sotherys          #+#    #+#             */
/*   Updated: 2022/01/29 21:16:42 by sotherys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_snode	*ft_stack_new(int val)
{
	t_snode	*new;

	if (!ft_malloc((void *)&new, sizeof(t_snode)))
		return (NULL);
	new->val = val;
	new->keep = FALSE;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}
