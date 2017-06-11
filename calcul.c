/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpurci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 16:36:55 by gpurci            #+#    #+#             */
/*   Updated: 2017/02/13 15:56:15 by gpurci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graf.h"

int					distanta_graf(int xo, int yo, int xu, int yu)
{
	return (pow(pow(abs(xu - xo), 2) + pow(abs(yu - yo), 2), 0.5));
}

int					num_muchii(muchie *much)
{
	int				i = 0;
	while (much)
	{
		i++;
		much = much->dr;
	}
	return (i);
}

void				alg_djekstra(Djekstra *dist, int *array, int i)
{
	int				j = 0;
	unsigned int	R;

	while (array[j] != -1)
	{
		if (array[j] > -1)
		{
			printf("IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIalg djjjgh aray = %d\n", array[j]);
			R = (unsigned int)distanta_graf(dist[i].x, dist[i].y, dist[array[j]].x, dist[array[j]].y) + dist[i].len;
			if (R < dist[array[j]].len)
			{
				dist[array[j]].len = R;
				dist[array[j]].IDsursa = i;
				if (dist[array[j]].stare != 2)
					dist[array[j]].stare = 1;
			}
		}
		j++;
	}
	printf("ALGORITM DJECSRR-------- J = %d\n", j);
	dist[i].stare = 2;
}

int					ver_stare(Djekstra *dist, int len_graf)
{
	int				i = 0;

	while (i < len_graf)
	{
		if (dist[i].stare == 1)
			break ;
		i++;
	}
	return (i);
}

void					dist_min_nod(mlx_win *mlw, Djekstra *dist, int dest)
{
	char				c[] = "NO";
	dublu_coord			len;

	if (dist[dest].IDsursa == -1)
		mlx_string_put(mlw->mlx, mlw->win, 495, 100, 0x00FFFFFF, c);
	else
	{
		while (dest > 0)
		{
			len.init.x = dist[dist[dest].IDsursa].x;
			len.init.y = dist[dist[dest].IDsursa].y;
			len.final.x = dist[dest].x;
			len.final.y = dist[dest].y;
			reinit_coord(&len, 0xFF00, mlw, 0);
			dest = dist[dest].IDsursa;
		}
	}
}
