#include "../../Cub3d.h"

char *grab_path(int c, char *line, int i)
{
	char *path;

	path = malloc(sizeof(char) * c + 1);
	c = 0;
	while (line[i])
	{
		path[c] = line[i];
		i++;
		c++;
	}
	path[c] = '\0';
	return (path);
}

void affiliate_we_ea(t_data *data, char *pre, char *line, int c, int i)
{
	if (ft_strcmp(pre, "WE") == 0 && !data->paths.pw)
	{
		data->paths.pw = malloc(sizeof(char) * (c + 1));
		c = 0;
		while (line[i])
		{
			data->paths.pw[c] = line[i];
			c++;
			i++;
		}
		data->paths.pw[c] = '\0';
	}
	else if (!data->paths.pe)
	{
		data->paths.pe = malloc(sizeof(char) * (c + 1));
		c = 0;
		while (line[i])
		{
			data->paths.pe[c] = line[i];
			c++;
			i++;
		}
		data->paths.pe[c] = '\0';
	}
}

void affiliate_no_so(t_data *data, char *pre, char *line, int c, int i)
{
	if (ft_strcmp(pre, "NO") == 0 && !data->paths.pn)
	{
		data->paths.pn = malloc(sizeof(char) * (c + 1));
		c = 0;
		while (line[i])
		{
			data->paths.pn[c] = line[i];
			c++;
			i++;
		}
		data->paths.pn[c] = '\0';
	}
	else if (!data->paths.ps)
	{
		data->paths.ps = malloc(sizeof(char) * (c + 1));
		c = 0;
		while (line[i])
		{
			data->paths.ps[c] = line[i];
			c++;
			i++;
		}
		data->paths.ps[c] = '\0';
	}
}

void extract_xpm(t_data *data, char *pre, char *line, int i)
{
	int c;

	c = 0;
	while (line[i] == ' ' || line[i] == '\n' || line[i] == '\f' || line[i] == '\t' || line[i] == '\v' || line[i] == '\r')
		i++;
	while (line[i + c])
		c++;
	(void)data;
	(void)pre;
	if (ft_strcmp(pre, "NO") == 0 || ft_strcmp(pre, "SO") == 0)
		affiliate_no_so(data, pre, line, c, i);
	else if (ft_strcmp(pre, "WE") == 0 || ft_strcmp(pre, "EA") == 0)
		affiliate_we_ea(data, pre, line, c, i);
	else
		exit(ft_exit(data, "Error: Path unreadable"));
}