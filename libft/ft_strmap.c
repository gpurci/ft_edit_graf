/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpurci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 15:47:36 by gpurci            #+#    #+#             */
/*   Updated: 2016/11/21 15:41:26 by gpurci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strmap(char const *s, char (*f)(char))
{
	char	*src;
	size_t	i;

	if (!s || !f)
		return (0);
	if (!(src = ft_strnew(ft_strlen(s))))
		return (0);
	i = 0;
	while (s[i])
	{
		src[i] = f(s[i]);
		i++;
	}
	return (src);
}
