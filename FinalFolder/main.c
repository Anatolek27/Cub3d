#include "Cub3d.h"

int main(int argc, char **argv)
{
	t_data data;

	if (argc != 2)
		return (ft_exit(&data, "Error : Expected exactly 1 argument"));
	data.paths.pfile = (char *)malloc(sizeof(char) * (ft_strlen(argv[1] + 1)));
	if (!data.paths.pfile)
		return (ft_exit(&data, "Error: Malloc error"));
	data.paths.pfile = argv[1];
	data.paths.pfile[ft_strlen(argv[1])] = '\0'; // verif sur linux si utilitée
	return (ft_exit(&data, NULL));
}