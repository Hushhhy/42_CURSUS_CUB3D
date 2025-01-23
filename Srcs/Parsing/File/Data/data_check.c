/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:59:08 by acarpent          #+#    #+#             */
/*   Updated: 2024/12/16 15:24:11 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	_parse_color_val(char *line, int *i, t_game *game)
{
	int	val;

	while (line[*i] && (line[*i] == ' ' || line[*i] == '\t'))
		(*i)++;
	if (!ft_isdigit(line[*i]))
		_error_msg_free("Error", ERR_COLOR_FORMAT, 1, game);
	val = 0;
	while (line[*i] && ft_isdigit(line[*i]))
	{
		val = val * 10 + (line[*i] - '0');
		(*i)++;
	}
	if (val < 0 || val > 255)
		_error_msg_free("Error", ERR_COLOR_RANGE, 1, game);
	while (line[*i] && (line[*i] == ' ' || line[*i] == '\t'))
		(*i)++;
	if (line[*i] == ',')
	(*i)++;
	return (val);
}

void	_check_texname(char *name, t_game *game)
{
	char	*ext;

	ext = ft_strchr(name, '.');
	if (ft_strncmp(ext, ".xpm ", 5) && ft_strncmp(ext, ".xpm\t", 5)
		&& ft_strncmp(ext, ".xpm\n", 5) && ft_strncmp(ext, ".xpm\0", 5))
	{
		ft_free(game->data.file);
		_free_texture(game->data.no_texture, game->data.so_texture,
			game->data.ea_texture, game->data.we_texture);
		_free_colors(game->data.ceiling_color, game->data.floor_color);
		exit(_error_msg("Texture", ERR_XPM, 1));
	}
}

void	_get_ceiling(char *color, t_game *game)
{
	int	r;
	int	g;
	int	b;
	int	i;

	i = 1;
	_coma_check(color, game);
	r = _parse_color_val(color, &i, game);
	g = _parse_color_val(color, &i, game);
	b = _parse_color_val(color, &i, game);
	if (color[i] != '\n' && color[i] != '\0')
		_error_msg_free("Error", ERR_COLOR_FORMAT, 1, game);
	game->data.ceiling_rgb = (r << 16) + (g << 8) + b;
}

void	_get_floor(char *color, t_game *game)
{
	int	r;
	int	g;
	int	b;
	int	i;

	i = 1;
	_coma_check(color, game);
	r = _parse_color_val(color, &i, game);
	g = _parse_color_val(color, &i, game);
	b = _parse_color_val(color, &i, game);
	if (color[i] != '\n' && color[i] != '\0')
		_error_msg_free("Error", ERR_COLOR_FORMAT, 1, game);
	game->data.floor_rgb = (r << 16) + (g << 8) + b;
}

void	_coma_check(char *color, t_game *game)
{
	int	coma;
	int	i;

	coma = 0;
	i = 0;
	while (color[i])
	{
		if (color[i] == ',')
			coma++;
		i++;
	}
	if (coma != 2)
		_error_msg_free("Error", ERR_COMA, 1, game);
}
