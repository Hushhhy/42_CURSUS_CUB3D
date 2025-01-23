/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:03:24 by acarpent          #+#    #+#             */
/*   Updated: 2024/12/16 15:09:29 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	_north_check(t_game *game, char *line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	if (!ft_strncmp(line, "NO ", 3))
	{
		i += 3;
		while (line[i] && (line[i] == ' ' || line[i] == '\t'))
			i++;
		if (!game->data.no_texture)
		{
			_check_texname(line, game);
			game->data.no_texture = _new_alloc(i, line);
			while (line[i] && (line[i] != ' ' && line[i] != '\t'))
				game->data.no_texture[j++] = line[i++];
			game->data.no_texture[j] = '\0';
		}
		else
			exit(_error_msg_free("Detail", ERR_NORTH, 1, game));
	}
}

void	_south_check(t_game *game, char *line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	if (!ft_strncmp(line, "SO ", 3))
	{
		i += 3;
		while (line[i] && (line[i] == ' ' || line[i] == '\t'))
			i++;
		if (!game->data.so_texture)
		{
			_check_texname(line, game);
			game->data.so_texture = _new_alloc(i, line);
			while (line[i] && (line[i] != ' ' && line[i] != '\t'))
				game->data.so_texture[j++] = line[i++];
			game->data.so_texture[j] = '\0';
		}
		else
			exit(_error_msg_free("Detail", ERR_SOUTH, 1, game));
	}
}

void	_east_check(t_game *game, char *line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	if (!ft_strncmp(line, "EA ", 3))
	{
		i += 3;
		while (line[i] && (line[i] == ' ' || line[i] == '\t'))
			i++;
		if (!game->data.ea_texture)
		{
			_check_texname(line, game);
			game->data.ea_texture = _new_alloc(i, line);
			while (line[i] && (line[i] != ' ' && line[i] != '\t'))
				game->data.ea_texture[j++] = line[i++];
			game->data.ea_texture[j] = '\0';
		}
		else
			exit(_error_msg_free("Detail", ERR_EAST, 1, game));
	}
}

void	_west_check(t_game *game, char *line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	if (!ft_strncmp(line, "WE ", 3))
	{
		i += 3;
		while (line[i] && (line[i] == ' ' || line[i] == '\t'))
			i++;
		if (!game->data.we_texture)
		{
			_check_texname(line, game);
			game->data.we_texture = _new_alloc(i, line);
			while (line[i] && (line[i] != ' ' && line[i] != '\t'))
				game->data.we_texture[j++] = line[i++];
			game->data.we_texture[j] = '\0';
		}
		else
			exit(_error_msg_free("Detail", ERR_WEST, 1, game));
	}
}
