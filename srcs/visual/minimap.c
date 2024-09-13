/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunegel <akunegel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 12:18:32 by hguillau          #+#    #+#             */
/*   Updated: 2024/09/13 12:25:04 by akunegel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Cub3d.h"

// Blanc	#FFFFFF
// Noir		#000000
// make 10 px for smaller minimap


// need to midify manually with map growth
void	draw_player(int	x, int y, int color, t_images *img)
{
	int	i;
	int	j;
	int	k;

	i = x + 2;
	j = y + 2;
	k = x;
	while (y - 2 < j)
	{
		while (x - 2 < i)
		{
			my_mlx_pixel_put(img, x - 2, y - 2, color);
			x++;
		}
		x = k;
		y++;
	}
}

void	draw_map(int x, int y, int color, t_images *img)
{
	int	i;
	int	j;
	int k;

	i = x + 64;
	j = y + 64;
	k = x;
	while (y < j)
	{
		while (x < i)
		{
			my_mlx_pixel_put(img, x, y, color);
			x++;
		}
		x = k;
		y++;
	}
}

void	print_minimap(t_data *data, t_images *img)
{
	int	x;
	int	y;
	int	pos;
	int	i;

	x = 20;
	y = 20;
	pos = 0;
	while (data->map.map[pos])
	{
		i = 0;
		while (data->map.map[pos][i])
		{
			if (data->map.map[pos][i] == '1')
				draw_map(x, y, 0x000000, img);
			else if (data->map.map[pos][i] == '0')
				draw_map(x, y, 0xFFFFFF, img);
			x += 64;
			i++;
		}
		x = 20;
		y += 64;
		pos++;
	} // le -20 est pour la marge de 20 pixel a gauche et au dessus de la minimap
	draw_player((((data->p.y) * 64) + 20), (((data->p.x) * 64) + 20), 0x0000FF, img);
}
