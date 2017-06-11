/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpurci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 15:39:52 by gpurci            #+#    #+#             */
/*   Updated: 2017/02/20 18:43:11 by gpurci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graf.h"

dublu_coord		*reinit_coord_dublu(dublu_coord *leg, dublu_coord *point)
{
	point->init.x = leg->init.x;
	point->init.y = leg->init.y;
	point->final.x = leg->final.x;
	point->final.y = leg->final.y;
	return (point);
}

void			grafic_graf(mlx_win *mlx)
{
	dublu_coord		leg;
	dublu_coord		point;
	char			c[2];
	muchie				*much;
	muchie				*nucleu;

	if (mlx->nuc.nd)
	{		
		leg.init.x = coord_x_y(mlx->nuc.nd->x);
		leg.init.y = coord_x_y(mlx->nuc.nd->y);
		circle(leg.init.x, leg.init.y, 25, 360, 0xFFFFFF, mlx);
	}
	nucleu = mlx->nuc.nucleu;
	while (nucleu)
	{
		much = (muchie*)nucleu->nd->much;
		leg.init.x = coord_x_y(nucleu->nd->x);
		leg.init.y = coord_x_y(nucleu->nd->y);
		circle(leg.init.x, leg.init.y, 20, 360, 0xFFFFFF, mlx);	
		circle(leg.init.x, leg.init.y, 21, 360, 0xFFFFFF, mlx);
		if (nucleu->nd->stare == 1)
		{
			circle(leg.init.x, leg.init.y, 19, 360, 0xFF0000, mlx);
			circle(leg.init.x, leg.init.y, 18, 360, 0xFF0000, mlx);
			circle(leg.init.x, leg.init.y, 17, 360, 0xFF0000, mlx);
		}
		c[0] = nucleu->nd->nume;
		c[1] = 0;
		mlx_string_put(mlx->mlx, mlx->win, leg.init.x - 5, leg.init.y - 10, 0x00FFFFFF, c);
		while (much)
		{
			conv_char_int(&leg.final, much->nd->x);
			printf("nume nod %c nume %c xo = %d yo = %d xu = %d yu = %d\n", 
					nucleu->nd->nume, much->nd->nume, leg.init.x, leg.init.y, leg.final.x, leg.final.y);
			reinit_coord(reinit_coord_dublu(&leg, &point), 0xFFFFFF, mlx, much);
			much = much->dr;
		}
		nucleu = nucleu->dr;
	}
}

int				main (void)
{
	mlx_win	mlw;

	mlw.nuc.nucleu = 0;
	mlw.pres = 0;
	reinit_flag(&mlw);
	mlw.mlx = mlx_init();
	mlw.win = mlx_new_window(mlw.mlx, 1000, 1000, "gpurci");
	mlx_hook(mlw.win, KEY_PRESS, KEY_PRESS_MASK, &mouse_pres, &mlw);
	mlx_hook(mlw.win, MOTION_NOTIFY, PTR_MOTION, &mouse_motion, &mlw);
	mlx_key_hook(mlw.win, &my_key_fun, &mlw);
	mlx_mouse_hook(mlw.win, &my_mouse_fun, &mlw);
	mlx_loop_hook(mlw.mlx, &my_loop_hook_fun, &mlw);
	mlx_loop(mlw.mlx);
	return (0);
}
