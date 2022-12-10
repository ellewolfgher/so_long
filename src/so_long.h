/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewolfghe <ewolfghe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 19:37:22 by ewolfghe          #+#    #+#             */
/*   Updated: 2022/12/08 16:40:54 by ewolfghe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include "../get_next_line/get_next_line.h"
# include "../mlx/mlx.h"

# define KEY_W				119
# define KEY_S				115
# define KEY_A				97
# define KEY_D				100

# define KEY_UP  			65362
# define KEY_DOWN  			65364
# define KEY_LEFT  			65361
# define KEY_RIGHT 			65363

# define KEY_ESC  			65307

# define PL_FT "./textures/player_front.xpm"
# define PL_BK "./textures/player_back.xpm"
# define PL_LT "./textures/player_left.xpm"
# define PL_RT "./textures/player_right.xpm"
# define COIN "./textures/coin.xpm"
# define EXIT "./textures/exit.xpm"
# define TILES "./textures/tiles.xpm"
# define WALL "./textures/wall.xpm"

typedef struct s_game
{
	void	*mlx;
	void	*window;
	void	*player_f;
	void	*player_b;
	void	*player_r;
	void	*player_l;
	void	*exit;
	void	*wall;
	void	*coins;
	void	*tile;
	int		imgy;
	int		imgx;
	int		ply_x;
	int		ply_y;
	int		map_x;
	int		map_y;
	char	*map1;
	char	**map2;
	char	**tmp_map2;
	int		coins_count;
	int		tmp_coins_count;
	int		exit_count;
	int		player_count;
	int		validate;
	int		move_count;
	char	coords;
	char	*move_count_screen;
}	t_game;

void	ft_ber_check(char *map_name, t_game *game);
void	ft_error(char *msg, t_game *game);
int		ft_key_event(int keycode, t_game *game);
void	ft_init_map(t_game *game, char *map);
void	ft_map_check(t_game *game);
void	ft_ber_map_check(t_game *game);
void	ft_format_check(t_game *game);
void	ft_wall_check(t_game *game);
void	ft_side_check(t_game *game);
void	ft_valid_map_check(t_game *game, int x, int y);
void	ft_path_check(t_game *game);
void	ft_init_image(t_game *game);
void	ft_put_image(t_game *game);
void	ft_put_image_player(t_game *game, int x, int y);
void	ft_score(t_game *game);
void	ft_init_xy(int *x, int *y);
void	ft_map_size(int *x, int *y, t_game *game);
void	ft_render_after_move(t_game *game);
void	ft_check_up(int key, t_game *game);
void	ft_check_down(int key, t_game *game);
void	ft_check_right(int key, t_game *game);
void	ft_check_left(int key, t_game *game);
int		ft_check_movement(t_game *game, int x, int y);
int		ft_close_window(t_game *game);
void	ft_free_all(t_game *game);
void	ft_free_mlx(t_game *game);

#endif
