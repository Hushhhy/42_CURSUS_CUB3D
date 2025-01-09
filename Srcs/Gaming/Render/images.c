/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 15:40:38 by acarpent          #+#    #+#             */
/*   Updated: 2025/01/09 13:59:53 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	my_mlx_pixel_put(t_game *game, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < game->data.map_width && y >= 0 && y < game->data.map_height)
	{
		dst = game->mlx.addr + (y * game->mlx.size_line + x
				* (game->mlx.bpp / 8));
		*(unsigned int *)dst = color;
	}
}
