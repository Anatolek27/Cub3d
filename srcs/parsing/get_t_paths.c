/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_t_paths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunegel <akunegel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 01:48:32 by akunegel          #+#    #+#             */
/*   Updated: 2024/09/13 01:53:19 by akunegel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Cub3d.h"

char	*grab_path(int c, char *line, int i)
{
	char	*path;

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

void	affiliate_we_ea(t_data *data, char *pre, char *line, int *tmp)
{
	if (ft_strcmp(pre, "WE") == 0 && !data->paths.pw)
	{
		data->paths.pw = malloc(sizeof(char) * (tmp[1] + 1));
		tmp[1] = 0;
		while (line[tmp[0]])
		{
			data->paths.pw[tmp[1]] = line[tmp[0]];
			tmp[1]++;
			tmp[0]++;
		}
		data->paths.pw[tmp[1]] = '\0';
	}
	else if (!data->paths.pe)
	{
		data->paths.pe = malloc(sizeof(char) * (tmp[1] + 1));
		tmp[1] = 0;
		while (line[tmp[0]])
		{
			data->paths.pe[tmp[1]] = line[tmp[0]];
			tmp[1]++;
			tmp[0]++;
		}
		data->paths.pe[tmp[1]] = '\0';
	}
}

void	affiliate_no_so(t_data *data, char *pre, char *line, int *tmp)
{
	if (ft_strcmp(pre, "NO") == 0 && !data->paths.pn)
	{
		data->paths.pn = malloc(sizeof(char) * (tmp[1] + 1));
		tmp[1] = 0;
		while (line[tmp[0]])
		{
			data->paths.pn[tmp[1]] = line[tmp[0]];
			tmp[1]++;
			tmp[0]++;
		}
		data->paths.pn[tmp[1]] = '\0';
	}
	else if (!data->paths.ps)
	{
		data->paths.ps = malloc(sizeof(char) * (tmp[1] + 1));
		tmp[1] = 0;
		while (line[tmp[0]])
		{
			data->paths.ps[tmp[1]] = line[tmp[0]];
			tmp[1]++;
			tmp[0]++;
		}
		data->paths.ps[tmp[1]] = '\0';
	}
}

void	extract_xpm(t_data *data, char *pre, char *line, int i)
{
	int	c;
	int	tmp[2];

	c = 0;
	while (line[i] == ' ' || line[i] == '\n' || line[i] == '\f'
		|| line[i] == '\t' || line[i] == '\v' || line[i] == '\r')
		i++;
	while (line[i + c])
		c++;
	(void)data;
	(void)pre;
	tmp[0] = i;
	tmp[1] = c;
	if (ft_strcmp(pre, "NO") == 0 || ft_strcmp(pre, "SO") == 0)
		affiliate_no_so(data, pre, line, tmp);
	else if (ft_strcmp(pre, "WE") == 0 || ft_strcmp(pre, "EA") == 0)
		affiliate_we_ea(data, pre, line, tmp);
	else
		exit(ft_exit(data, "Error: Path unreadable"));
}
