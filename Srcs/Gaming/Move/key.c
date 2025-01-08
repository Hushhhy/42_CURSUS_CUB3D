/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:13:33 by acarpent          #+#    #+#             */
/*   Updated: 2024/12/23 15:10:09 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// ADD Key to move and exit game
// CF mon so_long

int	_key_press(int key, t_game *game)
{
	if (key == KEY_ESC)
		_close_game(game);
	// if (key == KEY_W || key == KEY_UP)
	// 	move_up(game);
	// if (key == KEY_S || key == KEY_DOWN)
	// 	move_down(game);
	// if (key == KEY_A || key == KEY_LEFT)
	// 	move_left(game);
	// if (key == KEY_D || key == KEY_RIGHT)
	// 	move_right(game);
	return (0);
}
