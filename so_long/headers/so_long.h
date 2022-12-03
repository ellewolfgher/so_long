/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewolfghe <ewolfghe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 12:26:46 by ewolfghe          #+#    #+#             */
/*   Updated: 2022/12/03 12:45:38 by ewolfghe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "./get_next_line.h"
# include "../libft/libft.h"
# include <unistd.h>
# include <fcntl.h>

# define WALL				'1'
# define FLOOR 				'0'
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

# define FRONT				1
# define LEFT				2
# define RIGHT				3
# define BACK				4

typedef struct s_img
{
	void	*img_ptr;
	int		*addr;
	int		height;
	int		width;
	int		size_line;
	int		bpp;
	int		endian;	
}				t_img;

typedef struct s_game
{
	t_img	img_bg;
	void	*wall;
	void	*coins;
	void	*player;
	void	*exit;
	void	*win;
	void	*mlx;
	char	**map;
	int		x;
	int		y;
	int		map_height;
	int		map_width;
	int		steps;
	int		fd;
	int		n_players;
	int		n_coins;
	int		n_exit;
}				t_game;

void	map_init(t_game *game);
void	set_bg(t_game *game);
void	set_tile(t_game *game, int x, int y, char ch);
void	free_ptr(t_game *game);
void	print_steps(t_game *game);
void	player_coord(t_game *game, int x, int y);
int		key_moves(int keycode, t_game *game);
int		close_game(t_game *game);

#endif