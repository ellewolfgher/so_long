/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewolfghe <ewolfghe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 12:27:30 by ewolfghe          #+#    #+#             */
/*   Updated: 2022/11/27 17:05:47 by ewolfghe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void    so_long(char *file)
{
    t_game  game;

    game.mlx = mlx_init();
    game.win = mlx_new_window(game.mlx, game.map_width * 32, game.map_height * 32, "TBD");
    mlx_loop(game.mlx);
    return(0);
}