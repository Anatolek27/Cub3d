/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunegel <akunegel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 16:24:48 by akunegel          #+#    #+#             */
/*   Updated: 2024/08/09 15:38:16 by akunegel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// retire identifiant des rgb (C ou F)

void path_correct_bis(char *tmp, t_data *data, size_t t)
{
    int i;
    int j;

    j = 0;
    i = 1;
    if (t == 0)
    {
        data->c = malloc(sizeof(char) * ft_strlen(tmp) - 1);
        while (tmp[i])
        {
            data->c[j] = tmp[i];
            i++;
            j++;
        }
        data->c[j] = '\0';
    }
    else if (t == 1)
    {
        data->f = malloc(sizeof(char) * ft_strlen(tmp) - 1);
        while (tmp[i])
        {
            data->f[j] = tmp[i];
            i++;
            j++;
        }
        data->f[j] = '\0';
    }
}

// suite

void path_correct_2(char *tmp, t_data *data, size_t t)
{
    int i;
    int j;

    j = 0;
    i = 2;
    if (t == 3)
    {
        while (tmp[i])
        {
            data->we[j] = tmp[i];
            i++;
            j++;
        }
        data->we[j] = '\0';
    }
    else if (t == 4)
    {
        while (tmp[i])
        {
            data->ea[j] = tmp[i];
            i++;
            j++;
        }
        data->ea[j] = '\0';
    }
}

// retire identifiant des textures (NO, SO...)

void path_correct(char *tmp, t_data *data, size_t t)
{
    int i;
    int j;

    j = 0;
    i = 2;
    if (t == 1)
    {
        while (tmp[i])
        {
            data->no[j] = tmp[i];
            i++;
            j++;
        }
        data->no[j] = '\0';
    }
    else if (t == 2)
    {
        while (tmp[i])
        {
            data->so[j] = tmp[i];
            i++;
            j++;
        }
        data->so[j] = '\0';
    }
    else
        path_correct_2(tmp, data, t);
}

// recupere rgb

void get_content_bis(t_data *data, int i, size_t b)
{
    int c;
    int j;
    char *tmp;

    c = 0;
    j = 0;
    while (data->tmp[i][j])
    {
        if (data->tmp[i][j] != ' ')
            c++;
        j++;
    }
    tmp = malloc(sizeof(char) * c + 1);
    j = 0;
    c = 0;
    while (data->tmp[i][j])
    {
        if (data->tmp[i][j] != ' ')
        {
            tmp[c] = data->tmp[i][j];
            c++;
        }
        j++;
    }
    tmp[c] = '\0';
    path_correct_bis(tmp, data, b);
}