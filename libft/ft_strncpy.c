/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpurci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 13:10:03 by gpurci            #+#    #+#             */
/*   Updated: 2016/11/21 14:51:21 by gpurci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncpy(char *dest, const char *src, size_t n)
{
	unsigned int i;

	i = 0;
	while (*(src + i) != '\0' && i < (unsigned int)n)
	{
		*(dest + i) = *(src + i);
		i++;
	}
	while (i < (unsigned int)n)
	{
		*(dest + i) = '\0';
		i++;
	}
	if (ft_strlen(src) == n + 1 && ft_strlen(dest) < n)
		*(dest + i) = '\0';
	return (dest);
}
