/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imajeru <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 08:20:06 by imajeru           #+#    #+#             */
/*   Updated: 2016/11/21 15:01:33 by gpurci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, char *src)
{
	char *temp;

	temp = dest;
	while (*temp != '\0')
		temp++;
	while (*src != '\0')
	{
		*temp = *src;
		src++;
		temp++;
	}
	*temp = '\0';
	return (dest);
}
