#include "../Cub3d.h"

unsigned int rgb_to_hex(int *rgb)
{
  unsigned int hex = 0;

  hex = (rgb[0] << 16) | (rgb[1] << 8) | rgb[2];
  return hex;
}

int line_is_empty(char *line)
{
  int i;

  i = 0;
  while (line[i] != '\0')
  {
    if (line[0] == '\n' || line[0] == '\t' || line[0] == '\v' || line[0] == ' ')
    {
      while (line[i] == ' ' || line[i] == '\t' || line[i] == '\n' || line[i] == '\v')
      {
        if (line[i] == '\n')
          return 0;
        i++;
      }
    }
    return (1);
  }
  return (0);
}

void    tex_alloc(t_data *data, int t, int c)
{
  if (t == 1)
    data->paths.pn = malloc(sizeof(char) * c);
  else if (t == 2)
    data->paths.ps = malloc(sizeof(char) * c);
  else if (t == 3)
    data->paths.pw = malloc(sizeof(char) * c);
  else if (t == 4)
    data->paths.pe = malloc(sizeof(char) * c);
}

int	ft_isdigit(int c)
{
  if (c > 47 && c < 58)
    return (1);
  else
    return (0);
}

int	ft_atoi(const char *str)
{
  int	num;
  int	isneg;
  int	i;

  num = 0;
  isneg = 1;
  i = 0;
  while (str[i] && (str[i] == ' ' || str[i] == '\t'
      || str[i] == '\n' || str[i] == '\r'
      || str[i] == '\v' || str[i] == '\f'))
    i++;
  if (str[i] == '+')
    i++;
  else if (str[i] == '-')
  {
    isneg *= -1;
    i++;
  }
  while (ft_isdigit(str[i]))
  {
    num = (num * 10) + (str[i] - '0');
    i++;
  }
  return (num * isneg);
}