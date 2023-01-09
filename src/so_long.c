/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewolfghe <ewolfghe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 19:37:14 by ewolfghe          #+#    #+#             */
/*   Updated: 2022/12/10 19:49:48 by ewolfghe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(char *msg, t_game *game)
{
	ft_printf(msg);
	ft_free_all(game);
	exit(EXIT_FAILURE);
}

int	ft_close_window(t_game *game)
{
	ft_free_mlx(game);
	ft_free_all(game);
	exit(EXIT_SUCCESS);
	return (0);
}

void	ft_free_all(t_game *game)
{
	int	i;

	i = 0;
	if (game->map1)
		free(game->map1);
	if (game->map2)
	{
		while (game->map2[i])
		{
			free(game->map2[i]);
			i++;
		}
		free(game->map2);
	}
	if (game->tmp_map2)
	{
		i = 0;
		while (game->tmp_map2[i])
		{
			free(game->tmp_map2[i]);
			i++;
		}
		free(game->tmp_map2);
	}
	free(game);
}

void	ft_free_mlx(t_game *game)
{
	mlx_destroy_image(game->mlx, game->tile);
	mlx_destroy_image(game->mlx, game->coins);
	mlx_destroy_image(game->mlx, game->wall);
	mlx_destroy_image(game->mlx, game->exit);
	mlx_destroy_image(game->mlx, game->player_l);
	mlx_destroy_image(game->mlx, game->player_r);
	mlx_destroy_image(game->mlx, game->player_b);
	mlx_destroy_image(game->mlx, game->player_f);
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
}

int	main(int ac, char **av)
{
	t_game	*game;

	if (ac == 2)
	{
		game = ft_calloc(sizeof(t_game), 1);
		ft_ber_check(av[1], game);
		ft_init_map(game, av[1]);
		ft_map_check(game);
		ft_format_check(game);
		ft_wall_check(game);
		ft_valid_map_check(game, game->ply_x, game->ply_y);
		ft_path_check(game);
		game->mlx = mlx_init();
		ft_init_image(game);
		mlx_hook(game->window, 2, 1L << 0, ft_key_event, game);
		mlx_hook(game->window, 17, 1L << 2, ft_close_window, game);
		mlx_loop(game->mlx);
	}
	else
	{
		game = ft_calloc(sizeof(t_game), 1);
		ft_error("Map file is missing.", game);
	}
}
