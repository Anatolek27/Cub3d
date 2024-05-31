#include "cub3d.h"

int		check_for_map(char *line)
{
	int	check;

	check = 0;
	while (*line)
	{
		if (!ft_strchr("012NSEW \t\f\n\r\v", *line))
			return (0);
		else if (*line == '1')
			check = 1;
		line++;
	}
	return (check);

}

void	get_data(char **lines, t_data *data)
{
	if (lines[0] == 0)
		return ;
	else if (!ft_strcmp(lines[0], "NO") && data->n_tex == NULL)
		get_texture(lines[1], &data->n_tex);
	else if (!ft_strcmp(lines[0], "SO") && data->s_tex == NULL)
		get_texture(lines[1], &data->s_tex);
	else if (!ft_strcmp(lines[0], "WE") && data->w_tex == NULL)
		get_texture(lines[1], &data->w_tex);
	else if (!ft_strcmp(lines[0], "EA") && data->e_tex == NULL)
		get_texture(lines[1], &data->e_tex);
	else if (!ft_strcmp(lines[0], "F") && data->c_color == NULL)
		get_color(lines[1], &data->f_color);
	else if (!ft_strcmp(lines[0], "C") && data->c_color == NULL)
		get_color(lines[1], &data->c_color);
	else if (lines[0][0] != '\n')
	{
		ft_error(data, "Format error\n");
	}//peut etre erreur, si oui verifier lignes suivantes grace au split
}

void	get_file(int fd, t_data *data)
{
	char	*line;
	char	**lines;

	ft_memset(&data->f_color, -1, sizeof(int) * 3);
	ft_memset(&data->c_color, -1, sizeof(int) * 3);
	line = NULL;
	while (get_next_line(fd, &line))
	{
		if (!check_for_map(line))
		{
			lines = ft_split(line, " \t\f\n\r\v");
			get_data(lines, data);
			while (*lines)
                free(*lines++);
			free(lines);
			free(line);
		}
		else
        {
			get_map_and_height(fd, line, data);
            get_width(data);
        }
	}
	free(line);
}

void    check_args(char *argv, t_data *data)
{
    int i;
    int fd;

    i = ft_strlen(data->pmap);
    if (argv[i] != 'b' || argv[i - 1] != 'u' || argv[i - 2] != 'c' || argv[i - 3] != '.')
        ft_error(data, "file needs to have .cub format\n");
    fd = open(argv, O_RDONLY);
    if (fd == -1)
        ft_error(data, "file not found\n");
    get_file(fd, data);
}