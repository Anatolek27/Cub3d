/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunegel <akunegel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 02:02:24 by akunegel          #+#    #+#             */
/*   Updated: 2024/09/16 18:54:04 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include "includes/gnl/get_next_line.h"
# include "mlx.h"

# define FOV 60						// FOV
# define T_SIZE 10					// tile size
# define P_HEIGHT 5					// Camera position
# define WIN_WIDTH 1024				// windows width
# define WIN_HEIGHT 512				// windows height
# define SPEED 4					// player speed
# define RO_SPEED 0.03				// rotation speed

typedef struct s_player
{
	int		x;
	int		y;
	double	pos_x;
	double	pos_y;
	double	dir_x;       // Direction X du joueur (vecteur directionnel)
    double	dir_y;       // Direction Y du joueur (vecteur directionnel)
    double	plane_x;     // Plan X de la caméra (perpendiculaire à la direction)
    double	plane_y;
	char	dir;
}				t_player;

typedef struct s_images {
    void	*img;
    char	*addr;
    int		width;
    int		height;
    int		pixel_bits;
    int		size_line;
    int		endian;
}				t_images;

typedef struct s_map
{
	char	**map;
	int		length;
	int		width;
}				t_map;

typedef struct s_paths
{
	char	*pfile;
	char	*ps;
	char	*pw;
	char	*pn;
	char	*pe;
	char	*pc;
	char	*pf;
}				t_paths;

typedef struct s_textures
{
	int	*rgbc;
	int	*rgbf;
	int	rgbc_hex;
	int	rgbf_hex;
}				t_textures;

typedef struct s_data
{
	int 		bool;
	t_player	p;
	t_map		map;
	t_paths		paths;
	t_textures	t;
	void		*mlx;
	void		*win;
	int			fd;
	char		**file;
	char		**tmp;
}				t_data;

int				ft_exit(t_data *data, char *err);
int				ft_strlen(char *str);
int				ft_strcmp(char *s1, char *s2);
char			*ft_strcpy(char *dest, char *src);
void			parsing(t_data *data);
void			get_file(t_data *data);
void			*ft_calloc(size_t count, size_t size);
int				get_line_nb(t_data *data);
void			get_clean_file(t_data *data);
int				line_is_empty(char *line);
void			get_paths(t_data *data);
void			check_t_paths(t_data *data);
void			extract_xpm(t_data *data, char *pre, char *line, int i);
int				ft_atoi(const char *str);
int				*convert_rgb(char *d, t_data *data);
char			**ft_split(char const *s, char c);
void			check_c(t_data *data);
void			check_f(t_data *data);
unsigned int	rgb_to_hex(int *rgb);
int				check_valid_rgb(t_data *data);
void			check_rgb(t_data *data);
void			get_map(t_data *data);
int				get_longest_line(char **file);
int				get_map_lines(char **file, t_data *data);
void			check_map_chars(t_data *data, int i);
void			check_map_playable(t_data *data, int x, int y);
void			init_player(t_player *p);
//void	init_mlx(t_data *data);

// MLX - raycasting
void	my_mlx_pixel_put(t_images *img, int x, int y, int color);
void	starting_mlx(t_data *data);
void	raycast(t_data *data, int screen_width, int screen_height);
void	print_minimap(t_data *data, t_images *img);

// mouvement
void	ft_movement(t_data *data, int key);
void	ft_mov_cam(t_data *data, int key);

#endif
