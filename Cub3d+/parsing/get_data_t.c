/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data_t.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunegel <akunegel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 21:43:16 by akunegel          #+#    #+#             */
/*   Updated: 2024/08/09 15:10:12 by akunegel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// alloue memoire pour stocker paths des textures

void    tex_alloc(t_data *data, int t, int c)
{
    if (t == 1)
        data->no = malloc(sizeof(char) * c);
    else if (t == 2)
        data->so = malloc(sizeof(char) * c);
    else if (t == 3)
        data->we = malloc(sizeof(char) * c);
    else if (t == 4)
        data->ea = malloc(sizeof(char) * c);
}

// recuperes les paths

void get_content(t_data *data, int i, size_t t)
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
    tmp = malloc(sizeof(char) * c);
    tex_alloc(data, t, c - 2);
    j = 0;
    c = 0;
    while (data->tmp[i][j])
    {
        if (data->tmp[i][j] != ' ' && data->tmp[i][j] != '\n')
        {
            tmp[c] = data->tmp[i][j];
            c++;
        }
        j++;
    }
    tmp[c] = '\0';
    path_correct(tmp, data, t);
}

// trie les lignes pour chaque texture

void check_pre(char *pre, int i, t_data *data)
{
    if (pre[0] == 'N' && pre[1] == 'O')
        get_content(data, i, 1);
    else if (pre[0] == 'S' && pre[1] == 'O')
        get_content(data, i, 2);
    else if (pre[0] == 'W' && pre[1] == 'E')
        get_content(data, i, 3);
    else if (pre[0] == 'E' && pre[1] == 'A')
        get_content(data, i, 4);
    else if (pre[0] == 'C' && pre[1] >= '0' && pre[1] <= '9')
        get_content_bis(data, i, 0);
    else if (pre[0] == 'F' && pre[1] >= '0' && pre[1] <= '9')
        get_content_bis(data, i, 1);
    else
    {
        printf("Error: In file format not respected");
        exit (0);
    }
}

// identifie les lignes et recuperes les paths(via check_pre)

void grab_data(t_data *data, int i)
{
    int j;
    int k;
    char *pre;
    
    pre = malloc(sizeof(char) * 2 + 1);
    k = 0;
    j = 0;
    while (data->tmp[i][j] && k < 2)
    {
        if (data->tmp[i][j] != ' ')
        {
            pre[k] = data->tmp[i][j];
            k++;
        }
        j++;
    }
    pre[2] = '\0';
    check_pre(pre, i, data);
    free(pre);
}
