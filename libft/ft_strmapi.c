/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpurci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 15:27:31 by gpurci            #+#    #+#             */
/*   Updated: 2016/11/07 18:46:20 by gpurci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*src;
	size_t	i;

	if (s == 0 || f == 0)
		return (0);
	src = ft_strnew(ft_strlen(s));
	if (src == 0)
		return (0);
	i = 0;
	while (s[i])
	{
		src[i] = f((unsigned int)i, s[i]);
		i++;
	}
	return (src);
}
