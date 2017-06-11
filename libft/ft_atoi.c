/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpurci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 00:48:39 by gpurci            #+#    #+#             */
/*   Updated: 2016/11/21 14:50:38 by gpurci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const char		*ft_cond(const char *str)
{
	while (*str == 32 || (*str > 8 && *str < 14))
		str++;
	return (str);
}

int						ft_atoi(const char *str)
{
	int nbr;
	int f;

	nbr = 0;
	f = 1;
	str = ft_cond(str);
	if (*(str) == 45)
	{
		str++;
		f = -1;
	}
	else if (*str == 43)
		str++;
	while (*str > 47 && *str < 58)
	{
		nbr = nbr * 10 + *(str) - 48;
		str++;
	}
	nbr = nbr * f;
	return (nbr);
}
