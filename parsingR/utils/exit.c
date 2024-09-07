#include "../Cub3d.h"

void ft_exit2(t_data *data)
{
  	int i;

  	i = 0;
	if (data->tmp)
	{
		while (data->tmp[i])
		{
			free(data->tmp[i]);
            data->tmp[i] = NULL;
			i++;
		}
		free(data->tmp);
	}
    if (data->paths.pc)
      free(data->paths.pc);
    if (data->paths.pf)
      free(data->paths.pf);
    if (data->paths.pn)
      free(data->paths.pn);
    if (data->paths.ps)
      free(data->paths.ps);
	exit (0);
}

int ft_exit (t_data *data, char *err)
{
	int i;

	i = 0;
    if (data->paths.pfile)
    	free(data->paths.pfile);
	ft_exit2(data);
	if (data->paths.pw)
		free(data->paths.pw);
	if (data->paths.pe)
		free(data->paths.pe);
	if (data->file != NULL)
	{
		while (data->file[i] != NULL)
		{
			free(data->file[i]);
			data->file[i] = NULL;
			i++;
		}
		free(data->file);
        data->file = NULL;
	}
	printf ("%s\n", err);
	return (0);
}