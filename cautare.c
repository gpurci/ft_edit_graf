/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cautare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpurci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 13:30:40 by gpurci            #+#    #+#             */
/*   Updated: 2017/02/13 15:58:33 by gpurci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graf.h"

muchie				*cautare_nod(void *much, muchie **find, char nume)
{
	muchie			*beg;

	beg = (muchie*)much;
	*find = 0;
	if (!beg)
		return (0);
	if (beg->nd->nume == nume)
	{
		*find = beg;
		return (0);
	}
	while (beg->dr)
	{
		if (beg->dr->nd->nume == nume)
		{
			*find = beg->dr;
			return (beg);
		}
		beg = beg->dr;
	}
	return (0);
}

void				coincidenta_nume(int *array, muchie *nucleu, muchie *much)
{
	muchie			*lst;
	int				j = 0;
	int				n = 0;

	while (much)
	{
		lst = nucleu;
		n = 0;
		if ((much->st_much & 1))
		{
			while (lst->nd->nume != much->nd->nume)
			{
				n++;
				lst = lst->dr;
			}
		}
		else
			n = -2;
		array[j] = n;
		much = much->dr;
		j++;
	}
}//scrie ordinea de amplasare a unei muchii in nucleu
//j numarul de muchii
//n numarul de ordine
