#include "../Cub3d.h"

void get_clean_file(t_data *data)
{
  int i;
  int j;

  i = 0;
  j = 0;
  while (data->file[i])
  {
    if (line_is_empty(data->file[i]) == 1)
      data->tmp[j++] = data->file[i];
    i++;
  }
}

void get_file(t_data *data)
{
	char	*line;
    int i;
    int j;
    int c;

	i = 0;
    j = 0;
    c = 0;
    line = get_next_line(data->fd);
	while (line != NULL)
	{
		data->file[i] = ft_calloc(ft_strlen(line) + 1, sizeof(char));
		if (!data->file[i])
			exit (ft_exit(data, "Malloc error"));
		while (line[j] != '\0')
			data->file[i][j++] = line[c++];
		data->file[i++][j] = '\0';
		j = 0;
        c = 0;
		free(line);
		line = get_next_line(data->fd);
	}
	data->file[i] = NULL;
    close (data->fd);
}