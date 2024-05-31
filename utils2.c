#include "cub3d.h"

char	*ft_strncpy(char *dest, char *src, int n)
{
	char *sav_dest;
	char *sav_src;

	sav_dest = dest;
	sav_src = src;
	if (n != 0)
	{
		while (1)
		{
			if ((*sav_dest++ = *sav_src++) == 0)
			{
				while (--n != 0)
					*sav_dest++ = 0;
				break ;
			}
			if (--n == 0)
				break ;
		}
	}
	return (dest);
}

int	get_next_line(int fd, char **line)
{
	char	buf;
	int		i;

	if (read(fd, 0, 0) == -1)
		return (-1);
	if (!(*line = malloc(1024)))
		return (-1);
	i = 0;
	while (read(fd, &buf, 1))
	{
		if (buf == '\n')
		{
			(*line)[i] = '\0';
			return (1);
		}
		(*line)[i++] = buf;
	}
	(*line)[i] = '\0';
	return (0);
}