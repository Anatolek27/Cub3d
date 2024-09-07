#include "../cub3d.h"

unsigned int rgb_to_hex(int *rgb)
{
	unsigned int hex = 0;

	hex = (rgb[0] << 16) | (rgb[1] << 8) | rgb[2];
	return hex;
}