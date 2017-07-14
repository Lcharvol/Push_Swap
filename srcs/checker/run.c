/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 16:44:00 by lcharvol          #+#    #+#             */
/*   Updated: 2017/07/14 16:47:07 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_push_swap.h"

int			verif_intruction(char *str)
{
	char	*tab[11];
	int		i;
	int		count;

	tab = {"sa", "sb", "ss", "pa", "pb", "ra", "rb",
		"rr", "rra", "rrb", "rrr"};
	i = 0;
	count = 0;
	while (i < 11)
	{
		if (ft_strcmp(str, tab[i]) == 0)
			count++;
		i++;
	}
	if (count == 1)
		return (0);
	return (1);
}

void		do_op(t_pile *p, char *line)
{
	if (ft_strcmp(line, "sa") == 0)
		ft_sa(p, 1);
	if (ft_strcmp(line, "sb") == 0)
		ft_sb(p, 1);
	if (ft_strcmp(line, "pa") == 0)
		ft_pa(p);
	if (ft_strcmp(line, "pb") == 0)
		ft_pb(p);
	if (ft_strcmp(line, "ra") == 0)
		ft_ra(p, 1);
	if (ft_strcmp(line, "rb") == 0)
		ft_rb(p, 1);
	if (ft_strcmp(line, "rr") == 0)
		ft_rr(p);
	if (ft_strcmp(line, "rra") == 0)
		ft_rra(p, 1);
	if (ft_strcmp(line, "rrb") == 0)
		ft_rrb(p, 1);
	if (ft_strcmp(line, "rrr") == 0)
		ft_rrr(p);
}

void		run(t_pile *p)
{
	char *line;

	while (ft_get_next_line(1, &line))
	{
		if (verif_intruction(line) != 0)
			error();
		do_op(p, line);
	}
}
