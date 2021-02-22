/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_settings.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafajat <mafajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 01:43:53 by mafajat           #+#    #+#             */
/*   Updated: 2021/02/20 18:42:42 by mafajat          ###   ########.fr       */
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
    while(*line == ' ')
        line++;
    if (*line == '1')
    {
        line++;
        map.line++;
        if (map.line == 1)
            return (ft_wall_maria(line));
        if (*line != '1')
        {
            //printf("ok ");
            while (ft_valid_character(line))
            {
              //  printf("ok2 ");
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
    if (*l == '0' || *l == '1' || *l == '2')
        return (1);
    if (*l == 'N' || *l == 'S' || *l == 'E' || *l == 'W')
        return (1);
    return(0);
}

int     ft_wall_maria(char *l)
{
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
    int r;
    i = 0;
    
    r = ft_check_map(l);
    printf("map line %d : %d\n", map.line , r);
    /*
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
    */
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
        if (ft_ismap(char line))
        {
            while (r != 0)
            map.map = ft_strjoin(map.map, line);
            
        }
    }
}