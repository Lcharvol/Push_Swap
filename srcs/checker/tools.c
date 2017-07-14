/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 16:42:03 by lcharvol          #+#    #+#             */
/*   Updated: 2017/07/14 16:42:10 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_push_swap.h"

void				init_pile(t_pile *p, int ac)
{
	p->pile_sizea = ac - 1;
}

void				ft_rr(t_pile *p)
{
	ft_ra(p, 1);
	ft_rb(p, 1);
	ft_putstr("rr\n");
}

void				error(void)
{
	ft_putendl("Error");
	exit(0);
}

long long int		ft_atoi_ll(const char *str)
{
	int				i;
	long long int	nb;
	long long int	neg;

	nb = 0;
	i = 0;
	neg = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
			|| str[i] == '\t' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
		neg = neg * -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		nb *= 10;
		nb += (str[i] - '0');
		i++;
	}
	return (neg * nb);
}
