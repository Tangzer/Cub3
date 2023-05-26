/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Verdoodt <Verdoodt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 12:16:37 by devoma            #+#    #+#             */
/*   Updated: 2023/05/26 16:52:53 by Verdoodt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	*get_arguments(char **map, char id, int num)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] && (map[i][j] == ' ' || map[i][j] == '\t'))
			j++;
		if (map[i][j] && map[i][j] == id)
			return (path(map[i], num));
		i++;
	}
	return (NULL);
}

int	map_malloc_count(char **map)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (is_id(map[i], 0) || is_empty_str(map[i]))
		i++;
	while (map[i])
	{
		count++;
		i++;
	}
	return (count + 1);
}

char	**get_map(char	**map)
{
	int		i;
	int		j;
	int		count;
	char	**new_map;

	i = 0;
	j = 0;
	count = map_malloc_count(map);
	new_map = malloc(sizeof(char *) * count);
	protect_malloc(new_map);
	while (is_id(map[i], 0) || is_empty_str(map[i]))
		i++;
	while (map[i])
	{
		new_map[j] = map[i];
		i++;
		j++;
	}
	new_map[j] = NULL;
// Amo --> techniquement on doit free 'map' sauf que ça bug 1/3 qd on le fait... Pourtant je ne vois nul par d'autre
// ou on reutilise 'map' .... ??? 
//	free_map(map);
//
	return (new_map);
}

int	malloc_count(char *line)
{
	int		i;
	int		count;

	i = -1;
	count = 0;
	while (line[++i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
			count++;
	}
	return (count);
}

char	*path(char *line, int num)
{
	int		i;
	int		count;
	char	*path;

	i = 0;
	count = malloc_count(line) + 1;
	path = malloc(sizeof(char) * count);
	protect_malloc(path);
	count = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	i += num;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
		{
			path[count] = line[i];
			count++;
		}
		i++;
	}
	path[count] = '\0';
	return (path);
}
