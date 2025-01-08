/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:10:40 by acarpent          #+#    #+#             */
/*   Updated: 2025/01/08 13:28:29 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	_getmap(t_game *game, int i)
{
	int		start;
	int		k;
	char	*line;
	int		size;

	k = 0;
	start = _emptylines(game, i);
	size = _get_map_size(game, start) + 1;
	game->data.map = malloc(sizeof(char *) * (size + 1));
	if (!game->data.map)
		return ;
	while (game->data.file[start])
	{
		line = game->data.file[start];
		if (_line_empty(line))
			break ;
		game->data.map[k] = ft_strdup(line);
		if (!game->data.map[k])
			return ;
		start++;
		k++;
	}
	game->data.map[k] = NULL;
	_check_the_map(game);
}

int	_get_map_size(t_game *game, int i)
{
	int		size;
	int		start;
	char	**file;

	file = game->data.file;
	start = _emptylines(game, i) - 1;
	size = 0;
	while (file[start++])
		if (!_line_empty(file[start]))
			size++;
	return (size);
}

void	_map_realloc(t_game *game)
{
	char	*new;
	int		len;
	int		i;

	i = 0;
	while (game->data.map[i])
	{
		printf("%s", game->data.map[i]);
		i++;
	}
	i = 0;
	game->data.map_width = _get_map_width(game->data.map);
	while (game->data.map[i])
	{
		len = ft_strlen(game->data.map[i]);
		if (len < game->data.map_width)
		{
			new = malloc(game->data.map_width + 1);
			ft_strcpy(new, game->data.map[i]);
			ft_memset(new + len, '1', game->data.map_width - len);
			new[game->data.map_width] = '\0';
			free(game->data.map[i]);
			game->data.map[i] = new;
		}
		i++;
	}
}
