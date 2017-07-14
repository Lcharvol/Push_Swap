/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 03:53:10 by lcharvol          #+#    #+#             */
/*   Updated: 2017/07/14 16:40:19 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_push_swap.h"

int		check_overflow(char *str)
{
	if (str[0] == '-')
	{
		if (ft_strlen(str) > 11 || ft_atoi_ll(str) < -2147483647)
			return (1);
		return (0);
	}
	if (ft_strlen(str) > 10 || ft_atoi_ll(str) > 2147483646)
		return (1);
	return (0);
}

int		check_number(int ac, char **av)
{
	int	i;
	int	i2;

	i = 1;
	while (i < ac)
	{
		if (check_overflow(av[i]) != 0)
			error();
		i2 = 0;
		while (av[i][i2])
		{
			if (ft_isdigit(av[i][i2]) != 1 && av[i][i2] != '-' && i2 != 0)
				return (1);
			i2++;
		}
		i++;
	}
	return (0);
}

void	stock_numbers(t_pile *c, int ac, char **av)
{
	int i;

	i = 0;
	while (i < ac - 1)
	{
		c->pilea[i] = ft_atoi(av[i + 1]);
		i++;
	}
}

void	issort(int *tab, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (i != 0)
		{
			if (tab[i - 1] > tab[i])
			{
				ft_putendl("KO");
				return ;
			}
		}
		i++;
	}
	ft_putendl("OK");
}

int		main(int ac, char **av)
{
	t_pile	*p;

	p = (t_pile *)malloc(sizeof(*p));
	p->pilea = (int *)malloc(sizeof(*(p->pilea)) * (ac - 1));
	p->pileb = (int *)malloc(sizeof(*(p->pilea)) * (ac - 1));
	if (check_number(ac, av) != 0)
		error();
	init_pile(p, ac);
	stock_numbers(p, ac, av);
	run(p);
	issort(p->pilea, p->pile_sizea);
}
