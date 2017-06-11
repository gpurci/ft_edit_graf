/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_graf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpurci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 13:44:24 by gpurci            #+#    #+#             */
/*   Updated: 2017/02/12 21:25:04 by gpurci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graf.h"

void					del_one_much(mlx_win *mlw, char nume)
{
	del_one_muchie(&mlw->nuc.nd->much, nume);	
	reinit_flag(mlw);
	reinit_frame_graf(mlw);
}

void				del_graf(muchie **nucleu)
{
	muchie			*tmp;

	while (*nucleu)
	{
		tmp = (*nucleu)->dr;
		del_one_nod(nucleu);
		free(*nucleu);
		*nucleu = tmp;
	}
	nucleu = 0;
}//sterge intreg graful

void				del_nod(muchie **nucleu, char nume)
{
	muchie			*drept;
	muchie			*del;

	drept = *nucleu;
	while (drept)
	{
		drept->nd->much = del_one_muchie(&drept->nd->much, nume);
		drept = drept->dr;
	}//stergere muchia ce se indreapta spre un nod in proces de stergere
	if (!(drept = cautare_nod(*nucleu, &del, nume)) && !del)
		return ;
	if (!drept)
	{
		*nucleu = del->dr;
		del_one_nod(&del);
		return ;
	}//sterge primul nod daca corespunde cu numele dat ca paramentru
	drept->dr = del->dr;
	del_one_nod(&del);
	//sterge nodul ce corespunde cu numele dat ca parametru*/
}
