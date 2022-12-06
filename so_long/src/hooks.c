#include "../headers/so_long.h"

int	ft_key_event(int key, t_game *game)
{
	if (key == KEY_ESC)
	{
		ft_free_all(game);
		exit(EXIT_SUCCESS);
	}
	ft_key_up(key, game);
	ft_key_down(key, game);
	ft_key_left(key, game);
	ft_key_right(key, game);
	return (0);
}

void	ft_key_up(int key, t_game *game)
{
	if (key == KEY_UP || key == KEY_W)
	{
		if (ft_check_moves(game, game->player_x, game->player_y - 1))
		{
			game->map_ptr[game->player_y][game->player_x] = TILES;
			game->player_y -= 1;
			game->map_ptr[game->player_y][game->player_x] = PLAYER;
			game->coords = 'B';
			ft_render_after_move(game);
		}
	}
}

void	ft_key_down(int key, t_game *game)
{
	if (key == KEY_DOWN || key == KEY_S)
	{
		if (ft_check_moves(game, game->player_x, game->player_y + 1))
		{
			game->map_ptr[game->player_y][game->player_x] = TILES;
			game->player_y += 1;
			game->map_ptr[game->player_y][game->player_x] = PLAYER;
			game->coords = 'F';
			ft_render_after_move(game);
		}
	}
}

void	ft_key_left(int key, t_game *game)
{
	if (key == KEY_LEFT || key == KEY_A)
	{
		if (ft_check_moves(game, game->player_x - 1, game->player_y))
		{
			game->map_ptr[game->player_y][game->player_x] = TILES;
			game->player_x -= 1;
			game->map_ptr[game->player_y][game->player_x] = PLAYER;
			game->coords = 'L';
			ft_render_after_move(game);
		}
	}
}

void	ft_key_right(int key, t_game *game)
{
	if (key == KEY_RIGHT || key == KEY_D)
	{
		if (ft_check_moves(game, game->player_x + 1, game->player_y))
		{
			game->map_ptr[game->player_y][game->player_x] = TILES;
			game->player_x += 1;
			game->map_ptr[game->player_y][game->player_x] = PLAYER;
			game->coords = 'R';
			ft_render_after_move(game);
		}
	}
}
