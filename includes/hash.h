/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotherys <sotherys@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 23:00:26 by sotherys          #+#    #+#             */
/*   Updated: 2022/01/29 17:16:28 by sotherys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASH_H
# define HASH_H

# include "libft.h"

# define HASH_LOAD_FACTOR 0.75

typedef struct s_bucket
{
	int				val;
	struct s_bucket	*next;
}				t_bucket;

typedef struct s_hash
{
	t_bucket	**buckets;
	size_t		n_buckets;
	size_t		size;
}				t_hash;

t_bool			ft_hash_init(t_hash *hash);
t_bool			ft_hash_insert(t_hash *hash, int val);
t_bool			ft_hash_contains(t_hash *hash, int val);
void			ft_hash_free(t_hash *hash);

unsigned int	ft_hash(unsigned int val);
t_bool			ft_hash_resize(t_hash *hash);
t_bool			ft_hash_init_size(t_hash *hash, size_t n);

#endif
