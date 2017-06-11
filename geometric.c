/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpurci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 19:36:17 by gpurci            #+#    #+#             */
/*   Updated: 2017/02/20 18:49:35 by gpurci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graf.h"

void			circle(int xo, int yo, int r, int arc, int color, mlx_win *mlx)
{
	int			x;
	int			y;
	long double	del;
	int			len;
	long double	del_a = 0;
	int			i = 0;


	len = round(PI * r * arc / 180);
	del = 1.0 / (long double)(r);
	mlx_pixel_put(mlx->mlx, mlx->win, x + r, y, color);
	while (i < len)
	{
		x = xo + r * cos(del_a);
		y = yo + r * sin(del_a);
		del_a += del;
		mlx_pixel_put(mlx->mlx, mlx->win, x, y, color);
		i++;
	}
}

void				line(int xo, int yo, int xu, int yu, int color, int scara, mlx_win *m_w)
{
	int v[6];

	v[0] = abs(xu - xo);
	v[1] = xo < xu ? 1 : -1;
	v[2] = abs(yu - yo);
	v[3] = yo < yu ? 1 : -1;
	v[4] = (v[0] > v[2] ? v[0] : -v[2]) / 2;
	while (1)
	{
		mlx_pixel_put(m_w->mlx, m_w->win, xo, yo, color);
		color += scara;
		v[5] = v[4];
		if ((xo == xu) && (yo == yu))
			break ;
		if (v[5] > -v[0])
		{
			v[4] -= v[2];
			xo += v[1];
		}
		if (v[5] < v[2])
		{
			v[4] += v[0];
			yo += v[3];
		}
	}
}
