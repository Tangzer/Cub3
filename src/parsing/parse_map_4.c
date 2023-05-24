/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Verdoodt <Verdoodt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 12:17:56 by devoma            #+#    #+#             */
/*   Updated: 2023/05/23 16:33:10 by Verdoodt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	*create_line(char *map_line, int j)
{
	int		malloc_count;
	int		new_i;
	char	*new_line;

	malloc_count = malloc_counting(map_line);
	new_i = 0;
	new_line = malloc(sizeof(char) * malloc_count);
	protect_malloc(new_line);
	while (map_line[j] && (map_line[j] == ' ' || map_line[j] == '\t'))
		j++;
	while (map_line[j])
	{
		if (!map_line[j])
		{
			new_line[new_i] = '\0';
			return (new_line);
		}
		new_line[new_i] = map_line[j];
		j++;
		new_i++;
		new_line[new_i] = '\0';
	}
	return (new_line);
}

int	check_line_f_c(char *line)
{
	int		i;
	int		index;

	i = 1;
	index = 0;
	if (check_full_num(line, &i, &index) == 0)
		return (0);
	if (check_semi(line, &i) == 0)
		return (0);
	if (check_full_num(line, &i, &index) == 0)
		return (0);
	if (check_semi(line, &i) == 0)
		return (0);
	if (check_full_num(line, &i, &index) == 0)
		return (0);
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int	check_semi(char *line, int *i)
{
	while (line[*i] && (line[*i] == ' ' || line[*i] == '\t'))
		(*i)++;
	if (line[*i] && line[*i] != ',')
		return (0);
	(*i)++;
	return (1);
}

int	check_full_num(char *line, int *i, int *index)
{
	char	*temp;

	while (line[*i] && (line[*i] == ' ' || line[*i] == '\t'))
		(*i)++;
	(*index) = (*i);
	while (line[*i] && ft_isdigit(line[*i]))
		(*i)++;
	if ((*i) - (*index) > 0)
	{
		temp = ft_substr(line, *index, (*i) - (*index));
		if (!temp || ft_atoi(temp) > 255 || ft_atoi(temp) < 0)
		{
			free(temp);
			return (0);
		}
		free(temp);
	}
	else
		return (0);
	return (1);
}
