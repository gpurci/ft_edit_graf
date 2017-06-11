/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpurci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 16:27:38 by gpurci            #+#    #+#             */
/*   Updated: 2017/02/13 15:58:28 by gpurci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graf.h"

int				coord_x_y(char *c)
{
	int			*i;
	static int	k;

	i = (int*)c;
	k = *i;
	k = k & 0xFFFF;
	return (k);
}

void				conv_int_char_coord(int x, int y, char *i)
{
	char			*k;

	k = (char*)&x;
	*i = *k;
	i[1] = k[1];
	k = (char*)&y;
	i[2] = *k;
	i[3] = k[1];
}

void				af_array_graf(int **array)
{
	int				i = 0;
	int				n = 0;

	while (array[i][0] != -1)
	{
		n = 0;
		printf("IIIIIIIIIIIII= %d\n", i + 1);
		while (array[i][n] != -1)
		{
			printf("ID = %d\t", array[i][n] + 1);
			n++;
		}
		printf("\n");
		i++;
	}
	printf("IIIIIII= %d ARAY = %d___________________\n", i, array[i][0]);
}

void				eliberare_memorie(int **array, int len)
{
	delete_array_graf(array, len);
	free(*array);
}

int					*aloc_unid_and_init(muchie *much, muchie *cap, int **array, int len)
{
	int				n;
	char			f = 1;

	if (!(n = num_muchii(much)))
	{
		n = 1;
		f = 0;
	}
	if (!(array[len] = (int*)malloc(sizeof(int) * (n + 1))))
	{
		eliberare_memorie(array, len);
		return (0);
	}
	array[len][n] = -1;
	if (f == 0)
		array[len][0] = -2;
	else
		coincidenta_nume(array[len], cap, much);
	return (array[len]);
}

int				**aloc_tabl_bid_array(int len)
{
	int			**array;

	if (!(array = (int**)malloc(sizeof(int *) * (len + 1))))
		return (0);
	if (!(array[len] = (int*)malloc(sizeof(int))))
	{
		free(*array);
		return (0);
	}
	array[len][0] = -1;
	return (array);
}

int					**conv_graf_lst_array(muchie *nucleu, int i, char nume)
{
	muchie			*cap;
	muchie			*much;
	int				**array;

	if (!(array = aloc_tabl_bid_array(i)))
		return (0);
	cap = nucleu;
	i = 0;
	while (nucleu->nd->nume != nume)
	{
		much = (muchie*)nucleu->nd->much;
		if (!(aloc_unid_and_init(much, cap, array, i)))
			return (0);
		nucleu = nucleu->dr;
		i++;
	}
	if (!(array[i] = (int*)malloc(sizeof(int) * 2)))
	{
		eliberare_memorie(array, i);
		return (0);
	}
	array[i][0] = -3;
	array[i][1] = -1;
	return (array);
}
