/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Verdoodt <Verdoodt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 12:18:59 by devoma            #+#    #+#             */
/*   Updated: 2023/05/29 18:02:46 by Verdoodt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_matrix	*create_struct(char **map)
{
	t_matrix	*args;
	char		**temp_floor;
	char		**temp_ceiling;

	args = malloc(sizeof(t_matrix));
	protect_malloc(args);
	args->north = get_arguments(map, 'N', 2, args->north);
	args->south = get_arguments(map, 'S', 2, args->south);
	args->west = get_arguments(map, 'W', 2, args->west);
	args->east = get_arguments(map, 'E', 2, args->east);
	args->floor = get_arguments(map, 'F', 1, args->floor);
	args->ceiling = get_arguments(map, 'C', 1, args->ceiling);
	temp_floor = ft_split(args->floor, ',');
	args->f1 = ft_atoi(temp_floor[0]);
	args->f2 = ft_atoi(temp_floor[1]);
	args->f3 = ft_atoi(temp_floor[2]);
	free_map(temp_floor);
	temp_ceiling = ft_split(args->ceiling, ',');
	args->c1 = ft_atoi(temp_ceiling[0]);
	args->c2 = ft_atoi(temp_ceiling[1]);
	args->c3 = ft_atoi(temp_ceiling[2]);
	free_map(temp_ceiling);
	args->map = get_map(map, args->map);
	free_map(map);
	return (args);
}

void	destroy_struct(t_data *data, t_matrix *args)
{
	(void)data;
	if (args->north)
		free(args->north);
	if (args->south)
		free(args->south);
	if (args->west)
		free(args->west);
	if (args->east)
		free(args->east);
	if (args->floor)
		free(args->floor);
	if (args->ceiling)
		free(args->ceiling);
	if (data->img)
		free(data->img);
	if (data->rcasting)
		free(data->rcasting);
	if (args->map)
		free_map(args->map);
}
