/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunegel <akunegel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 14:47:33 by akunegel          #+#    #+#             */
/*   Updated: 2024/08/15 14:27:14 by akunegel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int argc, char *argv[])
{
    t_data data;
    
    if (argc != 2) {
        printf("Error: Usage: ./program filename.cub");
        return 0;
    }
    if (!has_cub_extension(argv[1])) {
        printf("Error: File must have a .cub extension");
        return 0;
    }
    data.path = malloc(sizeof(char) * ft_strlen(argv[1]) + 1);
    data.path = argv[1];;
    parse_data(&data);
    get_data(&data);
    for (int i = 0; data.map.map[i]; i++)
        printf("%s\n", data.map.map[i]);
    printf("RGB C: %d.%d.%d\nRGB F: %d.%d.%d\nPath N: %s\nPath E: %s\nPath S: %s\nPath O: %s\n", data.t.rgbc[0], data.t.rgbc[1], data.t.rgbc[2], data.t.rgbf[0], data.t.rgbf[1], data.t.rgbf[2], data.no, data.ea, data.so, data.we);
    printf("RGB en hexadecimal: #%06X | #%06X\n", data.t.rgbc_hex, data.t.rgbf_hex);
    return (0);
}