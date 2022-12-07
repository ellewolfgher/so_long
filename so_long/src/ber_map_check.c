/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ber_map_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewolfghe <ewolfghe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 19:36:37 by ewolfghe          #+#    #+#             */
/*   Updated: 2022/12/07 19:36:38 by ewolfghe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_ber_check(char *map_name, t_game *game)
{
	int	len;

	len = ft_strlen(map_name);
	if (map_name[len - 1] != 'r' || map_name[len - 2] != 'e'
		|| map_name[len - 3] != 'b' || map_name[len - 4] != '.'
		|| len <= 9)
		ft_error("Must be '.ber' extension!", game);
}

void	ft_map_check(t_game *game)
{
	static int	i = 0;
	static int	j = 0;

	while (game->map2[i])
	{
		j = 0;
		while (game->map2[i][j])
		{
			if (game->map2[i][j] == 'C')
				game->coins_count++;
			else if (game->map2[i][j] == 'E')
				game->exit_count++;
			else if (game->map2[i][j] == 'P')
			{
				game->player_count++;
				game->ply_x = j;
				game->ply_y = i;
			}
			else if (game->map2[i][j] != '0' && game->map2[i][j] != '1')
				ft_error("Error! Map must include 1P or 1C or 1E.", game);
			j++;
		}
		i++;
	}
	ft_ber_map_check(game);
}

void	ft_format_check(t_game *game)
{
	int	line_len1;
	int	line_len2;
	int	i;

	i = 0;
	line_len1 = ft_strlen(game->map2[0]);
	game->map_x = line_len1;
	while (game->map2[i])
	{
		line_len2 = ft_strlen(game->map2[i]);
		if (line_len2 != line_len1)
			ft_error("Error! The map is not rectangular.", game);
		i++;
	}
}

void	ft_wall_check(t_game *game)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (game->map2[i])
	{
		len++;
		i++;
	}
	game->map_y = len;
	i = 0;
	while (game->map2[0][i] && game->map2[len - 1][i])
	{
		if (game->map2[0][i] != '1' || game->map2[len - 1][i] != '1')
			ft_error("Error! The walls are not closed.", game);
		i++;
	}
	ft_side_check(game);
}

void	ft_side_check(t_game *game)
{
	int	i;
	int	len;

	i = 0;
	len = game->map_x;
	while (i < game->map_y)
	{
		if (game->map2[i][0] != '1' || game->map2[i][len - 1] != '1')
			ft_error("Error! The walls are not closed.", game);
		i++;
	}
	game->tmp_coins_count = game->coins_count;
}
