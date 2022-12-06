/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacis@student.42istanbul.com.tr <yacis>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 19:39:58 by yacis@stude       #+#    #+#             */
/*   Updated: 2022/10/08 16:33:32 by yacis@stude      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	ft_init_pos(int *x, int *y)
{
	*x = 0;
	*y = 0;
}

void	ft_map_size(int *x, int *y, t_game *game)
{
	if (*x == game->map_x * 64)
	{
		*x = -64;
		*y += 64;
	}
	*x += 64;
}

void	ft_render_after_move(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	ft_put_image(game);
}

int	ft_check_moves(t_game *game, int x, int y)
{
	if (game->map_ptr[y][x] != WALL)
	{
		if (game->map_ptr[y][x] == COINS)
			game->coins_count--;
		else if (!game->coins_count && game->map_ptr[y][x] == EXIT)
		{
			ft_printf("Moves: %d\nCongratulations!", ++(game->move_count));
			ft_free_all(game);
			exit(EXIT_SUCCESS);
		}
		if (game->map_ptr[y][x] == EXIT)
			return (0);
		ft_printf("Moves: %d\n", ++(game->move_count));
		return (1);
	}
	return (0);
}

void	ft_ber_map_check(t_game *game)
{
	if (game->coins_count < 1 || game->exit_count != 1
		|| game->player_count != 1)
		ft_error("Error! Map is missing 1P or 1C or 1E.", game);
}
