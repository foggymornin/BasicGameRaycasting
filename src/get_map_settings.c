/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_settings.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafajat <mafajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 01:43:53 by mafajat           #+#    #+#             */
/*   Updated: 2021/02/17 03:11:58 by mafajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

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

int    ft_check_map(char* line)
{
    if (ft_wall_maria(line) == 0)
        return (0);
    while(*line == ' ')
        line++;
    if (*line == '1')
    {
        line++;
        if (*line != '1')
        {
            printf("i'm here");
            while (ft_valid_character(line))
            {
                printf("%d\n", ft_valid_character(line));
                if (*line == '1')
                    return(1);
                line++;
            }
        }
    }
    return(0);
}
int     ft_valid_character(char *l)
{
    if (*l == 0 || *l == 1 || *l == 2)
        return (1);
    if (*l == 'N' || *l == 'S' || *l == 'E' || *l == 'W')
        return (1);
    return(0);
}

int     ft_wall_maria(char *l)
{
    if (wall.maria == 1)
        return(1);
    if (ft_wall_maria(l))
        wall.maria = 1;
    while (*l == ' ')
        l++;
    while (*l == '1')
    {
        l++;
        while (*l == ' ')
        {
            l++;
            if (*l == 0)
                return (1);
        }
        if (*l == 0)
            return(1);
    }
    return (0);
}

void    ft_map(char *l)
{
    int i;

    i = 0;
  // printf("\n%d", ft_check_map(l));
    
    if (ft_check_map(l) ==  1)
    {
        map.y++;
        map.x = 0;
        while (l[i])
        {
            if (ft_valid_character(l + i))
                map.x++;
            i++;
        }
        i = 0;
        map.map[map.y] = (char *)malloc (sizeof(char) * map.x + 1);
        while (i <= map.x)
        {
            map.map[map.y][i] = l[i];
            i++;
            if (i == map.x)
            map.map[map.y][i] = 0;
        }
        printf("%s", map.map[map.y]);
    }
}
void    ft_get_map_settings(char *map)
{
    char *line;
    int fd;
    int r;

    r = 1;
    fd = open(map, O_RDONLY);
    while(r != 0)
    {
        r = get_next_line(fd, &line);
       // printf("%s\n", line);
        ft_resolution(line);
        ft_map(line);
    }
}