/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_graf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpurci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 15:21:40 by gpurci            #+#    #+#             */
/*   Updated: 2017/02/10 15:55:57 by gpurci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graf.h"

void				*del_one_muchie(void **much, char nume)
{
	muchie			*beg;
	muchie			*del;

	if (!(beg = cautare_nod(*much, &del, nume)) && !del)
		return (*much);
	if (!beg)
	{
		*much = del->dr;
		del->dr = 0;
		del->nd = 0;
		free(del);
		return (*much);
	}
	beg->dr = del->dr;
	del->nd = 0;
	del->dr = 0;
	free(del);
	return (*much);
}//sterge muchiile ce sunt indreptate catre nod-ul ce trebuie de sters

void				del_muchie(muchie **much)
{
	muchie			*tmp;

	while (*much)
	{
		tmp = (*much)->dr;
		(*much)->nd = 0;
		(*much)->dr = 0;
		free(*much);
		*much = tmp;
	}
}//sterge toate muchiile unui nod sterge orbitele unui nod

void				del_value_nod(nod *nd)
{
	nd->nume = 0;
	nd->x[0] = 0;
	nd->x[1] = 0;
	nd->y[0] = 0;
	nd->y[1] = 0;
	nd->much = 0;
}//sterge valorile unui nod

void				del_one_nod(muchie **nucleu)
{
	muchie			*tmp;

	tmp = (muchie*)(*nucleu)->nd->much;//adresa la prima muchie a unui nod
	del_muchie(&tmp);//sterge muchiile 
	del_value_nod((*nucleu)->nd);
	(*nucleu)->dr = 0;
	free((*nucleu)->nd);
	(*nucleu)->nd = 0;
}//sterge un nod
