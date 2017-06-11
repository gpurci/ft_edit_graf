/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpurci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 19:21:30 by gpurci            #+#    #+#             */
/*   Updated: 2017/02/06 17:45:02 by gpurci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int					ver_gnl(char *c)
{
	char			*addres;

	if ((addres = ft_strchr(c, 10)))
	{
		*addres = '\0';
		return (1);
	}
	return (0);
}

char				*gnl_strjoin(char *s)
{
	int				i;
	char			*dest;

	i = ft_strlen(s);
	if (!(dest = ft_strnew(i + 1)))
		return (0);
	ft_strcpy(dest, s);
	return (dest);
}

int					gnl_init(char **list, char **line, char **buf)
{
	if (!*list)
		if (!(*list = ft_strdup("\0")))
			return (-1);
	if (ver_gnl(*list))
	{
		if (!(*line = ft_strdup(*list)))
			return (-1);
		*buf = *list;
		if (!(*list = gnl_strjoin(*list + ft_strlen(*list) + 1)))
			return (-1);
		ft_strclr(*buf);
		ft_strdel(buf);
		return (1);
	}
	if (!(*buf = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (-1);
	return (2);
}

int					gnl_finish(char **list, char **line, char **buf, int ret)
{
	int				i;

	*line = ft_strdup(*list);
	ft_strclr(*list);
	ft_strdel(list);
	if (ret > (i = (int)ft_strlen(*buf)))
		if (!(*list = gnl_strjoin(*buf + i + 1)))
			return (-1);
	if (ret > 0 || (ret == 0 && **line != '\0'))
		ret = 1;
	ft_strclr(*buf);
	ft_strdel(buf);
	return (ret);
}

int					get_next_line(int const fd, char **line)
{
	int				ret;
	int				i;
	static char		*list[256];
	char			*buf[2];

	if (fd < 0)
		return (-1);
	if ((i = gnl_init(&list[fd], line, &buf[0])) != 2)
		return (i);
	while ((ret = read(fd, buf[0], BUFF_SIZE)) > 0)
	{
		buf[0][ret] = '\0';
		i = ver_gnl(buf[0]);
		buf[1] = list[fd];
		if (!(list[fd] = ft_strjoin(list[fd], buf[0])))
			return (-1);
		ft_strclr(buf[1]);
		ft_strdel(&buf[1]);
		if (i == 1)
			break ;
	}
	if (ret == -1)
		return (-1);
	return (gnl_finish(&list[fd], line, &buf[0], ret));
}
