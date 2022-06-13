/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotherys <sotherys@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 00:45:43 by sotherys          #+#    #+#             */
/*   Updated: 2022/06/13 03:30:36 by sotherys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			break ;
		++i;
	}
	return ((unsigned char) s1[i] - (unsigned char) s2[i]);
}

int	ft_str_find(const char **strs, const char *str)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		if (ft_strcmp(strs[i], str) == 0)
			return (i);
		++i;
	}
	return (-1);
}

void	ft_checker(t_ps *tab, int ac, char **av)
{
	char				*line;
	int					cmd_id;
	static const char	*cmds[12] = \
	{"sa\n", "sb\n", "ss\n", "pa\n", "pb\n"\
	, "ra\n", "rb\n", "rr\n", "rra\n", "rrb\n", "rrr\n", NULL};

	ft_ps_init(tab);
	if (!ft_ps_parse(tab, ac - 1, av + 1))
		tab->error = TRUE;
	while (!tab->error)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		cmd_id = ft_str_find(cmds, line);
		free(line);
		if (cmd_id >= 0)
			ft_exec(tab, cmd_id, 1, FALSE);
		else
			tab->error = TRUE;
	}
}
