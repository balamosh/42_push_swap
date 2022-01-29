/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotherys <sotherys@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 23:43:16 by sotherys          #+#    #+#             */
/*   Updated: 2022/01/29 17:26:47 by sotherys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash.h"

t_bool	ft_hash_resize(t_hash *hash)
{
	t_hash		new_hash;
	size_t		i;
	t_bucket	*node;

	if (!ft_hash_init_size(&new_hash, 2 * hash->n_buckets))
		return (FALSE);
	i = 0;
	while (i < hash->n_buckets)
	{
		node = hash->buckets[i++];
		while (node)
		{
			if (!ft_hash_insert(&new_hash, node->val))
			{
				ft_hash_free(&new_hash);
				return (FALSE);
			}
			node = node->next;
		}
	}
	ft_hash_free(hash);
	hash->buckets = new_hash.buckets;
	hash->n_buckets = new_hash.n_buckets;
	hash->size = new_hash.size;
	return (TRUE);
}
