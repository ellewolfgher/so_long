/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewolfghe <ewolfghe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 19:36:56 by ewolfghe          #+#    #+#             */
/*   Updated: 2022/12/07 19:36:57 by ewolfghe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_key_event(int key, t_game *game)
{
	if (key == KEY_ESC)
	{
		ft_free_all(game);
		exit(EXIT_SUCCESS);
	}
	ft_check_up(key, game);
	ft_check_down(key, game);
	ft_check_left(key, game);
	ft_check_right(key, game);
	return (0);
}

void	ft_check_up(int key, t_game *game)
{
	if (key == KEY_W || key == KEY_UP)
	{
		if (ft_check_movement(game, game->ply_x, game->ply_y - 1))
		{
			game->map2[game->ply_y][game->ply_x] = '0';
			game->ply_y -= 1;
			game->map2[game->ply_y][game->ply_x] = 'P';
			game->coords = 'B';
			ft_render_after_move(game);
		}
	}
}

void	ft_check_down(int key, t_game *game)
{
	if (key == KEY_S || key == KEY_DOWN)
	{
		if (ft_check_movement(game, game->ply_x, game->ply_y + 1))
		{
			game->map2[game->ply_y][game->ply_x] = '0';
			game->ply_y += 1;
			game->map2[game->ply_y][game->ply_x] = 'P';
			game->coords = 'F';
			ft_render_after_move(game);
		}
	}
}

void	ft_check_left(int key, t_game *game)
{
	if (key == KEY_A || key == KEY_LEFT)
	{
		if (ft_check_movement(game, game->ply_x - 1, game->ply_y))
		{
			game->map2[game->ply_y][game->ply_x] = '0';
			game->ply_x -= 1;
			game->map2[game->ply_y][game->ply_x] = 'P';
			game->coords = 'L';
			ft_render_after_move(game);
		}
	}
}

void	ft_check_right(int key, t_game *game)
{
	if (key == KEY_D || key == KEY_RIGHT)
	{
		if (ft_check_movement(game, game->ply_x + 1, game->ply_y))
		{
			game->map2[game->ply_y][game->ply_x] = '0';
			game->ply_x += 1;
			game->map2[game->ply_y][game->ply_x] = 'P';
			game->coords = 'R';
			ft_render_after_move(game);
		}
	}
}
