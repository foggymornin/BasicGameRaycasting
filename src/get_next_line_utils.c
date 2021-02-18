/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafajat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 11:35:22 by mafajat           #+#    #+#             */
/*   Updated: 2019/11/12 15:24:30 by mafajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

char		*cut(char *s, int i)
{
	int		n;
	char	*ss;

	if (i == 0)
	{
		free(s);
		return (0);
	}
	n = i;
	while (s[n])
		n++;
	ss = (char *)malloc(sizeof(char) * (n - i + 1));
	if (!ss)
		return (freeass2(ss));
	n = 0;
	while (s[i])
		ss[n++] = s[i++];
	ss[n] = 0;
	free(s);
	return (ss);
}

char		*dupnl(char *s)
{
	int		i;
	char	*ss;

	i = 0;
	while (s[i] != '\n' && s[i])
		i++;
	ss = (char *)malloc(sizeof(char) * (i + 1));
	if (!ss)
		return (freeass2(ss));
	i = 0;
	while (s[i] != '\n' && s[i])
	{
		ss[i] = s[i];
		i++;
	}
	ss[i] = 0;
	return (ss);
}

int			searchnl(char *s)
{
	int i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '\n')
		{
			return (++i);
		}
		i++;
	}
	return (0);
}

char		*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	int		k;
	char	*s;

	k = ft_strlen(s1) + ft_strlen(s2);
	if (!(s = malloc(sizeof(char) * (k + 1))))
		return (freeass2(s));
	j = 0;
	i = 0;
	while (i < k)
	{
		if (s1[i] != 0)
		{
			s[i] = s1[i];
			i++;
		}
		else
			while (s2[j])
				s[i++] = s2[j++];
	}
	s[i] = 0;
	free(s2);
	free(s1);
	return (s);
}

size_t		ft_strlen(char *s)
{
	size_t n;

	n = 0;
	while (s[n])
		n++;
	return (n);
}
