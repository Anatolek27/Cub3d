#ifndef CUB3D_H
#define CUB3D_H

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <fcntl.h>
#include "includes/gnl/get_next_line.h"

typedef struct s_player
{
	int x;
	int y;
	char dir;
} t_player;

typedef struct s_map
{
	char **map;
	int length;
	int width;
} t_map;

typedef struct s_paths
{
	char *pfile;
	char *ps;
	char *pw;
	char *pn;
	char *pe;
	char *pc;
	char *pf;
} t_paths;

typedef struct s_textures
{
	int *rgbc;
	int *rgbf;
	int rgbc_hex;
	int rgbf_hex;
} t_textures;

typedef struct s_data
{
	t_player p;
	t_map map;
	t_paths paths;
	t_textures t;
	void *mlx;
	void *win;
	int fd;
	char **file;
	char **tmp;
} t_data;

int ft_exit(t_data *data, char *err);
int ft_strlen(char *str);

#endif