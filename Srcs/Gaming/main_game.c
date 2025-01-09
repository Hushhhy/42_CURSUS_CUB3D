/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 13:30:33 by acarpent          #+#    #+#             */
/*   Updated: 2025/01/09 15:27:04 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	_game(t_game *game)
{
	_handle_move(game);
	mlx_destroy_image(game->mlx.mlx_ptr, game->mlx.img_ptr);
	game->mlx.img_ptr = mlx_new_image(game->mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	game->mlx.addr = mlx_get_data_addr(game->mlx.img_ptr,
			&game->mlx.bpp, &game->mlx.size_line,
			&game->mlx.endian);
	mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr,
			game->mlx.img_ptr, 0, 0);
	_render(game);
	return (0);	
}
