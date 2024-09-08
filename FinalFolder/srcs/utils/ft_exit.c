#include "../../Cub3d.h"

int	ft_exit(t_data *data, char *err)
{
	if (err != NULL)
		printf("%s.\n", err);
	if (data->paths.pfile != NULL)
		free (data->paths.pfile);
	return (0);
}