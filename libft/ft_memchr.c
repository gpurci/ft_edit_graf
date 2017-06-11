/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpurci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 18:46:02 by gpurci            #+#    #+#             */
/*   Updated: 2016/11/21 14:45:11 by gpurci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memchr(const void *src, int c, size_t n)
{
	unsigned char *s;

	s = (unsigned char*)src;
	while (n > 0)
	{
		if (*s == (unsigned char)c)
			return ((void*)(s));
		s++;
		n--;
	}
	return (NULL);
}
