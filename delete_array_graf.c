/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_array_graf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpurci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 20:05:54 by gpurci            #+#    #+#             */
/*   Updated: 2017/02/11 15:34:17 by gpurci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graf.h"

void					delete_array_graf(int **array, int k)
{
	int					i = 0;
	int					j;

	while (i < k)
	{
		j = 0;
		while (array[i][j] != -1)
		{
			array[i][j] = 0;
			j++;
		}
		free(array[i]);
		i++;
	}
}

void					delete_djekstra(Djekstra *dist, int len)
{
	int					i = 0;

	while (i < len)
	{
		dist[i].ID = 0;
		dist[i].nd = 0;
		dist[i].IDsursa = 0;
		dist[i].len = 0;
		dist[i].x = 0;
		dist[i].y = 0;
		dist[i].stare = 0;
		i++;
	}
	free(dist);
}
