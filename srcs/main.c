/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunegel <akunegel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 01:58:30 by akunegel          #+#    #+#             */
/*   Updated: 2024/09/13 01:58:30 by akunegel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3d.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (ft_exit(&data, "Error : Expected exactly 1 argument"));
	data.paths.pfile = argv[1];
	parsing(&data);
	printf("C_hex: %X\nF_hex: %X\nC: %d.%d.%d\nF: %d.%d.%d\n", data.t.rgbc_hex, data.t.rgbf_hex, data.t.rgbc[0], data.t.rgbc[1], data.t.rgbc[2], data.t.rgbf[0], data.t.rgbf[1], data.t.rgbf[2]);
	return (ft_exit(&data, "Game closed"));
}
