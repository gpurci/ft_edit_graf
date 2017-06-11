/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpurci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/23 15:05:28 by gpurci            #+#    #+#             */
/*   Updated: 2016/11/21 16:37:07 by gpurci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(char *str, char *find, size_t n)
{
	size_t i;
	size_t j;

	i = 0;
	if (find[0] == '\0')
		return (str);
	while (*(str + i) != '\0' && i < n)
	{
		j = 0;
		while (*(find + j) == *(str + i + j) && (i + j) < n)
		{
			if (*(find + j + 1) == '\0')
			{
				return (str + i);
			}
			j++;
		}
		i++;
	}
	return (0);
}
