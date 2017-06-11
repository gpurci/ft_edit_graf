/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpurci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 10:24:31 by gpurci            #+#    #+#             */
/*   Updated: 2017/02/10 13:26:36 by gpurci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_len_integer(int j)
{
	int		i;

	if (j == 0)
		return (1);
	if (j == -2147483648)
		return (11);
	i = 0;
	if (j < 0)
	{
		i++;
		j = -j;
	}
	while (j > 0)
	{
		i++;
		j = j / 10;
	}
	return (i);
}

static void			ft_negativ_integer(char *nbr, int *n, int *k)
{
	if (*n == -2147483648)
	{
		nbr[0] = '-';
		nbr[1] = '2';
		*n = 147483648;
		*k = 1;
	}
	if (*n < 0)
	{
		nbr[0] = '-';
		*n = -(*n);
		*k = 0;
	}
}

char				*ft_itoa(int n)
{
	char	*nbr;
	int		i;
	int		k;

	k = -1;
	i = ft_len_integer(n);
	if (!(nbr = ft_strnew(i)))
		return (0);
	if (n == 0)
	{
		nbr[0] = '0';
		return (nbr);
	}
	ft_negativ_integer(nbr, &n, &k);
	i--;
	while (i > k)
	{
		nbr[i] = n % 10 + '0';
		i--;
		n = n / 10;
	}
	return (nbr);
}
