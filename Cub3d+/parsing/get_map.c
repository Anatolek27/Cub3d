#include "../cub3d.h"

//recuperer largeur map une fois rectangle

int get_width(t_data *data)
{
    int i;
    int max;

    max = 0;
    i = 6;
    while(i < data->map.length + 6)
    {
        if (ft_strlen(data->file[i]) > max)
            max = ft_strlen(data->file[i]);
        i++;
    }
    return (max);
}

//recuperation map

void cpy_map(t_data *data)
{
    int i;
    int j;
    
    i = 0;
    while (i < data->map.length)
    {
        j = 0;
        while (j < data->map.width)
        {
            if (j < ft_strlen(data->tmp[i + 6]) && data->tmp[i + 6][j] != '\n')
                data->map.map[i][j] = data->tmp[i + 6][j];
            else
                data->map.map[i][j] = '2';
            j++;
        }
        data->map.map[i][j] = '\0';
        i++;
    }
}

// allouer memoire pour chaque ligne de la map

void    alloc_map(t_data *data)
{
    int i;

    i = 0;
    while (i < data->map.length)
    {
        data->map.map[i] = malloc(sizeof(char) * data->map.width + 1);
        i++;
    }
}

// verifie qu'il n y a pas de '2' dans la map avant de transformer les espaces en 2

int check_two(char **tmp)
{
    int i;
    int j;

    i = 6;
    while (tmp[i])
    {
        j = 0;
        while (tmp[i][j])
        {
            if (tmp[i][j] == '2')
                return (0);
            j++;
        }
        printf("CHECK TWO  : %s", tmp[i]);
        i++;
    }
    return (1);
}

// fonction qui gere recuperation de la map

void    get_map(t_data *data)
{
    data->map.length = get_count(data->file) - 6;
    /*if (check_two(data->tmp) != 1)
    {
        printf("Error: In file format not respected.");
        exit (0);
    }
    if (get_count(data->tmp) < 9)
    {
        printf("Error: In file format not respected.");
        exit (0);
    }*/
    data->map.width = get_width(data) - 1;
    data->map.map = malloc(data->map.length * sizeof(char *) + 1);
    if (!data->map.map)
    {
        printf("Error: Map empty or malloc error.");
        exit (0);
    }
    alloc_map(data);
    cpy_map(data);
    check_map(data, data->map.map);\
}


// Fichier récupères tout les paths, récupère la map, erreur sur les paths(forme + existance) et map rectangulaire pas checké.