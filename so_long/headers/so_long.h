#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../mlx/mlx.h"
# include "./get_next_line.h"
# include "../libft/libft.h"

# define WALL				'1'
# define TILES 				'0'
# define COINS  			'C'
# define PLAYER				'P'
# define EXIT 		 		'E'

# define KEY_W				119
# define KEY_S				115
# define KEY_A				97
# define KEY_D				100

# define KEY_UP  			65362
# define KEY_DOWN  			65364
# define KEY_LEFT  			65361
# define KEY_RIGHT 			65363

# define KEY_ESC  			65307

# define XPM_P_FRONT "./assets/player_front.xpm"
# define XPM_P_BACK "./assets/player_back.xpm"
# define XPM_P_LEFT "./assets/player_left.xpm"
# define XPM_P_RIGHT "./assets/player_right.xpm"
# define XPM_COIN "./assets/coin.xpm"
# define XPM_EXIT "./assets/exit.xpm"
# define XPM_TILE "./assets/tile.xpm"
# define XPM_WALL "./assets/wall.xpm"

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*p_front;
	void	*p_back;
	void	*p_right;
	void	*p_left;
	void	*exit;
	void	*wall;
	void	*coin;
	void	*tile;
	int		img_x;
	int		img_y;
	int		pos_x;
	int		pos_y;
	int		player_x;
	int		player_y;
	int		map_x;
	int		map_y;
	char	*map;
	char	**map_ptr;
	char	**aux_map_ptr;
	int		coins_count;
	int		aux_coins_count;
	int		exit_count;
	int		player_count;
	int		valid_e;
	int		moves_count;
	char	coords;
	char	*move_count_screen;
}	t_game;

void	ft_ber_check(char *map_name, t_game *game);
void	ft_error(char *msg, t_game *game);
void	ft_init_map(t_game *game, char *map);
void	ft_map_check(t_game *game);
void	ft_ber_map_check(t_game *game);
void	ft_format_check(t_game *game);
void	ft_wall_check(t_game *game);
void	ft_sides_check(t_game *game);
void	ft_valid_map_check(t_game *game, int x, int y);
void	ft_path_check(t_game *game);
void	ft_init_img(t_game *game);
void	ft_set_img(t_game *game);
void	ft_set_img_player(t_game *game, int x, int y);
void	ft_score(t_game *game);
void	ft_init_pos(int *x, int *y);
void	ft_map_size(int *x, int *y, t_game *game);
void	ft_render_after_move(t_game *game);
void	ft_key_up(int key, t_game *game);
void	ft_key_down(int key, t_game *game);
void	ft_key_right(int key, t_game *game);
void	ft_key_left(int key, t_game *game);
void	ft_free_all(t_game *game);
void	ft_free_mlx(t_game *game);
int		ft_key_event(int keycode, t_game *game);
int		ft_check_moves(t_game *game, int x, int y);
int		ft_close_window(t_game *game);

#endif
