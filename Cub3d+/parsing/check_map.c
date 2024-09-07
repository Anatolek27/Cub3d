/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunegel <akunegel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 01:54:10 by akunegel          #+#    #+#             */
/*   Updated: 2024/08/09 17:12:49 by akunegel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    check_playable(t_data *data)
{
    int    i;
    int    j;

    i = 0;
    while (data->map.map[i])
    {
        j = 0;
        while (data->map.map[i][j])
        {
            if ((data->map.map[i][j] == '0') && ((data->map.map[i + 1][j] != '0'
            && data->map.map[i + 1][j] != '1') || (data->map.map[i][j + 1]  != '0'
            && data->map.map[i][j + 1] != '1') || (data->map.map[i - 1][j] != '0'
            && data->map.map[i - 1][j] != '1') || (data->map.map[i][j - 1] != '0' && data->map.map[i][j - 1] != '1')))
            {
                printf("Error: Map leaks.");
                exit (0);
            }
            j++;
        }
        i++;
    }
}

void check_borders(t_data *data, char **s)
{
    int i;

    i = 0;
    while (s[i])
    {
        if ((s[i][0] != '1' && s[i][0] != '2') || (s[i][data->map.width - 1] != '2' && s[i][data->map.width - 1] != '1'))
        {
            printf("Error: Map not closed.");
            exit(0);
        }
        i++;
    }
    i = 0;
    while (s[0][i])
    {
        if ((s[0][i] != '1' && s[0][i] != '2') || (s[data->map.length - 1][i] != '1' && s[data->map.length - 1][i] != '2'))
        {      
            printf("Error: Map not closed.");
            exit(0);
        }
        i++;
    }
} 

// verifie map que 0/1/2/pos

void check_map_2(t_data *data, char **s)
{
    int i;
    int j;
    
    i = 0;
    while (s[i])
    {
        j = 0;
        while (s[i][j])
        {
            if (s[i][j] != '0' && s[i][j] != '1' && s[i][j] != '2' && s[i][j] != 'N' && s[i][j] != 'S' && s[i][j] != 'E' && s[i][j] != 'W')
            {
                printf("Error: Not recognized caracter in map.");
                exit (0);
            }
            j++;
        }
        i++;
    }
    check_borders(data, s);
    check_playable(data);
}

// verifie joueur et recuperes pos + dir

void check_map(t_data *data, char **s)
{
    int i;
    int j;
    int count;

    i = 0;
    count = 0;
    while (s[i + 1])
    {
        j = 0;
        while (s[i][j])
        {
            if (s[i][j] == 'N' || s[i][j] == 'S' || s[i][j] == 'W' || s[i][j] == 'E')
            {
                data->p.dir = s[i][j];
                data->p.x = i;
                data->p.y = j;
                data->map.map[i][j] = '0';
                count++;
            }
            j++;
        }
        i++;
    }
    if (count != 1)
    {
        printf("Error: Player missing or multiple spawn.");
        exit (0);
    }
    check_map_2(data, s);
}