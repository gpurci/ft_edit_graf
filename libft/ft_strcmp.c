/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpurci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 15:04:34 by gpurci            #+#    #+#             */
/*   Updated: 2016/11/21 14:55:15 by gpurci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(char *c1, char *c2)
{
	unsigned char *s1;
	unsigned char *s2;

	s1 = (unsigned char*)c1;
	s2 = (unsigned char*)c2;
	while (*s1 != '\0')
	{
		if (*s1 != *s2)
			return ((int)(*s1 - *s2));
		s1++;
		s2++;
	}
	return ((int)(*s1 - *s2));
}
