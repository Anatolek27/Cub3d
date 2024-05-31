#include "cub3d.h"


void	get_width(t_data *data)
{
	int	tmp;
	int	length;
	int		i;
	int		j;

	tmp = 0;
	i = 0;
	while (data->map[i])
	{
		length = 0;
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == '\t')
				length += 4;
			else
				length++;
			j++;
		}
		if (length > tmp)
			tmp = length;
		i++;
	}
	data->map_width = tmp;
}

char	**get_map_and_height(int fd, char *line, t_data *data)
{
	char	**lines;
	int		i;

	i = 0;
	lines = malloc(sizeof(char *));
	if (!lines)
		exit(1);
	while (1)
	{
		lines = ft_realloc(lines,
				(i + 1) * sizeof(char *),
				(i + 2) * sizeof(char *));
		if (!lines)
			exit(1);
		lines[i++] = ft_strdup(line);
		free(line);
		if (!get_next_line(fd, &line) && *line == 0)
			break ;
	}
	free(line);
	lines[i] = 0;
	data->map_height = i;
	return (lines);
}