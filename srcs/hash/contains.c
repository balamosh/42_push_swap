/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contains.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotherys <sotherys@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 23:44:14 by sotherys          #+#    #+#             */
/*   Updated: 2022/01/27 23:55:03 by sotherys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash.h"

static t_bool	ft_bucket_search(t_bucket *head, int val)
{
	while (head)
	{
		if (head->val == val)
			return (TRUE);
		head = head->next;
	}
	return (FALSE);
}

t_bool	ft_hash_contains(t_hash *hash, int val)
{
	return (ft_bucket_search(\
			hash->buckets[ft_hash(val) % hash->n_buckets], \
			val));
}
