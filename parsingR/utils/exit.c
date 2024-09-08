#include "../Cub3d.h"
void free_paths2(t_data *data)
{
	write(1, "free_paths2 entered\n", 20);
	if (data->paths.pfile != NULL)
	{
		write(1, "pfile\n", 6);
		free(data->paths.pfile);
		data->paths.pfile = NULL;
	}
	if (data->paths.pc != NULL)
	{
		write(1, "pc\n", 3);
		free(data->paths.pc);
		data->paths.pc = NULL;
	}
	if (data->paths.pf != NULL)
	{
		write(1, "pf\n", 3);
		free(data->paths.pf);
		data->paths.pf = NULL;
	}
	write(1, "free_paths2 closed\n", 19);
}

void free_paths(t_data *data)
{
	write(1, "free_paths entered\n", 19);
	if (data->paths.pn != NULL)
	{
		free(data->paths.pn);
		data->paths.pn = NULL;
	}
	if (data->paths.ps != NULL)
	{
		free(data->paths.ps);
		data->paths.ps = NULL;
	}
	if (data->paths.pw != NULL)
	{
		free(data->paths.pw);
		data->paths.pw = NULL;
	}
	if (data->paths.pe != NULL)
	{
		free(data->paths.pe);
		data->paths.pe = NULL;
	}
	write(1, "free_paths closed\n", 18);
}

void ft_exit2(t_data *data)
{
	write(1, "Ft_exit2 entered\n", 17);
	int i;

	i = 0;
	if (data->tmp != NULL)
	{
		while (data->tmp[i] != NULL)
		{
			free(data->tmp[i]);
			data->tmp[i] = NULL;
			i++;
		}
		free(data->tmp);
		data->tmp = NULL;
	}
	write(1, "Ft_exit2 closed\n", 16);
}

int ft_exit(t_data *data, char *err)
{
	write(1, "Ft_exit entered\n", 16);
	int i;

	i = 0;
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
	//free_paths2(data);
	free_paths(data);
	//ft_exit2(data);
	printf("%s\n", err);
	write(1, "Ft_exit closed\n", 15);
	return (0);
}