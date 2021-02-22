/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_settings.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafajat <mafajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 01:43:53 by mafajat           #+#    #+#             */
/*   Updated: 2021/02/22 18:49:28 by mafajat          ###   ########.fr       */
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
            map.r_x = ft_atoi(line);
            line = ft_shift_line(line, ' ');
            map.r_y = ft_atoi(line);
            printf("%d\n", map.r_x);
            printf("%d\n", map.r_y);
        }
    }
}

int    ft_ismap(char *l)
{
    while (*l == ' ')
        l++;
    if (*l == '1')
        return (1);
    return(0);
}

void    ft_get_map_settings(char *file)
{
    char *line;
    int fd;
    int r;

	map.data = malloc (sizeof(char *));
	*map.data = 0;
    r = 1;
    fd = open(file, O_RDONLY);
    while(r != 0)
    {
        r = get_next_line(fd, &line);
        ft_resolution(line);
		while (r && ft_ismap(line))
		{
			map.linenumber++;
			if (ft_strlen(line) > map.longestline)
				map.longestline = ft_strlen(line);
			map.data = ft_strjoin2(map.data, line);
			r = get_next_line(fd, &line);
		}
    }
	printf("%s\nnumber of lines : %d\nlongest line : %zu\n", map.data, map.linenumber, map.longestline);
}