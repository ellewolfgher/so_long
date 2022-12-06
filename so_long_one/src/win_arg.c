/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewolfghe <ewolfghe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 12:05:59 by ewolfghe          #+#    #+#             */
/*   Updated: 2022/12/03 12:18:54 by ewolfghe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int close_game(t_game *game)
{
	if (game->player != 0)
		mlx_destroy_image(game->mlx, game->player);
	if (game->wall != 0)
		mlx_destroy_image(game->mlx, game->wall);
	if (game->coins != 0)
		mlx_destroy_image(game->mlx, game->coins);
	if (game->exit != 0)
		mlx_destroy_image(game->mlx, game->exit);
	mlx_destroy_image(game->mlx, game->img_bg.img_ptr);
	mlx_destroy_window(game->mlx, game ->win);
	mlx_destroy_display(game->mlx);
	free_ptr(game);
	exit(0);
}

int	main(int argc, char *argv[])
{
	if (argc == 2)
		so_long(argv[1]);
	else
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("Wrong number of arguments!", 2);
		exit(1);
	}
	return (0);
}
