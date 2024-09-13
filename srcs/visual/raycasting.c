/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunegel <akunegel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 19:46:26 by akunegel          #+#    #+#             */
/*   Updated: 2024/09/13 12:48:54 by akunegel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Cub3d.h"

void init_player(t_player *p)
{
    if (p->dir == 'N')
    {
        p->dir_x = -1;
        p->dir_y = 0;
        p->plane_x = 0;
        p->plane_y = 0.66;
    }
    else if (p->dir == 'S')
    {
        p->dir_x = 1;
        p->dir_y = 0;
        p->plane_x = 0;
        p->plane_y = -0.66;
    }
    else if (p->dir == 'E')
    {
        p->dir_x = 0;
        p->dir_y = 1;
        p->plane_x = 0.66;
        p->plane_y = 0;
    }
    else if (p->dir == 'W')
    {
        p->dir_x = 0;
        p->dir_y = -1;
        p->plane_x = -0.66;
        p->plane_y = 0;
    }
}
/*
void	init_ray(t_ray *ray, t_data *data, int x, int screen_width)
{
	ray->camera_x = 2 * x / (double)screen_width - 1;
	ray->ray_dir_x = data->p.dir_x + data->p.plane_x * ray->camera_x;
	ray->ray_dir_y = data->p.dir_y + data->p.plane_y * ray->camera_x;
	ray->map_x = (int)data->p.x;
	ray->map_y = (int)data->p.y;
	ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
	ray->hit = 0;
}


void	calculate_step(t_ray *ray, t_data *data)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (data->p.x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - data->p.x) * ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (data->p.y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - data->p.y) * ray->delta_dist_y;
	}
}


void	perform_dda(t_ray *ray, t_data *data)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (data->map.map[ray->map_x][ray->map_y] == '1')
			ray->hit = 1;
	}
}

void	calculate_wall_distance(t_ray *ray, t_data *data)
{
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->map_x - data->p.x +
			(1 - ray->step_x) / 2) / ray->ray_dir_x;
	else
		ray->perp_wall_dist = (ray->map_y - data->p.y +
			(1 - ray->step_y) / 2) / ray->ray_dir_y;
}

void	calculate_line_height(t_ray *ray, int screen_height)
{
	ray->line_height = (int)(screen_height / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + screen_height / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + screen_height / 2;
	if (ray->draw_end >= screen_height)
		ray->draw_end = screen_height - 1;
}

int	select_texture(t_ray *ray)
{
	if (ray->side == 1 && ray->ray_dir_y > 0)
		return (1);
	else if (ray->side == 0 && ray->ray_dir_x < 0)
		return (2);
	else if (ray->side == 1 && ray->ray_dir_y < 0)
		return (3);
	return (0);
}


void	draw_column(t_data *data, t_ray *ray, int x, int screen_width ,int screen_height)
{
	t_images	*texture;
	int			tex_x, tex_y, y, color;
	double		wall_x, tex_pos, step;

	texture = &data->images[select_texture(ray)];
	wall_x = (ray->side == 0) ? data->p.y + ray->perp_wall_dist * ray->ray_dir_y :
			data->p.x + ray->perp_wall_dist * ray->ray_dir_x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * (double)texture->width);
	if ((ray->side == 0 && ray->ray_dir_x > 0) || (ray->side == 1 && ray->ray_dir_y < 0))
		tex_x = texture->width - tex_x - 1;
	step = 1.0 * texture->height / ray->line_height;
	tex_pos = (ray->draw_start - screen_height / 2 + ray->line_height / 2) * step;
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		tex_y = (int)tex_pos & (texture->height - 1);
		tex_pos += step;
		color = texture->addr[tex_y * texture->width + tex_x];
		data->img.addr[y * screen_width + x] = color;
		y++;
	}
}

void	raycast(t_data *data, int screen_width, int screen_height)
{
	t_ray	ray;
	int		x;

	x = 0;
	while (x < screen_width)
	{
		init_ray(&ray, data, x, screen_width);
		calculate_step(&ray, data);
		perform_dda(&ray, data);
		calculate_wall_distance(&ray, data);
		calculate_line_height(&ray, screen_height);
		draw_column(data, &ray, x, screen_width ,screen_height);
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}*/
