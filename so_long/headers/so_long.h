/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewolfghe <ewolfghe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 12:26:46 by ewolfghe          #+#    #+#             */
/*   Updated: 2022/11/27 16:03:56 by ewolfghe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

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




#endif