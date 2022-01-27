/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotherys <sotherys@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 22:56:54 by sotherys          #+#    #+#             */
/*   Updated: 2022/01/27 22:56:55 by sotherys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ub;
	size_t			i;

	i = 0;
	ub = (unsigned char *) b;
	while (i < len)
		ub[i++] = c;
	return (b);
}
