/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gaming.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <pgrellie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:13:33 by acarpent          #+#    #+#             */
/*   Updated: 2025/01/15 16:59:40 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// ADD Key to move and exit game
// CF mon so_long

int	_key_press(int key, t_game *game)
{
	if (key == ESC)
		_close_game(game);
	if (key == KEY_W || key == UP)
		move_up(game);
	if (key == KEY_S || key == DOWN)
		move_down(game);
	if (key == KEY_A || key == LEFT)
		move_left(game);
	if (key == KEY_D || key == RIGHT)
		move_right(game);
	return (0);
}
