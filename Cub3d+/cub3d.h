/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunegel <akunegel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 14:47:16 by akunegel          #+#    #+#             */
/*   Updated: 2024/08/13 20:07:49 by akunegel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define FOV 60
# define TEX_SIZE 64
# define WIN_WIDTH 600
# define WIN_HEIGHT 800
# define SPEED 4
# define RO_SPEED 0.005

# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include "gnl/get_next_line.h"
# include <math.h>

typedef struct s_textures {
    int *rgbc;
    int *rgbf;
    int rgbc_hex;
    int rgbf_hex;
}   t_textures;

typedef struct s_ray {
    double dir_x;           // Direction X du rayon
    double dir_y;           // Direction Y du rayon
    double plane_x;         // Plan X de la caméra (généralement partagé avec le joueur)
    double plane_y;         // Plan Y de la caméra (généralement partagé avec le joueur)
    double camera_x;        // Position X de la caméra dans l'espace de la caméra (de -1 à 1)
    double ray_dir_x;       // Direction X calculée du rayon
    double ray_dir_y;       // Direction Y calculée du rayon
    int map_x;              // Coordonnée X sur la carte du carré actuellement occupé par le rayon
    int map_y;              // Coordonnée Y sur la carte du carré actuellement occupé par le rayon
    double side_dist_x;     // Distance du bord actuel au prochain bord en X
    double side_dist_y;     // Distance du bord actuel au prochain bord en Y
    double delta_dist_x;    // Distance qu'un rayon doit parcourir pour passer au prochain carré en X
    double delta_dist_y;    // Distance qu'un rayon doit parcourir pour passer au prochain carré en Y
    double perp_wall_dist;  // Distance perpendiculaire à la paroi (projetée sur le plan de la caméra)
    int step_x;             // Direction de l'étape à prendre en X (-1 ou 1)
    int step_y;             // Direction de l'étape à prendre en Y (-1 ou 1)
    int hit;                // Indicateur si une paroi est touchée (1 pour hit)
    int side;               // Indicateur du côté de la paroi touchée (0 pour X, 1 pour Y)
    int line_height;        // Hauteur de la ligne à dessiner sur l'écran
    int draw_start;         // Point de départ du dessin sur l'axe Y
    int draw_end;           // Point de fin du dessin sur l'axe Y
}   t_ray;

typedef struct s_images {
    void    *img;
    int     *addr;
    int     width;
    int     height;
    int     pixel_bits;
    int     size_line;
    int     endian;
} t_images;

typedef struct s_map {
    char **map;
    int length;
    int width;
} t_map;

typedef struct s_player {
    int x;
    int y;
    double dir_x;       // Direction X du joueur (vecteur directionnel)
    double dir_y;       // Direction Y du joueur (vecteur directionnel)
    double plane_x;     // Plan X de la caméra (perpendiculaire à la direction)
    double plane_y;
    char dir;
} t_player;

typedef struct s_img
{
	void	*img;
	int		*addr;
	int		pixel_bits;
	int		size_line;
	int		endian;
}	t_img;

typedef struct s_data {
    void *mlx;
    void *win;
    t_player p;
    char **file;
    char **tmp;
    char *path;
    int fd;
    t_map map;
    t_ray ray;
    char dir;
    int pos_x;
    int pos_y;
    char *no;
    char *so;
    char *we;
    char *ea;
    char *f;
    char *c;
    t_textures t;
    t_images *images;
    t_img img;
} t_data;

int has_cub_extension(char *file);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
void parse_data(t_data *data);
void get_data(t_data *data);
void grab_data(t_data *data, int i);
void    tex_alloc(t_data *data, int t, int c);
void get_content(t_data *data, int i, size_t t);
void check_pre(char *pre, int i, t_data *data);
void grab_data(t_data *data, int i);
void get_content_bis(t_data *data, int i, size_t b);
void path_correct_2(char *tmp, t_data *data, size_t t);
void path_correct(char *tmp, t_data *data, size_t t);
void path_correct_bis(char *tmp, t_data *data, size_t b);
void    get_map(t_data *data);
int get_count(char **file);
void check_map(t_data *data, char **s);
void check_tex(t_data *data);
char	**ft_split(char const *s, char c);
int	ft_atoi(const char *str);
int init_textures(t_data *data);
void init_player(t_player *p);
int	key_press(int keycode, t_data *data);
unsigned int rgb_to_hex(int *rgb);

void	init_mlx(t_data *data);

#endif