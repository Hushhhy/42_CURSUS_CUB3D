/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:22:44 by acarpent          #+#    #+#             */
/*   Updated: 2025/01/23 15:57:40 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int ac, char **av)
{
	t_game	game;

	ft_memset(&game, 0, sizeof(t_game));
	if (ac != 2)
		return (_error_msg("Usage", ERR_ARG, 1));
	_checkname(av[1]);
	if (!_getfile(&game, av[1]))
		return (_error_msg("Detail", ERR_GET_FILE, 1));
	_parse_file(&game);
	_init_mlx(&game);
	return (0);
}
