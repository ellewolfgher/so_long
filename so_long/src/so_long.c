#include "../headers/so_long.h"

void	ft_error(char *msg, t_game *game)
{
	ft_putendl_fd(msg, 2);
	ft_free_all(game);
	exit(EXIT_FAILURE);
}

int	ft_close_window(t_game *game)
{
	ft_free_all(game);
	exit(EXIT_SUCCESS);
	return (0);
}

void	ft_free_all(t_game *game)
{
	int	i;

	i = 0;
	if (game->map)
		free(game->map);
	if (game->map_ptr)
	{
		while (game->map_ptr[i])
		{
			free(game->map_ptr[i]);
			i++;
		}
		free(game->map_ptr);
	}
}

void	ft_free_mlx(t_game *game)
{
	mlx_destroy_image(game->mlx, game->tile);
	mlx_destroy_image(game->mlx, game->coin);
	mlx_destroy_image(game->mlx, game->wall);
	mlx_destroy_image(game->mlx, game->exit);
	mlx_destroy_image(game->mlx, game->p_front);
	mlx_destroy_image(game->mlx, game->p_back);
	mlx_destroy_image(game->mlx, game->p_left);
	mlx_destroy_image(game->mlx, game->p_right);
	mlx_destroy_window(game->mlx, game->win);
	free(game->mlx);
}

int	main(int argc, char *argv[])
{
	t_game	*game;

	if (argc == 2)
	{
		game = ft_calloc(sizeof(t_game), 1);
		ft_ber_check(argv[1], game);
		ft_init_map(game, argv[1]);
		ft_map_check(game);
		ft_format_check(game);
		ft_wall_check(game);
		ft_valid_map_check(game, game->player_x, game->player_y);
		ft_path_check(game);
		game->mlx = mlx_init();
		ft_init_img(game);
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
