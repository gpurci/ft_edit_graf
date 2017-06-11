/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nod_muchie.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpurci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 18:13:56 by gpurci            #+#    #+#             */
/*   Updated: 2017/02/13 13:49:11 by gpurci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graf.h"

nod					*cre_nod(char nume, char *i)
{
	nod				*lst_nod;

	if (!(lst_nod = (nod*)malloc(sizeof(nod))))
		return (0);
	lst_nod->nume = nume;
	lst_nod->stare = 1;
	lst_nod->x[0] = *i;
	lst_nod->x[1] = *(++i);
	lst_nod->y[0] = *(++i);
	lst_nod->y[1] = *(++i);
	lst_nod->much = 0;
	return (lst_nod);
}

muchie				*cre_muchie(nod *jos)
{
	muchie			*lst_much;

	if (!(lst_much = (muchie*)malloc(sizeof(muchie))))
		return (0);
	lst_much->dr = 0;
	lst_much->st_much = 1;
	lst_much->nd = jos;
	return (lst_much);
}

void				back_muchie(muchie *lst_much, nod *jos)
{
	muchie			*beg;

	if ((beg = cre_muchie(jos)))
	{
		while (lst_much->dr)
			lst_much = lst_much->dr;
		lst_much->dr = beg;
	}
}

void				add_much(muchie **lst_much, nod *nd)
{
	if (*lst_much)
		back_muchie(*lst_much, nd);
	else
		(*lst_much) = cre_muchie(nd);
}

void				af_graf(muchie *nucleu)
{
	int				x;
	int				y;
	muchie				*much;

	while (nucleu)
	{
		much = (muchie*)nucleu->nd->much;
		x = coord_x_y(nucleu->nd->x);
		y = coord_x_y(nucleu->nd->y);
		printf("nume nod %c x = %d y = %d nume muchii\n", nucleu->nd->nume, x, y);
		while (much)
		{
			x = coord_x_y(nucleu->nd->x);
			y = coord_x_y(nucleu->nd->y);
			printf("nume %c x =%d y=%d\n", much->nd->nume, x, y);
			much = much->dr;
		}
		nucleu = nucleu->dr;
	}
}

char				*coord(char *c)
{
	int				i;

	static char		x[4];
	char			*y;

	i = atoi(c);
	y = (char*)&i;
	x[0] = *y;
	x[1] = *(y + 1);
	while (i > 0)
	{
		i /= 10;
		c++;
	}
	c++;
	i = atoi(c);
	y = (char*)&i;
	x[2] = *y;
	x[3] = *(y + 1);
	return (x);
}

void				cre_graf(muchie **lst_much, int ac, char **c)
{
	int				i = 1;
	int				j;
	char			f;
	muchie			*beg;
	muchie			*tmp;
	muchie			*ap;

	while (i < ac)
	{
		add_much(lst_much, cre_nod(*c[i], coord((c[i] + 2))));
		i++;
	}
	i = 1;
	ap = *lst_much;
	while (i < ac)
	{
		j = 0;
		f = 0;
		beg = 0;
		while (c[i][j] && c[i][j] != ')')
			j++;
		j += 2;
		while (c[i][j])
		{
			if (c[i][j] != ')' && c[i][j] != ',' && c[i][j] != ' ')
			{
				tmp = *lst_much;
				while (c[i][j] != tmp->nd->nume)
					tmp = tmp->dr;
				add_much(&beg, tmp->nd);
			}
			j++;
		}
		ap->nd->much = (void*)beg;
		ap = ap->dr;
		i++;
	}
}
