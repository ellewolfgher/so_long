/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewolfghe <ewolfghe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 19:36:47 by ewolfghe          #+#    #+#             */
/*   Updated: 2022/12/10 20:05:29 by ewolfghe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_map(t_game *game, char *map)
{
	int		fd;
	char	*buff;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		ft_error("File not found!", game);
	buff = get_next_line(fd);
	if (!buff)
		ft_error("File is empty!", game);
	while (buff)
	{
		game->map1 = ft_strjoin(game->map1, buff);
		free(buff);
		buff = get_next_line(fd);
	}
	free(buff);
	game->map2 = ft_split(game->map1, '\n');
	game->tmp_map2 = ft_split(game->map1, '\n');
}

void	ft_init_image(t_game *game)
{
	game->player_f = mlx_xpm_file_to_image(game->mlx, PL_FT,
			&game->imgx, &game->imgy);
	game->player_b = mlx_xpm_file_to_image(game->mlx, PL_BK,
			&game->imgx, &game->imgy);
	game->player_l = mlx_xpm_file_to_image(game->mlx, PL_LT,
			&game->imgx, &game->imgy);
	game->player_r = mlx_xpm_file_to_image(game->mlx, PL_RT,
			&game->imgx, &game->imgy);
	game->coins = mlx_xpm_file_to_image(game->mlx, COIN,
			&game->imgx, &game->imgy);
	game->exit = mlx_xpm_file_to_image(game->mlx, EXIT,
			&game->imgx, &game->imgy);
	game->tile = mlx_xpm_file_to_image(game->mlx, TILES,
			&game->imgx, &game->imgy);
	game->wall = mlx_xpm_file_to_image(game->mlx, WALL,
			&game->imgx, &game->imgy);
	game->window = mlx_new_window(game->mlx, game->map_x * 64, \
		game->map_y * 64, "So_Longuinho");
	game->coords = 'F';
	ft_put_image(game);
}

void	ft_put_image(t_game *game)
{
	int	x;
	int	y;

	ft_init_xy(&x, &y);
	while (y < game->map_y * 64)
	{
		if (game->map2[y / 64][x / 64] != '1'
			&& game->map2[y / 64][x / 64] != '0')
			mlx_put_image_to_window(game->mlx, game->window,
				game->tile, x, y);
		if (game->map2[y / 64][x / 64] == '1')
			mlx_put_image_to_window(game->mlx, game->window, game->wall, x, y);
		else if (game->map2[y / 64][x / 64] == '0')
			mlx_put_image_to_window(game->mlx, game->window,
				game->tile, x, y);
		else if (game->map2[y / 64][x / 64] == 'E')
			mlx_put_image_to_window(game->mlx, game->window, game->exit, x, y);
		else if (game->map2[y / 64][x / 64] == 'C')
			mlx_put_image_to_window(game->mlx, game->window,
				game->coins, x, y);
		else if (game->map2[y / 64][x / 64] == 'P')
			ft_put_image_player(game, x, y);
		ft_map_size(&x, &y, game);
	}
	ft_score(game);
}

void	ft_put_image_player(t_game *game, int x, int y)
{
	if (game->coords == 'F')
		mlx_put_image_to_window(game->mlx, game->window, game->player_f, x, y);
	else if (game->coords == 'R')
		mlx_put_image_to_window(game->mlx, game->window, game->player_r, x, y);
	else if (game->coords == 'L')
		mlx_put_image_to_window(game->mlx, game->window, game->player_l, x, y);
	else if (game->coords == 'B')
		mlx_put_image_to_window(game->mlx, game->window, game->player_b, x, y);
}

void	ft_score(t_game *game)
{
	game->move_count_screen = ft_itoa(game->move_count);
	mlx_string_put(game->mlx, game->window, 30, 30, 0xDC143C, \
	"MOVES:  ");
	mlx_string_put(game->mlx, game->window, 65, 30, 0xDC143C, \
		game->move_count_screen);
	free(game->move_count_screen);
}
