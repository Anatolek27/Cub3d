#include "../Cub3d.h"

int ft_strlen(char *str)
{
  int i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}

int get_line_nb(t_data *data)
{
  int i;
  char *line;

  i = 0;
  line = get_next_line(data->fd);
  while (line)
  {
    i++;
    free(line);
    line = get_next_line(data->fd);
  }
  close(data->fd);
  return (i);
}

void	ft_bzero(void *s, size_t n)
{
  unsigned char	*p;

  p = (unsigned char *)s;
  while (n != 0)
  {
    *p = '\0';
    p++;
    n--;
  }
}

void	*ft_calloc(size_t count, size_t size)
{
  void	*r;

  r = malloc(count * size);
  if (!r)
    return (NULL);
  ft_bzero(r, size * count);
  return (r);
}