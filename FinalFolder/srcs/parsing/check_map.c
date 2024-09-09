#include "../../Cub3d.h"

/*void	verify_map_leaks(char **map)
{
	int i;
	int j;

	i = 0;
	while (map[i][j])
	{

	}
}*/

void	verify_if_player_stuck(t_data *data)
{
	if (data->map.map[data->p.x - 1][data->p.y] != '0' && data->map.map[data->p.x + 1][data->p.y] != '0' &&
		data->map.map[data->p.x][data->p.y - 1] != '0' && data->map.map[data->p.x][data->p.y + 1] != '0' )
		exit(ft_exit(data, "Error: Player surrounded by walls"));
}

void	check_map_playable(t_data *data, int x, int y)
{
	if (get_map_lines(data->tmp, data) < 3)
		exit(ft_exit(data, "Error: Map unplayable"));
	if (!data->p.dir)
		exit (ft_exit(data, "Error: Player missing"));
	if (!data->map.map[x - 1][y] || !data->map.map[x + 1][y] || !data->map.map[x][y - 1] || !data->map.map[x][y + 1])
		exit(ft_exit(data, "Error: Player can't be on border"));
	data->map.width = get_longest_line(data->tmp);
	data->map.length = get_map_lines(data->tmp, data);
	//verify_map_leaks(data->map.map);
	//verify_if_player_stuck(data);
}

void check_map_chars(t_data *data)
{
	int i;
	int j;

	i = 0;
	while (data->map.map[i])
	{
		j = 0;
		while (data->map.map[i][j])
		{
			if (data->map.map[i][j] == '2' || data->map.map[i][j] == '1' || data->map.map[i][j] == '0')
				j++;
			else if (data->map.map[i][j] == 'N' || data->map.map[i][j] == 'S' || data->map.map[i][j] == 'W' || data->map.map[i][j] == 'E')
			{
				data->p.dir = data->map.map[i][j++];
				data->p.x = i;
				data->p.y = j;
			}
			else
				exit(ft_exit(data, "Error: Map contains unrecognizable character or has empty line"));
		}
		i++;
	}
	if (!data->p.dir)
		exit (ft_exit(data, "Error: Player missing"));
}