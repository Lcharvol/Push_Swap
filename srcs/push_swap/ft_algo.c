/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 02:25:40 by lcharvol          #+#    #+#             */
/*   Updated: 2017/01/28 02:25:41 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_push_swap.h"

void	ft_rr(t_pile *p)
{
	ft_ra(p, 1);
	ft_rb(p, 1);
	ft_putstr("rr\n");
}

int		ft_is_reverse_sort_pileb(t_pile *p)
{
	int i;

	i = 0;
	while (i < (p->pile_sizeb - 1))
	{
		if (p->pileb[i] > p->pileb[i + 1])
		{
			while ((p->pileb[i] > p->pileb[i + 1]) && (i < (p->pile_sizeb - 1)))
				i++;
			if (i != (p->pile_sizeb - 1))
				return (-1);
		}
		else
			return (-1); 
	}
	return (0);
}

int		ft_is_sort_pilea(t_pile *p)
{
	int i;

	i = 0;
	while (i < (p->pile_sizea - 1))
	{
		if (p->pilea[i] < p->pilea[i + 1])
		{
			while ((p->pilea[i] < p->pilea[i + 1]) && (i < (p->pile_sizea - 1)))
				i++;
			if (i != (p->pile_sizea - 1))
				return (-1);
		}
		else
			return (-1);
	}
	return (0);
}

int		ft_get_med_pos(t_pile *p)
{
	int i;

	i = 0;
	while(i < p->pile_sizea)
	{
		if (p->pilea[i] == p->pile_sizea / 2)
			break;
		i++;
	}
	return (i);
}

void	ft_algo2(t_pile *p)
{
	while (ft_is_sort_pilea(p) != 0)
	{
		
		if (p->pilea[0] > p->pilea[1])
		{
			ft_sa(p, 0);
			ft_ra(p, 0);
		}
	}
}

void	ft_algo1(t_pile *p)
{
	int j;
	int k;
	int med;

	med = p->pile_sizea / 2;
	j = med - 1;
	k = med + 1;
	if (ft_is_sort_pilea(p) == 0)
		return ;
	while (p->pilea[0] != med)
	{
		if (ft_get_med_pos(p) >= med)
			ft_rra(p, 0);
		else
			ft_ra(p, 0);
	}
	if (p->pilea[0] == med)
		{
			ft_pb(p);
		}
	while (p->pile_sizea > 0)
	{
		if (p->pilea[0] == k)
		{
			ft_pb(p);
			k++;
		}
		else if (p->pilea[0] == j)
		{
			ft_pb(p);
			ft_rb(p, 0);
			j--;
		}
		else
			ft_ra(p, 0);
	}
	while (p->pile_sizeb > 0)
		ft_pa(p);
}

void	ft_algo(t_pile *p)
{
	if (p->pile_sizea < 10)
		ft_algo2(p);
	else
		ft_algo1(p);
}
