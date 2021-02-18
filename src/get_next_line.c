/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafajat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:19:13 by mafajat           #+#    #+#             */
/*   Updated: 2019/11/12 15:23:28 by mafajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int		freeass(char *s)
{
	free(s);
	return (-1);
}

char	*freeass2(char *s)
{
	free(s);
	return (NULL);
}

int		get_next_line(int fd, char **l)
{
	char		*part;
	static char *s[4864];
	int			r;

	if (BUFFER_SIZE > MI || fd < 0 || BUFFER_SIZE < 1 || l == NULL)
		return (-1);
	if (!(part = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (freeass(part));
	if ((r = read(fd, part, BUFFER_SIZE)) < 0)
		return (freeass(part));
	part[r] = 0;
	if (!s[fd])
		s[fd] = part;
	else if (!(s[fd] = ft_strjoin(s[fd], part)))
		return (freeass(s[fd]));
	if (searchnl(s[fd]) || BUFFER_SIZE > r)
	{
		if (!(*l = dupnl(s[fd])))
			return (freeass(s[fd]));
		r = searchnl(s[fd]);
		if (!(s[fd] = cut(s[fd], r)))
			return (r ? -1 : 0);
		return (1);
	}
	return (get_next_line(fd, l));
}
