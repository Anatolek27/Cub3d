#include "cub3d.h"

void	check_dist_step(t_data *data)
{
	if (data->dda->distx < data->dda->disty)
	{
		data->dda->distx += data->dda->ddistx;
		data->dda->mapx += data->dda->stepx;
		data->dda->side = 0;
	}
	else
	{
		data->dda->disty += data->dda->ddisty;
		data->dda->mapy += data->dda->stepy;
		data->dda->side = 1;
	}
	if (data->map[data->dda->mapx][data->dda->mapy] == '1')
			data->dda->hit = 1;
	    if (!data->dda->side)
	    {
	    	if (data->dda->raydirx < 0)
	    		data->dda->side = 1;
	    	else if (data->dda->raydirx > 0)
    			data->dda->side = 2;
    	}
    	else if (data->dda->side == 1)
    	{
    		if (data->dda->raydiry < 0)
    			data->dda->side = 3;
    		else if (data->dda->raydiry > 0)
    			data->dda->side = 4;
    	}
}

void	check_dist(t_data *data)
{
	data->dda->hit = 0;
	data->dda->side = 0;
	while (data->dda->hit == 0)
		check_dist_step(data);
	if (data->dda->side == 1 || data->dda->side == 2 ||data->dda->side == 13 || data->dda->side == 14)
		data->dda->dist = (data->dda->mapx - data->player.pos.x + (1 - data->dda->stepx) / 2) / data->dda->raydirx;
	else if (data->dda->side == 3 || data->dda->side == 4 || data->dda->side == 15 || data->dda->side == 16)
		data->dda->dist = (data->dda->mapy - data->player.pos.y + (1 - data->dda->stepy) / 2) / data->dda->raydiry;
}


void	check_sides(t_data *data)
{
	if (data->dda->raydirx < 0)
	{
		data->dda->stepx = -1;
		data->dda->distx = (data->player.pos.x - \
			data->dda->mapx) * data->dda->ddistx;
	}
	else
	{
		data->dda->stepx = 1;
		data->dda->distx = (data->dda->mapx + 1.0 - \
			data->player.pos.x) * data->dda->ddistx;
	}
	if (data->dda->raydiry < 0)
	{
		data->dda->stepy = -1;
		data->dda->disty = (data->player.pos.y - data->dda->mapy) * data->dda->ddisty;
	}
	else
	{
		data->dda->stepy = 1;
		data->dda->disty = (data->dda->mapy + 1.0 - \
			data->player.pos.y) * data->dda->ddisty;
	}
}

void    dda_algorithm(t_data *data)
{
    data->dda->cam = 2 * data->i/ (double)WIDTH - 1;
    data->dda->raydirx = data->player.dirv.x + data->player.x * data->dda->cam;
    data->dda->raydiry = data->player.dirv.y + data->player.y * data->dda->cam;
    data->dda->mapx = data->player.pos.x;
    data->dda->mapy = data->player.pos.y;
    data->dda->ddistx = fabs(1 / data->dda->raydirx);
    data->dda->ddisty = fabs(1 / data->dda->raydiry);
    check_sides(data);
}

void    raycasting(t_data *data)
{
    int i;

    i = 0;
    data->i = 0.0;
    while (data->i < WIDTH)
    {
        dda_algorithm(data);
        i =0;
        data->dda->lineheight = (int)(WIDTH / data->dda->dist);
	    data->dda->lineheight = (int)(HEIGHT / data->dda->dist);
	    data->dda->drawstart = -data->dda->lineheight / 2 + HEIGHT / 2;
	    if (data->dda->drawstart < 0)
	    	data->dda->drawstart = 0;
    	data->dda->drawend = data->dda->lineheight / 2 + HEIGHT / 2;
    	if (data->dda->drawend > HEIGHT)
    		data->dda->drawend = HEIGHT - 1;
    	/*y += draw_line(data, data->map->c, 0, data->dda->drawstart);
    	y += draw_tex(data, y);
	    draw_line(data, data->map->f, y, HEIGHT);*/
        data->i++;
    }
}