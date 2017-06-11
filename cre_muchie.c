/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cre_muchie.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpurci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 14:36:29 by gpurci            #+#    #+#             */
/*   Updated: 2017/02/13 15:55:49 by gpurci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graf.h"

char				ver_if_muchie(muchie *much, char nume)
{
	while (much && (much->nd->nume != nume))
		much = much->dr;
	if (!much)
		return (1);
	return (0);
}

char				cre_mouse_much(mlx_win *mlw, int xp, int yp)
{
	int				x;
	int				y;
	muchie			*nucleu;

	nucleu = mlw->nuc.nucleu;
	mlw->nuc.lst_nd = mlw->nuc.nd;
	while (nucleu)
	{
		x = coord_x_y(nucleu->nd->x) - 21;
		y = coord_x_y(nucleu->nd->y) - 21;
		if ((xp > x) && (xp < x + 42) && (yp > y) && (yp < y + 42))
		{
			mlw->nuc.nd = nucleu->nd;
			x = -10000;
			break ;
		}
		nucleu = nucleu->dr;
	}
	if (x == -10000)
	{
		if (mlw->pres == 1 && 
				ver_if_muchie((muchie*)mlw->nuc.lst_nd->much, mlw->nuc.nd->nume)
				&& mlw->nume != 'd')
			add_much((muchie**)&mlw->nuc.lst_nd->much, mlw->nuc.nd);
		return (1);
	}
	return (0);
}
