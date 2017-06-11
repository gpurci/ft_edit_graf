/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpurci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 17:15:22 by gpurci            #+#    #+#             */
/*   Updated: 2016/11/21 15:53:22 by gpurci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(const char *s)
{
	size_t	k;
	size_t	i;
	char	*str;

	if (s == 0)
		return (0);
	while (*s == 32 || *s == '\t' || *s == '\n')
		s++;
	if ((k = ft_strlen(s)))
	{
		k--;
		while (s[k] == 32 || s[k] == '\t' || s[k] == '\n')
			k--;
		k++;
	}
	if (!(str = ft_strnew(k)))
		return (0);
	i = 0;
	while (i < k)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
