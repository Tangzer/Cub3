/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Verdoodt <Verdoodt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 12:18:53 by devoma            #+#    #+#             */
/*   Updated: 2023/05/23 16:30:50 by Verdoodt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	char_count(char *s, char c)
{
	int	count;
	int	i;
	int	len;

	i = 0;
	count = 1;
	len = ft_strlen(s) - 1;
	while (s[i] && s[i] == c)
		i++;
	while (s[len] && s[len] == c && i < len)
		len--;
	if (i == ft_strlen(s))
		return (0);
	while (s[i] && i < len)
	{
		if (s[i] == c && s[i - 1] != c)
			count++;
		i++;
	}
	return (count);
}

char	*create_word(char *s, int start, int len)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc(sizeof(char) * (len + 1));
	protect_malloc(word);
	while (i < len)
	{
		word[i] = s[start + i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *s, char c)
{
	int		start;
	int		end;
	int		i;
	int		quantity;
	char	**result;

	start = 0;
	i = 0;
	quantity = char_count(s, c);
	result = malloc(sizeof(char *) * (quantity + 1));
	if (!s || !result)
		return (NULL);
	while (i < quantity)
	{
		while (s[start] && s[start] == c)
			start++;
		end = start;
		while (s[end] && s[end] != c)
			end++;
		result[i] = create_word(s, start, end - start);
		start = end;
		i++;
	}
	result[i] = NULL;
	return (result);
}
