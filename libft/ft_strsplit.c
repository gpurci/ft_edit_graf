/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpurci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 20:20:30 by gpurci            #+#    #+#             */
/*   Updated: 2017/02/10 21:50:43 by gpurci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t			ft_strlen_var(const char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] != c && str[i] != '\0')
		i++;
	return (i);
}

static size_t			ft_len_rind(const char *s, char c)
{
	size_t	i;
	size_t	k;
	char	f;

	i = 0;
	f = 0;
	k = 0;
	while (s[k])
	{
		if (s[k] != c && !f)
		{
			f = 1;
			i++;
		}
		else if (f == 1 && s[k] == c)
			f = 0;
		k++;
	}
	return (i);
}

static char				**ft_alloc_char(const char *s, char c, size_t t)
{
	size_t	k;
	size_t	j;
	char	**ap;

	k = 0;
	j = 0;
	ap = NULL;
	if (!(ap = (char**)malloc(sizeof(char *) * t)))
		return (0);
	while (*s)
	{
		if (*s != c)
		{
			k = ft_strlen_var(s, c);
			if (!(ap[j++] = ft_strsub(s, 0, k)))
				return (0);
			s = s + k;
			if (!(*s))
				break ;
		}
		s++;
	}
	ap[j] = NULL;
	return (ap);
}

char					**ft_strsplit(const char *s, char c)
{
	size_t	j;
	char	**ap;

	ap = NULL;
	if (s == NULL)
		return (0);
	if (!(j = ft_len_rind(s, c)))
		j = 1;
	if (!(ap = ft_alloc_char(s, c, j + 1)))
		return (0);
	return (ap);
}
