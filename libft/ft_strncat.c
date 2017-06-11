/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imajeru <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 09:33:06 by imajeru           #+#    #+#             */
/*   Updated: 2016/11/21 15:04:06 by gpurci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, int n)
{
	char	*temp;
	int		i;

	temp = dest;
	while (*temp != '\0')
		temp++;
	i = 0;
	while (src[i] != '\0' && i < n)
	{
		*temp = src[i];
		temp++;
		i++;
	}
	*temp = '\0';
	return (dest);
}
