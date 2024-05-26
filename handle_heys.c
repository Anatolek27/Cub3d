#include "cub3d.h"

int	key_press(int key, t_data *data)
{
	if (key == KEY_W)
		data->player.move.x = 1;
	if (key == KEY_S)
		data->player.move.y = 1;
	if (key == KEY_A)
		data->player.move.x = 1;
	if (key == KEY_D)
		data->player.move.y = 1;
	if (key == KEY_LEFT)
		data->player.rotate.x = 1;
	if (key == KEY_RIGHT)
		data->player.rotate.y = 1;
	return (0);
}

int	key_release(int key, t_data *data)
{
	if (key == KEY_W)
		data->player.move.x = 0;
	if (key == KEY_S)
		data->player.move.y = 0;
	if (key == KEY_A)
		data->player.move.x = 0;
	if (key == KEY_D)
		data->player.move.y = 0;
	if (key == KEY_LEFT)
		data->player.rotate.x = 0;
	if (key == KEY_RIGHT)
		data->player.rotate.y = 0;
	if (key == KEY_ESC)
		return (ft_error(data));
	return (0);
}

void	main_loop(t_data *data)
{
	mlx_hook(data->win, 
}
