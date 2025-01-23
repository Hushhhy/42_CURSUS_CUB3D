/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:04:23 by codespace         #+#    #+#             */
/*   Updated: 2024/12/16 15:43:10 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	_has_to_free(t_game *game)
{
	_free_texture(game->data.no_texture, game->data.so_texture,
		game->data.ea_texture, game->data.we_texture);
	_free_colors(game->data.ceiling_color, game->data.floor_color);
	if (game->data.file)
		ft_free(game->data.file);
	if (game->data.map)
		ft_free(game->data.map);
}

void	_free_colors(char *ceiling, char *floor)
{
	if (ceiling)
		free(ceiling);
	if (floor)
		free(floor);
}

void	_free_texture(char *no, char *so, char *ea, char *we)
{
	if (no)
		free(no);
	if (so)
		free(so);
	if (ea)
		free(ea);
	if (we)
		free(we);
}
