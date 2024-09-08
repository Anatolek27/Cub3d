#include "Cub3d.h"

int main(int argc, char **argv)
{
  //int i = 0;
  t_data data;
  if (argc != 2)
    return (ft_exit(&data, "Expected exactly 1 argument.\n"));

  data.paths.pfile = malloc(sizeof(char) * ft_strlen(argv[1]));
  return (ft_exit(&data, "test exit"));
  if (!data.paths.pfile)
    return (ft_exit(&data, "Malloc error"));
  data.paths.pfile = argv[1];
  parsing(&data);
  /*while (data.tmp[i])
  {
    printf("%d: %s", i, data.tmp[i]);
    i++;
  }
  printf("\n%d\n", data.map.length);*/
  return (ft_exit(&data, "\nSee you soon"));
}