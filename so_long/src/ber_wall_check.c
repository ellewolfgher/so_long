#include "../headers/so_long.h"

void	ft_ber_check(char *map_name, t_game *game)
{
	int	len;

	len = ft_strlen(map_name);
	if (!ft_strnstr(map_name[len - 4], ".ber", 4))
		ft_error("It needs a .ber file extention", game);
}

void	ft_map_check(t_game *game)
{
	static int	i = 0;
	static int	j = 0;

	while (game->map_ptr[i])
	{
		j = 0;
		while (game->map_ptr[i][j])
		{
			if (game->map_ptr[i][j] == COINS)
				game->coins_count++;
			else if (game->map_ptr[i][j] == EXIT)
				game->exit_count++;
			else if (game->map_ptr[i][j] == PLAYER)
			{
				game->player_count++;
				game->player_x = j;
				game->player_y = i;
			}
			else if (game->map_ptr[i][j] != TILES && game->map_ptr[i][j] != '1')
				ft_error("Error! Map is missing 1P or 1C or 1E.", game);
			j++;
		}
		i++;
	}
	ft_ber_map_check(game);
}

void	ft_format_check(t_game *game)
{
	int	line_len_1;
	int	line_len_2;
	int	i;

	i = 0;
	line_len_1 = ft_strlen(game->map_ptr[0]);
	game->map_x = line_len_1;
	while (game->map_ptr[i])
	{
		line_len_2 = ft_strlen(game->map_ptr[i]);
		if (line_len_2 != line_len_1)
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
	while (game->map_ptr[i])
	{
		len++;
		i++;
	}
	game->map_y = len;
	i = 0;
	while (game->map_ptr[0][i] && game->map_ptr[len - 1][i])
	{
		if (game->map_ptr[0][i] != '1' || game->map_ptr[len - 1][i] != '1')
			ft_error("Error! The walls are not closed.", game);
		i++;
	}
	ft_sides_check(game);
}

void	ft_sides_check(t_game *game)
{
	int	i;
	int	len;

	i = 0;
	len = game->map_x;
	while (i < game->map_y)
	{
		if (game->map_ptr[i][0] != '1' || game->map_ptr[i][len - 1] != '1')
			ft_error("Error! The walls are not closed.", game);
		i++;
	}
	game->aux_coins_count = game->coins_count;
}
