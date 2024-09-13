/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunegel <akunegel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 14:10:14 by hguillau          #+#    #+#             */
/*   Updated: 2024/09/13 12:50:17 by akunegel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Cub3d.h"

// close the mlx window
int	ft_close_win(void)
{
	exit(1);
}

/*
keycode :
	a = 97
	s = 115
	d = 100
	w = 119
	esc = 65'307
	-> = 65'363
	<- = 65'361
	tab = 65'289
	m = 109
*/
// deal with the key you press on keyboard
int	deal_key(int key, t_data *data)
{
	(void)data; // remove after doing movement
	if (key == 65307) // echap
		ft_close_win();
//	if (key == 97 || key == 115 || key == 100 || key == 119)
//		ft_movement(data, key);
//	if (key == 65363 || key == 65361)
//		ft_mov_cam(data, key);
	return (0);
}

// draw pixel on the image
void	my_mlx_pixel_put(t_images *img, int x, int y, int color)
{
	char	*dst;
	
	if (x > WIN_WIDTH || y > WIN_HEIGHT)
		return ;
	dst = img->addr + (y * img->size_line + x * (img->pixel_bits / 8));
	*(unsigned int*)dst = color;
}

void	draw_background(t_data *data, t_images *img)
{
	int			x;
	int			y;

	x = 0;
	y = 0;
	while (y < (WIN_HEIGHT / 2))
	{
		while (x < WIN_WIDTH)
		{
			my_mlx_pixel_put(img, x, y, data->t.rgbc_hex);
			x++;
		}
		x = 0;
		y++;
	}
	while (y < WIN_HEIGHT)
	{
		while (x < WIN_WIDTH)
		{
			my_mlx_pixel_put(img, x, y, data->t.rgbf_hex);
			x++;
		}
		x = 0;
		y++;
	}
//	cast_ray(data); // do raycasting before reader map
	print_minimap(data, img);
}

//call the mlx
void	starting_mlx(t_data *data)
{
	t_images	img;

	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "Wonderfull Cub3D");
	img.img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.pixel_bits, &img.size_line, &img.endian);
	draw_background(data, &img);
	mlx_put_image_to_window(data->mlx, data->win, img.img, 0, 0);
	mlx_key_hook(data->win, deal_key, &img);
	mlx_hook(data->win, 17, 0, ft_close_win, 0);
	mlx_loop(data->mlx);
}
