/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cre_graf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpurci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 17:19:22 by gpurci            #+#    #+#             */
/*   Updated: 2017/02/07 16:34:46 by gpurci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graf.h"

void				cre_graf_mouse(muchie **much, int x, int y, char c)
{
	char			coord[4];

	conv_int_char_coord(x, y, coord);
	add_much(&(*much), cre_nod(c, coord));
}
