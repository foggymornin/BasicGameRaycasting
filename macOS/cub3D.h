#ifndef CUB3D_H
# define CUB3D_H

//# include "libft/libft.h"
# include "mlx.h"
# include "gnl/get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>



typedef struct s_map
{
    int r_x;
    int r_y;
    int player_x;
    int player_y;
    int linenumber;
    size_t longestline;
    char *data;
    char **map;
    int  element;
}   t_map;

t_map sett;

# define MI 2147483647
int		freeass(char *s);
char	*freeass2(char *s);
int		get_next_line(int fd, char **l);
size_t	ft_strlen(char *s);
int		searchnl(char *s);
char	*cut(char *s, int i);
char	*dupnl(char *s);
char	*ft_strjoin(char *s1, char *s2);
#define BUFFER_SIZE 100
int     ft_put(void);


void    ft_get_map_settings(char *map);
void    ft_resolution(char *line);
int		ft_atoi(const char *str);
char    *ft_shift_line(char *line, char c);
int    ft_check_map(char* line );
int     ft_valid_character(char *l);
int     ft_wall_maria(char *l);
char		*ft_strjoin2(char *s1, char *s2);
#endif