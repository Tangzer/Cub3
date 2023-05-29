/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Verdoodt <Verdoodt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 12:16:59 by devoma            #+#    #+#             */
/*   Updated: 2023/05/29 18:03:06 by Verdoodt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	key_ft(int key, t_data *data)
{
	if (key == RIGHT)
		rotate_right(data, -ROTATE_SPEED);
	else if (key == LEFT)
		rotate_right(data, ROTATE_SPEED);
	else if (key == A)
		move_left(data);
	else if (key == D)
		move_right(data);
	else if (key == W)
		move_up(data);
	else if (key == S)
		move_down(data);
	else if (key == ESC)
		ft_close(data);
	init_win(data);
	return (0);
}

int	ft_close(t_data *data)
{
	if (data->args)
		destroy_struct(data, data->args);
	system("leaks cub3d");
	exit (0);
}
