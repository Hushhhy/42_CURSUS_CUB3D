/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:22:38 by acarpent          #+#    #+#             */
/*   Updated: 2025/01/09 14:05:09 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	_data_init(t_game *game)
{
	game->data.file = NULL;
	game->data.fd = -1;
	game->data.no_texture = NULL;
	game->data.so_texture = NULL;
	game->data.we_texture = NULL;
	game->data.ea_texture = NULL;
	game->data.floor_color = NULL;
	game->data.ceiling_color = NULL;
	game->data.ceiling_rgb = -1;
	game->data.floor_rgb = -1;
	game->data.map = NULL;
	game->data.map_width = -1;
	game->data.map_height = -1;
	_player_init(game);
}

void	_player_init(t_game *game)
{
	game->player.p_count = 0;
	_ray_init(game);
}

void	_ray_init(t_game *game)
{
	game->ray.stepx = -1;
	game->ray.stepy = -1;
	game->ray.side = -1;
	game->ray.lineheight = -1;
	game->ray.start = -1;
	game->ray.end = -1;
	game->ray.color = -1;
	game->ray.mapx = -1;
	game->ray.mapy = -1;
	game->ray.perp_walldist = -1;
	game->ray.raydir.x = -1;
	game->ray.raydir.y = -1;
	game->ray.sidedist.x = -1;
	game->ray.sidedist.y = -1;
	game->ray.deltaDist.x = -1;
	game->ray.deltaDist.y = -1;
	_mlx_struct_init(game);
}

void	_mlx_struct_init(t_game *game)
{
	game->mlx.mlx_ptr = NULL;
	game->mlx.win_ptr = NULL;
	game->mlx.img_ptr = NULL;
	game->mlx.img_data = NULL;
	game->mlx.addr = NULL;
	game->mlx.bpp = -1;
	game->mlx.size_line = -1;
	game->mlx.endian = -1;
}
