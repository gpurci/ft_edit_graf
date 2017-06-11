/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpurci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 18:38:20 by gpurci            #+#    #+#             */
/*   Updated: 2016/11/21 14:44:04 by gpurci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t i;

	if (dest > src)
		while (n > 0)
		{
			(((unsigned char*)dest)[n - 1]) = (((unsigned char*)src)[n - 1]);
			n--;
		}
	else if (dest < src)
	{
		i = 0;
		while (i < n)
		{
			(((unsigned char*)dest)[i]) = (((unsigned char*)src)[i]);
			i++;
		}
	}
	return (dest);
}
