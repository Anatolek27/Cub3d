/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunegel <akunegel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 14:57:39 by akunegel          #+#    #+#             */
/*   Updated: 2024/08/28 13:43:47 by akunegel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// recupere contenu fichier

static void get_file(int x, int y, int i, t_data *data)
{
    char *line;
    
    line = get_next_line(data->fd);
    while (line != NULL)
    {
        data->file[x] = ft_calloc(ft_strlen(line) + 1, sizeof(char));
        if (!data->file[x])
        {
            printf("Error: Malloc Error.");
            exit (0);
        }
        while (line[i] != '\0')
        {
            data->file[x][y++] = line[i++];
        }
        data->file[x++][y] = '\0';
        free(line);
        y = 0;
        i = 0;
        line = get_next_line(data->fd);
    }
    data->file[x] = NULL;
}

// recupere nombre de lignes dans le fichier d'origine

static int get_number_line(t_data *data)
{
    int fd;
    char *line;
    int c;
    
    c = 0;
    fd = open(data->path, O_RDONLY);
    if (fd < 0)
    {
        printf("Error : Error opening file.\n");
        exit (0);
    }
    line = get_next_line(fd);
    while (line)
    {
        c++;
        free(line);
        line = get_next_line(fd);
    }
    close(fd);
    return (c);
}

// verif .cub

int has_cub_extension(char *file)
{
    int i;

    i = ft_strlen(file);
    if (file[i - 1] != 'b' || file[i - 2] != 'u' || file[i - 3] != 'c' || file[i - 4] != '.')
        return (0);
    return (1);
}

// fonction qui gere le parsing

void parse_data(t_data *data) 
{
    int x;
    int i;
    int y;

    i = 0;
    x = 0;
    y = 0;
    data->map.length = get_number_line(data);
    data->file = ft_calloc(data->map.length + 1, sizeof(char *));
    if (!data->file)
    {
        printf ("Error: File empty or couldnt be read");
        exit (0);
    }
    data->fd = open(data->path, O_RDONLY);
    if (data->fd < 0)
    {
        printf("Error: Error opening file");
        exit (0);
    }
    get_file(x, y, i, data);
    close(data->fd);
}