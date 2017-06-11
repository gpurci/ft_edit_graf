/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_graf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpurci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 17:31:01 by gpurci            #+#    #+#             */
/*   Updated: 2017/02/13 17:48:26 by gpurci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graf.h"

void					help(mlx_win *mlw)
{
	int					fd;
	char				y = 10;
	char				*line;

	fd = open("help.txt", O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		mlx_string_put(mlw->mlx, mlw->win, 10, y, 0xFFFFFF, line);
		y += 14;
		ft_strclr(line);
		free(line);
	}
	close(fd);
	reinit_flag(mlw);
}
