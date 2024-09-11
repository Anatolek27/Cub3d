#include "../Cub3d.h"

int main(int argc, char **argv)
{
	t_data data;

	if (argc != 2)
		return (ft_exit(&data, "Error : Expected exactly 1 argument"));
	data.paths.pfile = argv[1];
	parsing(&data);
	for (int i = 0; data.map.map[i]; i++)
		printf("%s\n", data.map.map[i]);
	printf("Textures: %s\n%s\n%s\n%s\n", data.paths.pn, data.paths.ps, data.paths.pw, data.paths.pe);
	printf("C_HEX: %#X\nF_HEX: %#X", data.t.rgbc_hex, data.t.rgbf_hex);
	return (ft_exit(&data, "Game closed"));
}