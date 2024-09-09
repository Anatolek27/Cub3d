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
int	ft_strcmp(char *s1, char *s2);
char *ft_strcpy(char *dest, char *src);
void parsing(t_data *data);
void get_file(t_data *data);
void *ft_calloc(size_t count, size_t size);
int get_line_nb(t_data *data);
void get_clean_file(t_data *data);
int line_is_empty(char *line);
void get_paths(t_data *data);
void check_t_paths(t_data *data);
void extract_xpm(t_data *data, char *pre, char *line, int i);
int	ft_atoi(const char *str);
int *convert_rgb(char *d, t_data *data);
char	**ft_split(char const *s, char c);
void    check_c(t_data *data);
void    check_f(t_data *data);
unsigned int rgb_to_hex(int *rgb);
int check_valid_rgb(t_data *data);
void check_rgb(t_data *data);
void get_map(t_data *data);
int get_longest_line(char **file);
int get_map_lines(char **file, t_data *data);
void check_map_chars(t_data *data);
void	check_map_playable(t_data *data, int x, int y);

#endif