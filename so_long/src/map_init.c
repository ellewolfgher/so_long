#include "../headers/so_long.h"

void	set_tile(t_game *game, int x, int y, char ch)
{
	if (ch == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->coins, x, y);
	else if (ch == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->wall, x, y);
	else if (ch == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->exit, x, y);
	else if (ch == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->player, x, y);
}

void	set_bg(t_game *game)
{
	int	h_count;
	int	w_count;

	h_count = -1;
	game->img_bg.img_ptr = mlx_new_image(game->mlx, game->map_width * 32,
			game->map_height * 32);
	game->img_bg.addr = (int *)mlx_get_data_addr(game->img_bg.img_ptr,
			&game->img_bg.bpp, &game->img_bg.size_line, &game->img_bg.endian);
	while (++h_count < (game->map_height * 32))
	{	
		w_count = -1;
		while (++w_count < (game->map_width * 32))
		{
			game->img_bg.addr[h_count * (game->map_width * 32) + w_count] = 0x000000;
		}		
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img_bg.img_ptr, 0, 0);	
}

void	map_init(t_game *game)
{
	int	x;
	int y;

	set_bg(game);
	y = -1;
	while (++y < game->map_height)
	{
		x = -1;
		while (++x < game->map_width)
		{
			if (game->map[y][x] == '1')
				set_tile(game, x * 32, y * 32, '1');
			else if (game->map[y][x] == 'E')
				set_tile(game, x * 32, y * 32, 'E');
			else if (game->map[y][x] == 'C')
				set_tile(game, x * 32, y * 32, 'C');
			else if (game->map[y][x] == 'P')
			{
				game->x = x;
				game->y = y;
				set_tile(game, x * 32, y * 32, 'P');
			}
		}
	}
}
