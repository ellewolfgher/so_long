#include "../headers/so_long.h"

void	ft_init_map(t_game *game, char *ber)
{
	int		fd;
	char	*buff;

	fd = open(ber, O_RDONLY);
	if (fd < 0)
		ft_error("File not found!", game);
	buff = get_next_line(fd);
	if (!buff)
		ft_error("File is empty!", game);
	while (buff)
	{
		game->map = ft_strjoin(game->map, buff);
		free(buff);
		buff = get_next_line(fd);
	}
	free(buff);
	game->map_ptr = ft_split(game->map, '\n');
	game->aux_map_ptr = ft_split(game->map, '\n');
}

void	ft_init_img(t_game *game)
{
	game->p_front = mlx_xpm_file_to_image(game->mlx, XPM_P_FRONT,
			&game->img_x, &game->img_y);
	game->p_back = mlx_xpm_file_to_image(game->mlx, XPM_P_BACK,
			&game->img_x, &game->img_y);
	game->p_left = mlx_xpm_file_to_image(game->mlx, XPM_P_LEFT,
			&game->img_x, &game->img_y);
	game->p_right = mlx_xpm_file_to_image(game->mlx, XPM_P_RIGHT,
			&game->img_x, &game->img_y);
	game->coin = mlx_xpm_file_to_image(game->mlx, XPM_COIN,
			&game->img_x, &game->img_y);
	game->exit = mlx_xpm_file_to_image(game->mlx, XPM_EXIT,
			&game->img_x, &game->img_y);
	game->tile = mlx_xpm_file_to_image(game->mlx, XPM_TILE,
			&game->img_x, &game->img_y);
	game->wall = mlx_xpm_file_to_image(game->mlx, XPM_WALL,
			&game->img_x, &game->img_y);
	game->win = mlx_new_window(game->mlx, game->map_x * 64, \
		game->map_y * 64, "so_long");
	game->coords = 'F';
	ft_set_img(game);
}

void	ft_set_img(t_game *game)
{
	int	x;
	int	y;

	ft_init_pos(&x, &y);
	while (y < game->map_y * 64)
	{
		if (game->map_ptr[y / 64][x / 64] != WALL
			&& game->map_ptr[y / 64][x / 64] != TILES)
			mlx_put_image_to_window(game->mlx, game->win,
				game->tile, x, y);
		if (game->map_ptr[y / 64][x / 64] == WALL)
			mlx_put_image_to_window(game->mlx, game->win, game->wall, x, y);
		else if (game->map_ptr[y / 64][x / 64] == TILES)
			mlx_put_image_to_window(game->mlx, game->win,
				game->tile, x, y);
		else if (game->map_ptr[y / 64][x / 64] == EXIT)
			mlx_put_image_to_window(game->mlx, game->win, game->exit, x, y);
		else if (game->map_ptr[y / 64][x / 64] == COINS)
			mlx_put_image_to_window(game->mlx, game->win,
				game->coin, x, y);
		else if (game->map_ptr[y / 64][x / 64] == PLAYER)
			ft_set_img_player(game, x, y);
		ft_map_size(&x, &y, game);
	}
	ft_score(game);
}

void	ft_set_img_player(t_game *game, int x, int y)
{
	if (game->coords == 'F')
		mlx_put_image_to_window(game->mlx, game->win, game->p_front, x, y);
	else if (game->coords == 'R')
		mlx_put_image_to_window(game->mlx, game->win, game->p_right, x, y);
	else if (game->coords == 'L')
		mlx_put_image_to_window(game->mlx, game->win, game->p_left, x, y);
	else if (game->coords == 'B')
		mlx_put_image_to_window(game->mlx, game->win, game->p_back, x, y);
}

void	ft_score(t_game *game)
{
	game->move_count_screen = ft_itoa(game->move_count);
	mlx_string_put(game->mlx, game->win, 30, 30, 0xFFFFFF, \
	"Moves: ");
	mlx_string_put(game->mlx, game->win, 65, 30, 0xFFFFFF, \
		game->move_count_screen);
	free(game->move_count_screen);
}
