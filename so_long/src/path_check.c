/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewolfghe <ewolfghe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 19:37:05 by ewolfghe          #+#    #+#             */
/*   Updated: 2022/12/08 14:15:19 by ewolfghe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_valid_map_check(t_game *game, int x, int y)
{
	char	*p;

	p = &game->tmp_map2[y][x];
	if (*p == 'E')
		game->validate = 1;
	if (*p != 'E' && *p != '1')
	{
		if (*p == 'C')
			game->tmp_coins_count--;
		*p = '.';
		if (game->tmp_map2[y][x + 1] != '1' &&
			game->tmp_map2[y][x + 1] != '.')
			ft_valid_map_check(game, x + 1, y);
		if (game->tmp_map2[y][x - 1] != '1' &&
			game->tmp_map2[y][x - 1] != '.')
			ft_valid_map_check(game, x - 1, y);
		if (game->tmp_map2[y - 1][x] != '1' &&
			game->tmp_map2[y - 1][x] != '.')
			ft_valid_map_check(game, x, y - 1);
		if (game->tmp_map2[y + 1][x] != '1' &&
			game->tmp_map2[y + 1][x] != '.')
			ft_valid_map_check(game, x, y + 1);
	}
}

void	ft_path_check(t_game *game)
{
	int	i;

	i = 0;
	while (game->tmp_map2[i])
	{
		free(game->tmp_map2[i]);
		i++;
	}
	free(game->tmp_map2);
	if (game->tmp_coins_count != 0 || game->validate != 1)
		ft_error("Error! Valid path is missing.", game);
}
