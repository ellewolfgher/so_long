/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewolfghe <ewolfghe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 19:37:29 by ewolfghe          #+#    #+#             */
/*   Updated: 2022/12/08 14:23:35 by ewolfghe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_xy(int *x, int *y)
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
	mlx_clear_window(game->mlx, game->window);
	ft_put_image(game);
}

int	ft_check_movement(t_game *game, int x, int y)
{
	if (game->map2[y][x] != '1')
	{
		if (game->map2[y][x] == 'C')
			game->coins_count--;
		else if (!game->coins_count && game->map2[y][x] == 'E')
		{
			ft_printf("MOVES: %d\nCongratulations!", ++(game->move_count));
			ft_free_all(game);
			exit(EXIT_SUCCESS);
		}
		if (game->map2[y][x] == 'E')
			return (0);
		ft_printf("MOVES: %d\n", ++(game->move_count));
		return (1);
	}
	return (0);
}

void	ft_ber_map_check(t_game *game)
{
	if (game->coins_count < 1 || game->exit_count != 1
		|| game->player_count != 1)
		ft_error("Error! Map must include 1P or 1C or 1E.", game);
}
