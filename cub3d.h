#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

# define KEY_Q 12
# define KEY_1 13
# define KEY_2 14
# define KEY_3 15
# define KEY_4 0
# define KEY_5 1
# define KEY_6 2
# define KEY_RIGHT 124
# define KEY_LEFT 123
# define KEY_ESC 53
# define WIDTH 640
# define HEIGHT 480
# define TEX_HEIGHT 64

typedef struct s_dirv {
	double	x;
	double	y;
} t_dirv;

typedef struct s_rotate {
	double	x;
	double	y;
} t_rotate;

typedef struct s_move {
	double x;
	double y;
} t_move;
typedef struct s_pos {
	double x;
	double y;
}	t_pos;

typedef struct s_player {
	int	x;
	int	y;
	char	dir;
	t_pos	pos;
	t_dirv	dirv;
	t_rotate	rotate;
	t_move	move;
}		t_player;

typedef struct s_dda {
	int	side;
	int	hit;
	double	cam;
	int	stepx;
	int	stepy;
	double step;
	double raydirx;
	double raydiry;
	int mapx;
	int mapy;
	double distx;
	double disty;
	double ddistx;
	double ddisty;
	double dist;
	int lineheight;
	int drawstart;
	int drawend;
	double wall;
}		t_dda;

typedef struct s_data {
	char *n_tex;
    char *s_tex;
    char *w_tex;
    char *e_tex;
    int *f_color;
    int *c_color;
    int map_width;
    int map_height;
	void	*mlx;
	void	*win;
	void	*img;
	t_player player;
	char	**map;	
	char	*pmap;
	t_dda	*dda;
	double i;
}		t_data;


char	*ft_strncpy(char *dest, char *src, int n);
char			**ft_split(char *str, char *charset);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *str);
void    ft_parse(t_data *data);
int	get_next_line(int fd, char **line);

#endif
