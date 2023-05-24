/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Verdoodt <Verdoodt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 12:17:05 by devoma            #+#    #+#             */
/*   Updated: 2023/05/21 20:27:49 by Verdoodt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int ac, char **av)
{
	char		**map;
	t_data		data;

	map = check_arguments(ac, av);
	if (!map)
		return (0);
	data.args = create_struct(map);
	init_all_structs(&data);
	data.game->mlx = mlx_init();
	data.game->win = mlx_new_window(data.game->mlx, WIDTH, HEIGHT, \
	"Cub3d");
	get_img_xpm(&data);
	init_win(&data);
	mlx_hook(data.game->win, 17, 1L << 0, ft_close, &data);
	mlx_hook(data.game->win, 2, 1L << 0, key_ft, &data);
	mlx_loop(data.game->mlx);
	destroy_struct(data.args);
	exit(0);
}
