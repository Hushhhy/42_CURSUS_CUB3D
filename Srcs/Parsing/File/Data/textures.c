/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <pgrellie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:57:41 by pgrellie          #+#    #+#             */
/*   Updated: 2025/01/14 17:58:58 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	load_text(t_game *game, t_img *text, char *path)
{
	text->img = mlx_xpm_file_to_image(game->mlx, path, &text->width,
			&text->height);
	if (text->img == NULL)
		return (1);
	text->addr = mlx_get_data_addr(text->img, &text->bits_per_pixel,
			&text->line_length, &text->endian);
	if (text->addr == NULL)
		return (1);
	return (0);
}

int	init_data(t_game *game)
{
	if (load_text(game, &game->text[0], game->data.no_texture))
		return (1);
	if (load_text(game, &game->text[1], game->data.so_texture))
		return (1);
	if (load_text(game, &game->text[2], game->data.we_texture))
		return (1);
	if (load_text(game, &game->text[3], game->data.ea_texture))
		return (1);
	return (0);
}

void	free_text(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (game->text[i].img)
			mlx_destroy_image(game->mlx, game->text[i].img);
		i++;
	}
}
