/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 21:34:44 by lcharvol          #+#    #+#             */
/*   Updated: 2017/01/27 21:34:45 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct		s_pile
{
	int				*pilea;
	int				*pileb;
	int				ac;
	char			**av;
	int				tmp;
	int				tmp2;
	int				pile_sizea;
	int				pile_sizeb;
}					t_pile;

long long int		ft_atoi_ll(const char *str);
void	ft_printpile(t_pile *p);
void	ft_algo(t_pile *p);
void	ft_rrr(t_pile *p);
void	ft_rrb(t_pile *p, int b);
void	ft_rra(t_pile *p, int b);
void	ft_rr(t_pile *p);
void	ft_rb(t_pile *p, int b);
void	ft_ra(t_pile *p, int b);
void	ft_ss(t_pile *p);
void	ft_sb(t_pile *p, int b);
void	ft_sa(t_pile *p, int b);
void	ft_pb(t_pile *p);
void	ft_pa(t_pile *p);

#endif
