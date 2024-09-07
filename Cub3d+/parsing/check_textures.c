/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunegel <akunegel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 02:27:57 by akunegel          #+#    #+#             */
/*   Updated: 2024/08/13 19:43:39 by akunegel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// verif contient que des nombres

int check_number(char *s)
{
    int i;
    
    i = 0;
    while (s[i])
    {
        if ((s[i] < '0' || s[i] > '9') && s[i] != ',' && s[i] != '\n')
            return (0);
        i++;
    }
    return (1);
}

// verif rgb entre 0 et 255

int check_valid_rgb(t_data *data)
{
	int	i;

	i = 0;
	while (i != 3)
    {
		if (data->t.rgbc[i] < 0 || data->t.rgbc[i] > 255 || data->t.rgbf[i] < 0 || data->t.rgbf[i] > 255)
            return (0);
		i++;
	}
    return (1);
}

// verif 3 nombres dans rgb sol

void    check_f(t_data *data)
{
    int i;
    int c;

    c = 0;
    i = 0;
    while (data->f[i])
    {
        if (data->f[i] == ',')
            c++;
        i++;
    }
    if (c != 2)
    {
        printf("Error: RGB format wrong.");
        exit (0);
    }
    if (check_number(data->f) == 0)
    {
        printf("Error: RGB format wrong.");
        exit(0); 
    }
}

// convertit data->c ou f en int *

int *convert_rgb(char *d)
{
    char **tmp;
    int *rgb;
    int i;
    
    i = 0;
    tmp = malloc(sizeof(char *) * 3);
    tmp = ft_split(d, ',');
    while (tmp[i])
        i++;
    if (i != 3)
    {
        printf("Error: In file format not respected.");
        exit (0);
    }
    rgb = malloc(sizeof(int) * 3);
    i = 0;
    while (i != 3)
    {
        rgb[i] = ft_atoi(tmp[i]);
        i++;
    }
    return (rgb);
}

// verif 3 nombres dans rgb toit

void    check_c(t_data *data)
{
    int i;
    int c;

    c = 0;
    i = 0;
    while (data->c[i])
    {
        if (data->c[i] == ',')
            c++;
        i++;
    }
    if (c != 2)
    {
        printf("Error: RGB format wrong.");
        exit (0);
    }
    if (check_number(data->c) == 0)
    {
        printf("Error: RGB format wrong.");
        exit(0);
    }
}

int check_paths(t_data *data)
{
    if (!data->no || !data->so || !data->we || !data->ea)
        return (0);
    if (data->no[0] != '.' || data->no[1] != '/')
        return (0);
    if (data->so[0] != '.' || data->so[1] != '/')
        return (0);
    if (data->we[0] != '.' || data->we[1] != '/')
        return (0);
    if (data->ea[0] != '.' || data->ea[1] != '/')
        return (0);
    if (data->no[ft_strlen(data->no) - 1] != 'm' || data->no[ft_strlen(data->no) - 2] != 'p' || data->no[ft_strlen(data->no) - 3] != 'x' || data->no[ft_strlen(data->no) - 4] != '.')
        return (0);
    if (data->so[ft_strlen(data->so) - 1] != 'm' || data->so[ft_strlen(data->so) - 2] != 'p' || data->so[ft_strlen(data->so) - 3] != 'x' || data->so[ft_strlen(data->so) - 4] != '.')
        return (0);
    if (data->we[ft_strlen(data->we) - 1] != 'm' || data->we[ft_strlen(data->we) - 2] != 'p' || data->we[ft_strlen(data->we) - 3] != 'x' || data->we[ft_strlen(data->we) - 4] != '.')
        return (0);
    if (data->ea[ft_strlen(data->ea) - 1] != 'm' || data->ea[ft_strlen(data->ea) - 2] != 'p' || data->ea[ft_strlen(data->ea) - 3] != 'x' || data->ea[ft_strlen(data->ea) - 4] != '.')
        return (0);
    return (1);
}

// gere verifs textures

void check_tex(t_data *data)
{
    data->t.rgbc = malloc(sizeof(int) * 3);
    data->t.rgbf = malloc(sizeof(int) * 3);
    data->t.rgbc = convert_rgb(data->c);
    data->t.rgbf = convert_rgb(data->f);
    data->t.rgbc_hex = rgb_to_hex(data->t.rgbc);
    data->t.rgbf_hex = rgb_to_hex(data->t.rgbf);
    check_c(data);
    check_f(data);
    if (check_valid_rgb(data) == 0)
    {
        printf("Error: RGB format not respected.");
        exit(0);
    }
    if (check_paths(data) == 0)
    {
        printf("Error: Textures path format not respected.");
        exit(0);
    }
}