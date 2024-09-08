#include "../Cub3d.h"

int get_width(t_data *data)
{
  int w;
  int i;
  int j;

  w = 0;
  i = 0;
  while (data->file[i])
  {
    if (line_is_empty(data->file[i]) == 1)
    {
      j = 0;
      while (data->file[i][j])
        j++;
      if (j > w)
        w = j;
    }
    i++;
  }
  return (w);
}

int get_count(char **file)
{
  int i;
  int c;

  c = 0;
  i = 0;
  while (file[i])
  {
    c += line_is_empty(file[i]);
    i++;
  }
  return (c);
}

void remove_empty_lines(t_data *data)
{
  int i;

  i = 0;
  data->map.length = get_count(data->file);
  data->tmp = ft_calloc(data->map.length + 1, sizeof(char *));
  if (data->tmp == NULL)
    exit(ft_exit(data, "Malloc error"));
  data->map.width = get_width(data);
  data->tmp[data->map.length] = NULL;
  while (i < data->map.length)
  {
    data->tmp[i] = ft_calloc(data->map.width + 1, sizeof(char *));
    i++;
  }
  get_clean_file(data);
}

void check_path(t_data *data)
{
  int i;
  i = ft_strlen(data->paths.pfile) - 1;
  if (data->paths.pfile[i] != 'b' || data->paths.pfile[i - 1] != 'u' ||
      data->paths.pfile[i - 2] != 'c' || data->paths.pfile[i - 3] != '.')
    exit (ft_exit(data, "File must have .cub extension"));
  data->fd = open(data->paths.pfile, O_RDONLY);
  if (data->fd < 0)
    exit (ft_exit(data, "File can't be opened"));
  data->file = ft_calloc(get_line_nb(data) + 1, sizeof(char *));
  if (!data->file)
    exit (ft_exit (data, "Malloc error"));
}

void parsing(t_data *data)
{
  check_path(data);
  data->fd = open(data->paths.pfile, O_RDONLY);
  if (data->fd < 0)
    exit (ft_exit(data, "File can't be opened"));
  get_file(data);
  close (data->fd);
  remove_empty_lines(data);
  //get_paths(data);
  //check_paths(data); //Debut des bugs
  //get_map(data);
}