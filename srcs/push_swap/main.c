/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 21:17:53 by lcharvol          #+#    #+#             */
/*   Updated: 2017/01/27 21:17:54 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_push_swap.h"

void	ft_printpile(t_pile *p)
{
	int i;

	i = 0;
	printf("\n---------------------\n");
	while (i < p->pile_sizea)
	{
		printf("\nValeur de pilea[%d]: %d\n", i, p->pilea[i]);
		i++;
	}
	printf("\n---------------------\n");

	printf("\n---------------------\n");
	i = 0;
	while (i < p->pile_sizeb)
	{
		printf("\nValeur de pileb[%d]: %d\n", i, p->pileb[i]);
		i++;
	}
	printf("\n---------------------\n");
}

void	ft_error(void)
{
	ft_putstr("Error");
	ft_putchar('\n');
	exit (1);
}

void	ft_verif_str(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!((str[i] >= 48 && str[i] <= 57) || str[i] == '-'))
			ft_error();
		i++;
	}
}

void	ft_verif_arg(t_pile *p)
{
	int i;
	int j;

	i = 0;
	while (i < p->pile_sizeb)
	{
		j = 0;
		while (j < p->pile_sizeb)
		{
			if ( p->pileb[i] == p->pileb[j] && j != i)
				ft_error();
			j++;
		}
		i++;
	}
}

void	ft_stock_params(t_pile *p)
{
	int i;

	i = 0;
	while (i != (p->ac - 1))
	{
		ft_verif_str((p->av)[i + 1]);
		p->pileb[i] = ft_atoi((p->av)[i + 1]);
		i++;
	}
	i = 0;
}

void	ft_verif_tri(t_pile *p)
{
	int i;

	i = 0;
	if (p->pile_sizeb > 0)
	{
		ft_putstr("KO\n");
		exit(1);
	}
	while (i < (p->pile_sizea - 1))
	{
		if (p->pilea[i] > p->pilea[i + 1])
		{
			ft_putstr("KO\n");
			exit(1);
		}
		i++;
	}
	ft_putstr("OK\n");
}

void	ft_put_index(t_pile *p)
{
	int i;
	int i2;
	int i3;

	i = 0;
	while (i < p->pile_sizeb)
	{
		i3 = 0;
		i2 = 0;
		while (i2 < p->pile_sizeb)
		{
			if (p->pileb[i] > p->pileb[i2] && (i != i2))
				i3++;
			i2++;
		}
		p->pilea[i] = i3;
		i++;
	}
	p->pile_sizea = p->pile_sizeb;
	p->pile_sizeb = 0;
}

int		main(int argc, char **argv)
{
	t_pile	*p;


	p = (t_pile *)malloc(sizeof(*p));
	if (argc < 2)
		exit (1);
	p->pile_sizeb = argc - 1;
	p->pile_sizea = 0;
	p->av = argv;
	p->ac = argc;
	p->pilea = (int *)malloc(sizeof(*(p->pilea)) * (argc - 1));
	p->pileb = (int *)malloc(sizeof(*(p->pileb)) * (argc - 1));
	ft_stock_params(p);
	ft_verif_arg(p);
	ft_put_index(p);
	//ft_printpile(p);
	ft_algo(p);
	ft_verif_tri(p);
	free(p->pilea);
	free(p->pileb);
	return (0);
}
