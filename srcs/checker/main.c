/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 03:53:10 by lcharvol          #+#    #+#             */
/*   Updated: 2017/01/30 03:53:12 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_push_swap.h"

void error(void)
{
  ft_putendl("Error");
  exit(0);
}

int check_overflow(char *str)
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

int check_number(int ac, char **av)
{
  int i;
  int i2;

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

int  verif_intruction(char *str)
{
  char *tab[11] = {"sa", "sb", "ss", "pa", "pb", "ra", "rb",
    "rr", "rra", "rrb", "rrr"};
  int i;
  int count;

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

void run(/* arguments */)
{
  char *line;

  while (ft_get_next_line(1, &line))
  {
    if (verif_intruction(line) != 0)
      error();
  }
}

int main (int ac, char **av)
{
  if (check_number(ac, av) != 0)
    error();
  run();
}
