#include "../Cub3d.h"

void check_rgb(t_data *data)
{
	data->t.rgbc = malloc(sizeof(int) * 3);
    if (!data->t.rgbc)
      exit(ft_exit(data, "Malloc error"));
	data->t.rgbf = malloc(sizeof(int) * 3);
	if (!data->t.rgbc)
		exit(ft_exit(data, "Malloc error"));
	data->t.rgbc = convert_rgb(data->paths.pc, data);
	data->t.rgbf = convert_rgb(data->paths.pf, data);
	check_c(data);
	check_f(data);
    printf("Crgb: %d.%d.%d", data->t.rgbc[0], data->t.rgbc[1], data->t.rgbc[2]);
	printf("Crgf: %d.%d.%d", data->t.rgbf[0], data->t.rgbf[1], data->t.rgbf[2]);
    check_valid_rgb(data);
	data->t.rgbc_hex = rgb_to_hex(data->t.rgbc);
	data->t.rgbf_hex = rgb_to_hex(data->t.rgbf);
}

void check_paths(t_data *data)
{
  	check_paths_exists(data);
	if (data->paths.pn[ft_strlen(data->paths.pn) - 1] != 'm' || data->paths.pn[ft_strlen(data->paths.pn) - 2] != 'p' || data->paths.pn[ft_strlen(data->paths.pn) - 3] != 'x' || data->paths.pn[ft_strlen(data->paths.pn) - 4] != '.')
		exit (ft_exit(data, ".xpm extension missing"));
	if (data->paths.ps[ft_strlen(data->paths.ps) - 1] != 'm' || data->paths.ps[ft_strlen(data->paths.ps) - 2] != 'p' || data->paths.ps[ft_strlen(data->paths.ps) - 3] != 'x' || data->paths.ps[ft_strlen(data->paths.ps) - 4] != '.')
		exit (ft_exit(data, ".xpm extension missing"));
	if (data->paths.pw[ft_strlen(data->paths.pw) - 1] != 'm' || data->paths.pw[ft_strlen(data->paths.pw) - 2] != 'p' || data->paths.pw[ft_strlen(data->paths.pw) - 3] != 'x' || data->paths.pw[ft_strlen(data->paths.pw) - 4] != '.')
		exit (ft_exit(data, ".xpm extension missing"));
	if (data->paths.pe[ft_strlen(data->paths.pe) - 1] != 'm' || data->paths.pe[ft_strlen(data->paths.pe) - 2] != 'p' || data->paths.pe[ft_strlen(data->paths.pe) - 3] != 'x' || data->paths.pe[ft_strlen(data->paths.pe) - 4] != '.')
		exit (ft_exit(data, ".xpm extension missing"));
    check_rgb(data);
}