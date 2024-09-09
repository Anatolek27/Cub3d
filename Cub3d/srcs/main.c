#include "../Cub3d.h"

int main(int argc, char **argv)
{
	t_data data;

	if (argc != 2)
		return (ft_exit(&data, "Error : Expected exactly 1 argument"));
	data.paths.pfile = argv[1];
	parsing(&data);
	printf("x: %d\ny: %d", data.p.x, data.p.y);
	return (ft_exit(&data, "Game closed"));
}