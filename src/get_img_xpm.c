/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_img_xpm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Verdoodt <Verdoodt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 12:17:19 by devoma            #+#    #+#             */
/*   Updated: 2023/05/19 13:16:40 by Verdoodt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	get_img_xpm(t_data *data)
{
	data->game->no = mlx_xpm_file_to_image(data->game->mlx,
			data->args->north, &data->img[1].width,
			&data->img[1].height);
	data->game->so = mlx_xpm_file_to_image(data->game->mlx,
			data->args->south, &data->img[2].width,
			&data->img[2].height);
	data->game->ea = mlx_xpm_file_to_image(data->game->mlx,
			data->args->east, &data->img[3].width,
			&data->img[3].height);
	data->game->we = mlx_xpm_file_to_image(data->game->mlx,
			data->args->west, &data->img[4].width,
			&data->img[4].height);
	if (!data->game->no || !data->game->so || !data->game->ea
		|| !data->game->we)
	{
		write(2, "No such path\n", 13);
		exit(1);
	}
}
