#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include "gnl/get_next_line.h"

typedef struct s_player {
  int x;
  int y;
  char dir;
}              t_player;

typedef struct s_map {
  char **map;
  int length;
  int width;
}              t_map;

typedef struct s_paths {
  char *pfile;
  char *ps;
  char *pw;
  char *pn;
  char *pe;
  char *pc;
  char *pf;
}              t_paths;

typedef struct s_textures {
  int *rgbc;
  int *rgbf;
  int	rgbc_hex;
  int	rgbf_hex;
}              t_textures;

typedef struct s_data {
  t_player p;
  t_map map;
  t_paths paths;
  t_textures t;
  void  *mlx;
  void  *win;
  int fd;
  char **file;
  char **tmp;
}				t_data;

int ft_strlen(char *str);
int ft_exit(t_data *data, char *err);
void get_file(t_data *data);
void parsing(t_data *data);
int get_line_nb(t_data *data);
void	*ft_calloc(size_t count, size_t size);
int line_is_empty(char *line);
void get_clean_file(t_data *data);
void get_paths(t_data *data);
void path_correct_bis(char *tmp, t_data *data, size_t t);
void get_content(t_data *data, int i, size_t t);
void get_content_bis(t_data *data, int i, size_t b);
void    tex_alloc(t_data *data, int t, int c);
void path_correct(char *tmp, t_data *data, size_t t);
void check_paths(t_data *data);
char	**ft_split(char const *s, char c);
int	ft_atoi(const char *str);
int *convert_rgb(char *d, t_data *data);
unsigned int rgb_to_hex(int *rgb);
void    check_f(t_data *data);
void    check_c(t_data *data);
int check_valid_rgb(t_data *data);
void check_paths_exists(t_data *data);

#endif