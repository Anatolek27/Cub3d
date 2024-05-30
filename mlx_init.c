#include "cub3d.h"

void	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		ft_error(data);
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Cub3D");
	if (!data->win)
		ft_error(data);
}
