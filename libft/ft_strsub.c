/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpurci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 15:36:32 by gpurci            #+#    #+#             */
/*   Updated: 2016/11/21 16:58:01 by gpurci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *src;

	if (!s || ft_strlen(s + start) < len)
		return (0);
	if (!(src = ft_strnew(len)))
		return (0);
	if (len == 0)
		return (src);
	src = ft_strncpy(src, s + start, len);
	return (src);
}
