#include "../headers/so_long.h"

void	ft_valid_map_check(t_game *game, int x, int y)
{
	char	*ptr;

	ptr = &game->map_ptr[y][x];
	if (*ptr == EXIT)
		game->valid = 1;
	if (*ptr != EXIT && *ptr != WALL)
	{
		if (*ptr == COINS)
			game->aux_coins_count--;
		*ptr = '.';
		if (game->map_ptr[y][x + 1] != WALL &&
			game->map_ptr[y][x + 1] != '.')
			ft_valid_map_check(game, x + 1, y);
		if (game->map_ptr[y][x - 1] != WALL &&
			game->map_ptr[y][x - 1] != '.')
			ft_valid_map_check(game, x - 1, y);
		if (game->map_ptr[y - 1][x] != WALL &&
			game->map_ptr[y - 1][x] != '.')
			ft_valid_map_check(game, x, y - 1);
		if (game->map_ptr[y + 1][x] != WALL &&
			game->map_ptr[y + 1][x] != '.')
			ft_valid_map_check(game, x, y + 1);
	}
}

void	ft_path_check(t_game *game)
{
	int	i;

	i = 0;
	while (game->map_ptr[i])
	{
		free(game->map_ptr[i]);
		i++;
	}
	free(game->map_ptr);
	if (game->aux_coins_count != 0 || game->valid != 1)
		ft_error("Error! No valid path found.", game);
}
