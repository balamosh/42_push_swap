/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotherys <sotherys@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 23:15:10 by sotherys          #+#    #+#             */
/*   Updated: 2022/01/29 17:57:41 by sotherys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash.h"

static t_bucket	*ft_bucket_new(int val)
{
	t_bucket	*new;

	new = malloc(sizeof(t_bucket));
	if (!new)
		return (new);
	new->val = val;
	return (new);
}

static t_bool	ft_bucket_insert(t_bucket **head, int val)
{
	t_bucket	*new;

	new = ft_bucket_new(val);
	if (!new)
		return (FALSE);
	new->next = *head;
	*head = new;
	return (TRUE);
}

t_bool	ft_hash_insert(t_hash *hash, int val)
{
	t_bool	flag;

	flag = ft_bucket_insert(\
			&hash->buckets[ft_hash(val) % hash->n_buckets], \
			val);
	if (!flag)
		return (FALSE);
	if ((double)++hash->size / hash->n_buckets > HASH_LOAD_FACTOR)
		return (ft_hash_resize(hash));
	return (TRUE);
}
