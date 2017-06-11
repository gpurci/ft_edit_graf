/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dist_graf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpurci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 12:25:15 by gpurci            #+#    #+#             */
/*   Updated: 2017/02/13 15:56:18 by gpurci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graf.h"

Djekstra				*init_dist(mlx_win *mlw, int i)
{
	muchie				*much;
	Djekstra			*dist;

	much = mlw->nuc.nucleu;
	if (!(dist = malloc(sizeof(Djekstra) * i)))
		return (0);
	i = 0;
	while (much)
	{
		if ((much->nd->stare & 1) == 1)
		{
			dist[i].ID = i;
			dist[i].nd = much->nd;
			dist[i].IDsursa = 0;
			dist[i].len = ~(0);
			dist[i].x = coord_x_y(much->nd->x);
			dist[i].y = coord_x_y(much->nd->y);
			dist[i].stare = 0;
		}
		else
		{
			dist[i].stare = 2;
			dist[i].nd = much->nd;
		}
		much = much->dr;
		i++;
	}
	return (dist);
}

void					swap_djekstra(Djekstra *src, Djekstra *dest, int **a, int **b)
{
	Djekstra			k;
	int					*i;

	i = *a;
	*a = *b;
	*b = i;

	k.nd = src[0].nd;
	k.x = src[0].x;
	k.y = src[0].y;

	src[0].nd = dest[0].nd;
	src[0].x = dest[0].x;
	src[0].y = dest[0].y;

	dest[0].nd = k.nd;
	dest[0].x = k.x;
	dest[0].y = k.y;
}

void					af_djekstra(Djekstra *dist, int len_graf)
{
	int					i = 0;

	while (i < len_graf)
	{
		printf("nume %c ID = %d sursa %d len %d stare %d x = %d y = %d\n", 
				dist[i].nd->nume, dist[i].ID, dist[i].IDsursa, dist[i].len, dist[i].stare, dist[i].x, dist[i].y);
		i++;
	}
}

void					rearanjare_nucleu(mlx_win *mlw)
{
	muchie				*much;
	muchie				*lst;
	muchie				*sec;

	sec = mlw->nuc.nucleu;
	much = cautare_nod(mlw->nuc.nucleu, &lst, mlw->nuc.lst_nd->nume);
	if (much)
	{
		much->dr = lst->dr;
		lst->dr = sec;
		mlw->nuc.nucleu = lst;
	}
	sec = mlw->nuc.nucleu;
	while (sec->dr)
		sec = sec->dr;
	much = cautare_nod(mlw->nuc.nucleu, &lst, mlw->nuc.nd->nume);
	if (much)
	{
		if (lst->dr)
		{
			much->dr = lst->dr;
			lst->dr = 0;
			sec->dr = lst;
		}
	}
}

void					creare_cale(mlx_win *mlw, Djekstra *dist, int len_graf)
{
	int					i;
	int					**array;

	printf("BIIIIIIIIIIINNNNNNNNNNNNEEEEEEEEEEEEEEEEEE\n");

	if ((array = conv_graf_lst_array(mlw->nuc.nucleu, len_graf, mlw->nuc.nd->nume)))
	{
		i = 0;
		dist[0].len = 0;
		dist[len_graf - 1].stare = 2;
		dist[len_graf - 1].IDsursa = -1;
		af_array_graf(array);
		while (1)
		{
			alg_djekstra(dist, array[i], i);
			i = ver_stare(dist, len_graf);
			if (i == len_graf)
				break ;
		}
		printf("djekstra--------------\n");
		af_djekstra(dist, len_graf);
		af_array_graf(array);
		printf("--------------\n");
		delete_array_graf(array, len_graf);
		dist_min_nod(mlw, dist, len_graf - 1);
	}
}

void					djeckstra(mlx_win *mlw)
{
	Djekstra			*dist;
	int					n = 0;
	printf("dddddddddddddddddddddddddddddddddjjjjjjjjjjjjjjjjjjjjjjjjjeeeeeeeeeeeeeeeeeeeeI\n");
	af_graf(mlw->nuc.nucleu);
	printf("___________--------------\n");
	rearanjare_nucleu(mlw);
	af_graf(mlw->nuc.nucleu);
	printf("BBBBIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII\n");	
	if (mlw->nuc.nd && mlw->nuc.lst_nd)
	{
		n = num_muchii(mlw->nuc.nucleu);
		if ((dist = init_dist(mlw, n)))
		{
			printf("initDJEKSTRA-------------------------------\nNUMARUL MUCHII = %d\n", n);
			creare_cale(mlw, dist, n);
			delete_djekstra(dist, n);
			reinit_flag(mlw);
		}
		else
			printf("NoooooooooDJEKSTRA__________________________----------------------\n");
	}
}
