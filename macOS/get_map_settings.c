/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_settings.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafajat <mafajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 01:43:53 by mafajat           #+#    #+#             */
/*   Updated: 2021/03/01 15:38:49 by mafajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char    *ft_shift_line(char *line, char c)
{
	while (*line == c)
		line++;
	while(*line != ' ' && *line)
		line++;
	return(line);
}
void    ft_resolution(char *line)
{
	if (*line)
	{
		if (*line == 'R' && *(line + 1) == ' ')
		{
			line++;
			sett.r_x = ft_atoi(line);
			line = ft_shift_line(line, ' ');
			sett.r_y = ft_atoi(line);
			sett.element++;
			//printf("%d\n", sett.r_x);
			//printf("%d\n", sett.r_y);
		}
	}
}

int    ft_ismap(char *l)
{
	char *player;
	int		i;
	int j;
	
	j = 0;
	i = 0;
	player = "NSEW";
	//printf("wtf %d", sett.player_y);
	
	while (l[i] == ' ' || l[i] == '\n')
	{
		printf("wtf");
		i++;
		if (l[i] == 0)
			return(0);
	}
	while (l[i])
	{
		if (l[i] == ' ' || l[i] == '1' || l[i] == '2' || l[i] == '0')
			i++;
		else if (!sett.player_y)
		{
			while(player[j])
			{
				if (l[i] == player[j])
				{
					sett.player_x = i;
					sett.player_y = j;
					i++;
					j = 0;
					break;
				}
				j++;
			}
		}
		if (player[j] == 0)
			return (0);	
	}
	return (1);
}

void	ft_stockmap()
{
	int x;
	size_t y;
	int i;

	i = 0;
	x = -1;
	y = 0;
	sett.map = (char **) malloc(sizeof(char *) * sett.linenumber);
	while(++x < sett.linenumber)
	{
		sett.map[x] = (char *) malloc(sizeof(char) * sett.longestline);
		while(sett.data[i] != '\n')
		{
			sett.map[x][y] = sett.data[i];
			y++;
			i++;
		}
		i++;
		while (y < sett.longestline)
		{
			sett.map[x][y] = ' ';
			y++;
		}
		y = 0;
	}
}

void    ft_get_map_settings(char *file)
{
	char *line;
	int fd;
	int r;
	char *er2;


	er2 = "Error\ninvalid map";
	sett.data = malloc (sizeof(char *));
	*sett.data = 0;
	r = 1;
	fd = open(file, O_RDONLY);
	while(r != 0)
	{
		r = get_next_line(fd, &line);
		ft_resolution(line);
		if (sett.element == 1 && *line != '\n')
		{
			if (ft_ismap(line))
			{
				sett.linenumber++;
				if (ft_strlen(line) > sett.longestline)
					sett.longestline = ft_strlen(line);
				sett.data = ft_strjoin2(sett.data, line);
			}
		}
	}
	ft_stockmap();
	//printf("%s\nnumber of lines : %d\nlongest line : %zu\n", sett.data, sett.linenumber, sett.longestline);
}