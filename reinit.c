/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reinit_tast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpurci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 15:33:30 by gpurci            #+#    #+#             */
/*   Updated: 2017/02/13 15:55:38 by gpurci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graf.h"

void				reinit_flag(mlx_win *mlw)
{
	mlw->pres = 0;
	mlw->nume = 0;
	mlw->key = 0;
	mlw->but = 0;
	mlw->nuc.nd = 0;
	mlw->nuc.lst_nd = 0;
}

void				reinit_name(mlx_win *mlw, char nume)
{
	mlw->nuc.nd->nume = nume;
	reinit_frame_graf(mlw);
}

void				reinit_frame_graf(mlx_win *mlw)
{
	mlx_clear_window(mlw->mlx, mlw->win);
	grafic_graf(mlw);
}

void			reinit_coord(dublu_coord *leg, int color, mlx_win *mlw, muchie *much)
{
	double		R;
	int			x;
	int			y;

	printf("coord xo =%d yo =%d xu =%d yu = %d\n", leg->init.x, leg->init.y, leg->final.x, leg->final.y);
	R = distanta_graf(leg->init.x, leg->init.y, leg->final.x, leg->final.y);
	R = 21 / R;
	y = abs(leg->final.y - leg->init.y) * R;
	x = abs(leg->final.x - leg->init.x) * R;
	if (leg->init.y > leg->final.y)
		y = -y;
	if (leg->init.x > leg->final.x)
		x = -x;
	leg->init.y += y;
	leg->final.y -= y;
	leg->init.x += x;
	leg->final.x -= x;
	circle(leg->final.x, leg->final.y, 6, 360, 0xFFFF & color, mlw);
	circle(leg->final.x, leg->final.y, 5, 360, 0xFFFF & color, mlw);	
	circle(leg->final.x, leg->final.y, 4, 360, 0xFFFF & color, mlw);
	if (!much)
		line(leg->init.x, leg->init.y, leg->final.x, leg->final.y, color, 0, mlw);
	else
	{
		if ((much->st_much & 1) == 1)
			line(leg->init.x, leg->init.y, leg->final.x, leg->final.y, color, 0, mlw);
		else
			line(leg->init.x, leg->init.y, leg->final.x, leg->final.y, 0xFF0000, 0, mlw);
	}
}

void				reinit_coord_graf(mlx_win *mlw, int x, int y)
{
	char			coord[4];
	nod				*nd;

	nd = mlw->nuc.nd;
	conv_int_char_coord(x, y, coord);
	nd->x[0] = coord[0];
	nd->x[1] = coord[1];
	nd->y[0] = coord[2];
	nd->y[1] = coord[3];
	reinit_frame_graf(mlw);
}
