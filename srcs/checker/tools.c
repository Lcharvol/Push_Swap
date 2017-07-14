
#include "../../includes/ft_push_swap.h"

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
