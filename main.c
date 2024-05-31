#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data data;

	if (argc == 2)
	{
		//check_args(argv[1], &data);
		ft_parse(&data);
		//ft_init(&data);
	}
	else
		printf("One argument expected\n");
	return (0);
}
