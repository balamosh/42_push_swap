/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotherys <sotherys@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 23:00:12 by sotherys          #+#    #+#             */
/*   Updated: 2022/01/27 23:44:00 by sotherys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash.h"

t_bool	ft_hash_init(t_hash *hash)
{
	hash->size = 0;
	hash->n_buckets = 4;
	return (ft_calloc((void **)&hash->buckets, \
			sizeof(t_bucket *) * hash->n_buckets));
}

static void	ft_bucket_free(t_bucket *head)
{
	t_bucket	*tmp;

	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}

void	ft_hash_free(t_hash *hash)
{
	size_t	i;

	i = 0;
	while (i < hash->n_buckets)
		ft_bucket_free(hash->buckets[i++]);
	free(hash->buckets);
}

unsigned int	ft_hash(unsigned int val)
{
	val = ((val >> 16) ^ val) * 0x45d9f3b;
	val = ((val >> 16) ^ val) * 0x45d9f3b;
	val = (val >> 16) ^ val;
	return (val);
}
