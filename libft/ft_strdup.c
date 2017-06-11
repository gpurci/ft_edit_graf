/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpurci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 14:18:57 by gpurci            #+#    #+#             */
/*   Updated: 2016/11/21 15:25:56 by gpurci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(char *src)
{
	char *dest;

	dest = (char*)malloc(ft_strlen(src) + 1);
	if (dest != 0)
	{
		ft_strcpy(dest, src);
	}
	return (dest);
}
