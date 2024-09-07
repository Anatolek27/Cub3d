#include "../Cub3d.h"

void path_correct_bis(char *tmp, t_data *data, size_t t)
{
    int i;
    int j;

    j = 0;
    i = 1;
    if (t == 0)
    {
        data->paths.pc = malloc(sizeof(char) * ft_strlen(tmp));
        while (tmp[i])
        {
            data->paths.pc[j] = tmp[i];
            i++;
            j++;
        }
        data->paths.pc[j] = '\0';
    }
    else if (t == 1)
    {
        data->paths.pf = malloc(sizeof(char) * ft_strlen(tmp));
        while (tmp[i])
        {
            data->paths.pf[j] = tmp[i];
            i++;
            j++;
        }
        data->paths.pf[j] = '\0';
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
            data->paths.pw[j] = tmp[i];
            i++;
            j++;
        }
        data->paths.pw[j] = '\0';
    }
    else if (t == 4)
    {
        while (tmp[i])
        {
            data->paths.pe[j] = tmp[i];
            i++;
            j++;
        }
        data->paths.pe[j] = '\0';
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
            data->paths.pn[j] = tmp[i];
            i++;
            j++;
        }
        data->paths.pn[j] = '\0';
    }
    else if (t == 2)
    {
        while (tmp[i])
        {
            data->paths.ps[j] = tmp[i];
            i++;
            j++;
        }
        data->paths.ps[j] = '\0';
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
    free(tmp);
}

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
    tmp = malloc(sizeof(char) * c + 1);
    if (tmp == NULL)
        exit( ft_exit(data, "Malloc error"));
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
    free(tmp);
}