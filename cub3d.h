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

typedef struct s_player {
	int	x;
	int	y;
	char	dir;
	t_dirv	dirv;
	t_rotate	rotate;
	t_move	move;
}		t_player;

typedef struct s_data {
	void	*mlx;
	void	*win;
	t_player player;
	char	**map;	
}		t_data;

#endif
