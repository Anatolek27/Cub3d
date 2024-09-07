#include "../Cub3d.h"

void check_paths_exists(t_data *data)
{
  if (!data->paths.pc || !data->paths.pf || !data->paths.pn || !data->paths.ps || !data->paths.pe || !data->paths.pw)
    exit( ft_exit(data, "Missing paths"));
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
		exit (ft_exit(data, "In file format not respected"));
	}
}

// identifie les lignes et recuperes les paths(via check_pre)

void get_texs_paths(t_data *data, int i)
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
void get_paths(t_data *data)
{
  	int i;

  	i = 0;
  	while (i < 6)
  	{
		get_texs_paths(data, i);
		i++;
  	}
	check_paths_exists(data);
    printf("NO: %s\nSO: %s\nWE: %s\nEA: %s\nC: %s\nF: %s\n", data->paths.pn, data->paths.ps, data->paths.pw, data->paths.pe, data->paths.pc, data->paths.pf);
}