#ifndef CUB3D_H
# define CUB3D_H

# define KEY_Q 12
# define KEY_W 13
# define KEY_W 14
# define KEY_W 15
# define KEY_W 0
# define KEY_W 1
# define KEY_W 2
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
	void	*mlx;
	void	*win;
	void	*img;
	t_player player;
	char	**map;	
	t_dda	*dda;
	double i;
}		t_data;

#endif
