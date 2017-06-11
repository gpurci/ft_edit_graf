/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_mouse_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpurci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 19:40:34 by gpurci            #+#    #+#             */
/*   Updated: 2017/02/13 16:56:14 by gpurci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graf.h"

void			delete_graf(mlx_win *mlw)
{
	del_graf(&mlw->nuc.nucleu);
	mlx_clear_window (mlw->mlx, mlw->win);
	reinit_flag(mlw);
}

void			exit_graf(mlx_win *mlw)
{
	delete_graf(mlw);
	exit(0);
}

void			delete_one_nod(mlx_win *mlw)
{
	del_nod(&mlw->nuc.nucleu, mlw->nuc.nd->nume);	
	reinit_frame_graf(mlw);	
	reinit_flag(mlw);
}

void			stare_nod_nev(mlx_win *mlw)
{
	mlw->nuc.nd->stare = 0;	
	reinit_frame_graf(mlw);	
	reinit_flag(mlw);
}

void			stare_nod_val(mlx_win *mlw)
{
	mlw->nuc.nd->stare = 1;	
	reinit_frame_graf(mlw);	
	reinit_flag(mlw);
}

void			stare_much_val(mlx_win *mlw, char nume)
{
	muchie		*much;

	cautare_nod(mlw->nuc.nd->much, &much, nume);
	if (much)
		much->st_much = 1;
	reinit_frame_graf(mlw);	
	reinit_flag(mlw);
}

void			stare_much_nev(mlx_win *mlw, char nume)
{
	muchie		*much;

	cautare_nod(mlw->nuc.nd->much, &much, nume);
	if (much)
		much->st_much = 0;
	reinit_frame_graf(mlw);	
	reinit_flag(mlw);
}

int				my_key_fun(int keycode, void *param)
{
	mlx_win		*mlw;
	static int	x = 10;
	int			y = 900;
	char		c[2];

	c[0] = ascii(keycode);
	c[1] = 0;
	mlw = (mlx_win*)param;
	if (keycode == kVK_Backspace && mlw->pres == 1)
		delete_one_nod(mlw);
	else if (keycode == kVK_ANSI_KeypadEnter)
		help(mlw);
	else if (keycode == kVK_Escape)
		exit_graf(mlw);
	else if (keycode == kVK_ANSI_G && mlw->nume == 8)
		delete_graf(mlw);
	else if (mlw->nume == 'm' && mlw->pres == 1)
		del_one_much(mlw, c[0]);
	else if (mlw->nume == 'n' && mlw->pres == 1)
		reinit_name(mlw, c[0]);
	else if (c[0] == 'p' && mlw->pres == 1)
		stare_nod_nev(mlw);
	else if (c[0] == 'i' && mlw->pres == 1)
		stare_nod_val(mlw);
	else if (keycode == kVK_Space)
		reinit_flag(mlw);
	else if (mlw->nume == 'k' && mlw->pres == 1)
		stare_much_val(mlw, c[0]);
	else if (mlw->nume == 'l' && mlw->pres == 1)
		stare_much_nev(mlw, c[0]);
	mlw->nume = c[0];
	x += 8;
	printf("key = %d  ascii code =%c| pres = %d nume = %c\n", 
			keycode, c[0], mlw->pres, mlw->nume);
	mlx_string_put(mlw->mlx, mlw->win, x, y, 0xFFFFFF, c);

	return (0);
}

int 			my_key_name(int name, void *q)
{
	char		*c;

	c = (char*)q;
	*c = ascii(name);
	return (0);
}

int				my_mouse_fun(int button, int x, int y, void *param)
{
	static  int	time_d;
	static int	time;
	mlx_win		*mlw;

	time = clock();
	mlw = (mlx_win*)param;
	printf("but = %d x = %d y = %d time = %d time_d = %d diff = %d add = \n", 
			button, x, y, time, time_d, time - time_d);
	if (time - time_d < 30000 && button == 1 && mlw->but == 1)
	{
		cre_graf_mouse(&mlw->nuc.nucleu, x, y, mlw->nume);
		grafic_graf(mlw);	
	}
	time_d = time;	
	return (0);
}

int				mouse_motion(int x, int y, void *q)
{
	mlx_win		*mlw;

	mlw = (mlx_win*)q;
	if (mlw->nume == 's' && mlw->pres == 1)
		reinit_coord_graf(mlw, x, y);
	printf("x = %d y = %d pres= |%d| nume =%c key = %d but = %d\n",
		   	x, y, mlw->pres, mlw->nume, mlw->key, mlw->but);
	return (0);
}

int				my_loop_hook_fun(void *par)
{
	mlx_win		*mlw;
	mlw = (mlx_win*)par;

	//mlx_mouse_hook(mlw->win, &my_mouse_fun, &par);
	//mlx_loop(mlw->mlx);
	return (0);
}

int				mouse_pres(int k, int x, int y, void *q)
{
	mlx_win		*mlw;

	mlw = (mlx_win*)q;
	printf("addres Q = |%p| pres =%d\n", q, mlw->pres);
	if (k == 2)
	{
		if (cre_mouse_much(mlw, x, y))
			mlw->pres++;
		reinit_frame_graf(mlw);
		if (mlw->nume == 'd' && mlw->pres == 2)
			djeckstra(mlw);
		if (mlw->pres == 2)
			mlw->pres = 0;
	}
	mlw->but = k;
	printf("PRES = %d\nSF_PRES\n", mlw->pres);
	return (0);
}
