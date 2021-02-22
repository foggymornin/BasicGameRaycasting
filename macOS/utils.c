
#include "cub3d.h"

char		*ft_strjoin2(char *s1, char *s2)
{
	int		i;
	int		j;
	int		k;
	char	*s;

	k = ft_strlen(s1) + ft_strlen(s2);
	if (!(s = malloc(sizeof(char) * (k + 2))))
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
    s[i] = '\n';
	s[i + 1] = 0;
	free(s2);
	free(s1);
	return (s);
}