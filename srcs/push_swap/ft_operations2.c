/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 02:39:23 by lcharvol          #+#    #+#             */
/*   Updated: 2017/01/28 02:39:24 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_push_swap.h"

void	ft_sa(t_pile *p, int b)
{
	if (p->pile_sizea > 0)
	{
		p->tmp = p->pilea[0];
		p->pilea[0] = p->pilea[1];
		p->pilea[1] = p->tmp;
		if (b == 0)
			ft_putstr("sa\n");
	}
}

void	ft_sb(t_pile *p, int b)
{
	if (p->pile_sizeb > 0)
	{
		p->tmp = p->pileb[0];
		p->pileb[0] = p->pileb[1];
		p->pileb[1] = p->tmp;
		if (b == 0)
			ft_putstr("sb\n");
	}
}

void	ft_ss(t_pile *p)
{
	ft_sa(p, 1);
	ft_sb(p, 1);
	ft_putstr("ss\n");
}

void	ft_pa(t_pile *p)
{
	int i;

	if (p->pile_sizeb > 0)
	{
		p->tmp = p->pileb[0];
		i = 0;
		while ((i + 1) < p->pile_sizeb)
		{
			p->pileb[i] = p->pileb[i + 1];
			i++;
		}
		p->pile_sizeb -= 1;
		i = p->pile_sizea + 1;
		while (i != 0)
		{
			p->pilea[i] = p->pilea[i - 1];
			i--;
		}
		p->pilea[0] = p->tmp;
		p->pile_sizea += 1;
		ft_putstr("pa\n");
	}
}

void	ft_pb(t_pile *p)
{
	int i;

	if (p->pile_sizea > 0)
	{
		p->tmp = p->pilea[0];
		i = 0;
		while ((i + 1) < p->pile_sizea)
		{
			p->pilea[i] = p->pilea[i + 1];
			i++;
		}
		p->pile_sizea -= 1;
		i = p->pile_sizeb + 1;
		while (i != 0)
		{
			p->pileb[i] = p->pileb[i - 1];
			i--;
		}
		p->pileb[0] = p->tmp;
		p->pile_sizeb += 1;
		ft_putstr("pb\n");
	}
}
