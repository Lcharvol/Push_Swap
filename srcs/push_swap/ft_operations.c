/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 21:19:49 by lcharvol          #+#    #+#             */
/*   Updated: 2017/01/27 21:19:51 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_push_swap.h"

void	ft_ra(t_pile *p, int b)
{
	int i;

	i = 0;
	p->tmp = p->pilea[0];
	while (i < p->pile_sizea)
	{
		p->pilea[i] = p->pilea[i + 1];
		i++;
	}
	p->pilea[i - 1] = p->tmp;
	if (b == 0)
		ft_putstr("ra\n");
}

void	ft_rra(t_pile *p, int b)
{
	int i;

	i = p->pile_sizea;
	p->tmp = p->pilea[i - 1];
	while (i != 0)
	{
		p->pilea[i] = p->pilea[i - 1];
		i--;
	}
	p->pilea[0] = p->tmp;
	if (b == 0)
		ft_putstr("rra\n");
}

void	ft_rrb(t_pile *p, int b)
{
	int i;

	i = p->pile_sizeb;
	p->tmp = p->pileb[i - 1];
	while (i != 0)
	{
		p->pileb[i] = p->pileb[i - 1];
		i--;
	}
	p->pileb[0] = p->tmp;
	if (b == 0)
		ft_putstr("rrb\n");
}

void	ft_rrr(t_pile *p)
{
	ft_rra(p, 1);
	ft_rrb(p, 1);
	ft_putstr("rrr\n");
}

void	ft_rb(t_pile *p, int b)
{
	int i;

	i = 0;
	p->tmp = p->pileb[0];
	while (i < p->pile_sizeb)
	{
		p->pileb[i] = p->pileb[i + 1];
		i++;
	}
	p->pileb[i - 1] = p->tmp;
	if (b == 0)
		ft_putstr("rb\n");
}

