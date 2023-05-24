/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Verdoodt <Verdoodt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 12:17:30 by devoma            #+#    #+#             */
/*   Updated: 2023/05/19 13:16:40 by Verdoodt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	rotate_right(t_data *data, double rotate)
{
	double	old_pos;

	old_pos = data->rcasting->dirx;
	data->rcasting->dirx = old_pos * cos(rotate) - data->rcasting->diry * \
	sin(rotate);
	data->rcasting->diry = old_pos * sin(rotate) + data->rcasting->diry * \
	cos(rotate);
	old_pos = data->rcasting->planex;
	data->rcasting->planex = old_pos * cos(rotate) - data->rcasting->planey * \
	sin(rotate);
	data->rcasting->planey = old_pos * sin(rotate) + data->rcasting->planey * \
	cos(rotate);
}

void	move_left(t_data *data)
{
	int	x;
	int	y;

	x = (int)(data->rcasting->posx - data->rcasting->planex * \
	(MOVE_SPEED + 0.1));
	y = (int)data->rcasting->posy;
	if (data->args->map[x][y] == '0')
		data->rcasting->posx -= data->rcasting->planex * MOVE_SPEED;
	x = (int)data->rcasting->posx;
	y = (int)(data->rcasting->posy - data->rcasting->planey * \
	(MOVE_SPEED + 0.1));
	if (data->args->map[x][y] == '0')
		data->rcasting->posy -= data->rcasting->planey * MOVE_SPEED;
}

void	move_right(t_data *data)
{
	int	x;
	int	y;

	x = (int)(data->rcasting->posx + data->rcasting->planex * \
	(MOVE_SPEED + 0.1));
	y = (int)data->rcasting->posy;
	if (data->args->map[x][y] == '0')
		data->rcasting->posx += data->rcasting->planex * MOVE_SPEED;
	x = (int)data->rcasting->posx;
	y = (int)(data->rcasting->posy + data->rcasting->planey * \
	(MOVE_SPEED + 0.1));
	if (data->args->map[x][y] == '0')
		data->rcasting->posy += data->rcasting->planey * MOVE_SPEED;
}

void	move_up(t_data *data)
{
	int	x;
	int	y;

	x = (int)(data->rcasting->posx + data->rcasting->dirx * (MOVE_SPEED + 0.1));
	y = (int)data->rcasting->posy;
	if (data->args->map[x][y] == '0')
		data->rcasting->posx += data->rcasting->dirx * MOVE_SPEED;
	x = (int)data->rcasting->posx;
	y = (int)(data->rcasting->posy + data->rcasting->diry * (MOVE_SPEED + 0.1));
	if (data->args->map[x][y] == '0')
		data->rcasting->posy += data->rcasting->diry * MOVE_SPEED;
}

void	move_down(t_data *data)
{
	int	x;
	int	y;

	x = (int)(data->rcasting->posx - data->rcasting->dirx * (MOVE_SPEED + 0.1));
	y = (int)data->rcasting->posy;
	if (data->args->map[x][y] == '0')
		data->rcasting->posx -= data->rcasting->dirx * MOVE_SPEED;
	x = (int)data->rcasting->posx;
	y = (int)(data->rcasting->posy - data->rcasting->diry * (MOVE_SPEED + 0.1));
	if (data->args->map[x][y] == '0')
		data->rcasting->posy -= data->rcasting->diry * MOVE_SPEED;
}
