/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewolfghe <ewolfghe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 12:21:20 by ewolfghe          #+#    #+#             */
/*   Updated: 2022/12/03 12:47:59 by ewolfghe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	free_ptr(t_game *game)
{
	int	i;

	i = 0;
	free(game->mlx);
	while (i < game->map_height)
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
}

void	print_steps(t_game *game)
{
	char	*steps;
	
	steps = ft_itoa(game->steps);
	write(1, steps, ft_strlen(steps));
	write(1, "\n", 1);
	free(steps);
}

void	player_coord(t_game *game, int x, int y)
{
	if (game->map[y][x] == EXIT)
	{
		if (game->n_coins == 0)
		{
			ft_putendl_fd("Game Reseted!", 1);
			ft_close_game(game);
		}
	}
	if (game->map[y][x] == COINS || game->map[y][x] == FLOOR)
	{
		if (game->map[y][x] == COINS)
			game->n_coins--;
		game->map[game->y][game->x] = FLOOR;
		game->map[y][x] = PLAYER;
		game->x = x;
		game->steps++;
		print_steps(game);
		mlx_destroy_image(game->mlx, game->img_bg.img_ptr);
		map_init(game);
	}
}

int	key_moves(int keycode, t_game *game)
{
	if (keycode == KEY_W || keycode == KEY_UP)
		player_coord(game, game->x, game->y - 1);
	if (keycode == KEY_S || keycode == KEY_DOWN)
		player_coord(game, game->x, game-> y + 1);
	if (keycode == KEY_A || keycode == KEY_LEFT)
		player_coord(game, game->x -1, game->y);
	if (keycode == KEY_D || keycode == KEY_RIGHT)
		player_coord(game, game->x + 1, game->y);
	if (keycode == KEY_ESC)
		close_game(game);
	return (0);
}
