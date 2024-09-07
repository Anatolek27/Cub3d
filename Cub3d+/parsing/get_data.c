/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunegel <akunegel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 15:18:10 by akunegel          #+#    #+#             */
/*   Updated: 2024/08/28 14:00:57 by akunegel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// compte lignes apres retrait \n

int get_count(char **file)
{
    int i;
    int c;
    int j;

    j = 0;
    c = 0;
    i = 0;
    while (file[i])
    {
      j = 0;
      if (file[i][0] == '\n' || file[i][0] == '\v' || file[i][0] == '\t' || file[i][0] == ' ')
          while (file[i][j] == '\v' || file[i][j] == '\t' || file[i][j] == '\n' || file[i][j] == ' ')
          {
            if (file[i][j] == '\n')
              c--;
            j++;
          }
      i++;
      c++;
    }
    return (c);
}

// enleve lignes vides

void remove_empty_lines(t_data *data)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (data->file[i])
    {
        if (data->file[i][0] != '\n')
        {
            data->tmp[j] = data->file[i];
            j++;
        }
        i++;
    }
}

// suite

int check_format2(t_data *data)
{
    int i;

    i = 0;
    while (data->tmp[i] && i < 6)
    {
        grab_data(data, i);
        i++;
    }
    if (!data->no || !data->so || !data->we || !data->ea || !data->f || !data->c)
    {
        printf("Error: In file format not respected.");
        exit (0);
    }
    return (1);
}

// gere le format des paths dans le .cub

int check_format(t_data *data)
{
    data->tmp = malloc((sizeof(char *) + 1) * get_count(data->file));
    if (!data->tmp)
    {
        printf("Error: Malloc error.");
        exit (0);
    }
    remove_empty_lines(data);
    if (check_format2(data) != 1)
    {
        printf("Error: In file format not respected.");
        exit(0);
    }
    return (1);
}

// gere la recuperation des infos du fichiers

void get_data(t_data *data)
{
    data->p.x = -1;
    data->p.y = -1;
    if (check_format(data) == 0)
    {
        printf("Error: In file format not respected.");
        exit (0);
    }
    get_map(data);
    check_tex(data);
    free(data->file);
}