/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:07:23 by acarpent          #+#    #+#             */
/*   Updated: 2025/01/07 13:33:47 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	_init_mlx(t_game *game)
{
	game->mlx.mlx_ptr = mlx_init();
	if (!game->mlx.mlx_ptr)
		exit(_error_msg_free("mlx", ERR_MLX_INIT, 1, game));
	game->mlx.win_ptr = mlx_new_window(game->mlx.mlx_ptr,
			WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	if (!game->mlx.win_ptr)
		exit(_error_msg_free("mlx", ERR_MLX_WIN, 1, game));
	game->data.img = mlx_new_image(game->mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	game->data.addr = mlx_get_data_addr(game->data.img,
			&game->data.bits_per_pixel, &game->data.line_length,
			&game->data.endian);
	my_mlx_pixel_put(&game->data, 100, 100, 0x00FF0000);
	mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr,
		game->data.img, 0, 0);
	mlx_hook(game->mlx.win_ptr, 2, 1L << 0, _key_press, game);
	mlx_loop(game->mlx.mlx_ptr);
	return ;
}
