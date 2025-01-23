/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:29:04 by acarpent          #+#    #+#             */
/*   Updated: 2024/12/13 15:31:39 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

//Close and exit game file

// int	_close_game(t_game *game)
// {
// 	_del_img(game);
// 	if (game->mlx.win_ptr)
// 		mlx_destroy_window(game->mlx.mlx_ptr, game->mlx.win_ptr);
// 	mlx_destroy_display(game->mlx.mlx_ptr);
// 	_has_to_free(game);
// 	exit(0);
// }