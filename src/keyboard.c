/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Verdoodt <Verdoodt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 12:16:59 by devoma            #+#    #+#             */
/*   Updated: 2023/05/28 11:37:26 by Verdoodt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	key_ft(int key, t_data *data)
{
	if (key == RIGHT)
		rotate_right(data, -ROTATE_SPEED);
	if (key == LEFT)
		rotate_right(data, ROTATE_SPEED);
	if (key == A)
		move_left(data);
	if (key == D)
		move_right(data);
	if (key == W)
		move_up(data);
	if (key == S)
		move_down(data);
	if (key == ESC)
		ft_close(key, data);
	init_win(data);
	return (0);
}

int	ft_close(int keycode, t_data *data)
{
	(void)keycode;
	(void)data;
	destroy_struct(data->args);.
	exit (0);
}
