/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpurci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 18:23:14 by gpurci            #+#    #+#             */
/*   Updated: 2016/11/21 14:42:38 by gpurci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		(((unsigned char*)dest)[i]) = (((unsigned char*)src)[i]);
		if ((((unsigned char*)src)[i]) == (unsigned char)c)
			return (dest + i + 1);
		i++;
	}
	return (0);
}
