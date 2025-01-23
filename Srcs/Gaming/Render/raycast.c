/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 15:21:03 by acarpent          #+#    #+#             */
/*   Updated: 2025/01/23 16:05:53 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	calculate_texture_coords(t_ray ray, t_game *game, double *wall_x,
		int *tex_x)
{
	if (ray.side == 0)
		*wall_x = game->player.pos.y + ray.perp_walldist * ray.raydir.y;
	else
		*wall_x = game->player.pos.x + ray.perp_walldist * ray.raydir.x;
	*wall_x -= floor(*wall_x);
	*tex_x = (int)(*wall_x * TEXTURE_WIDTH);
	if (ray.side == 0 && ray.raydir.x < 0)
		*tex_x = TEXTURE_WIDTH - *tex_x - 1;
	if (ray.side == 1 && ray.raydir.y < 0)
		*tex_x = TEXTURE_WIDTH - *tex_x - 1;
}

t_img	*select_texture(t_ray ray, t_game *game)
{
	if (ray.side == 0)
	{
		if (ray.raydir.x > 0)
			return (&game->text[3]);
		return (&game->text[2]);
	}
	if (ray.raydir.y > 0)
		return (&game->text[1]);
	return (&game->text[0]);
}

void	draw_walls(int x, t_ray ray, t_game *game)
{
	t_img	*texture;

	if (ray.start < 0)
		ray.start = 0;
	if (ray.end >= WIN_HEIGHT)
		ray.end = WIN_HEIGHT - 1;
	calculate_texture_coords(ray, game, &game->text->wall_x, &game->text->tex_x);
	texture = select_texture(ray, game);
	game->text->step = (double)TEXTURE_HEIGHT / ray.lineheight;
	game->text->tex_pos = (ray.start - WIN_HEIGHT / 2 + ray.lineheight / 2)
		* game->text->step;
	game->data.y = ray.start;
	while (game->data.y <= ray.end)
	{
		if (game->text->tex_pos >= TEXTURE_HEIGHT)
			game->text->tex_y = (int)(game->text->tex_pos) % TEXTURE_HEIGHT;
		else
			game->text->tex_y = (int)(game->text->tex_pos);
		game->text->tex_pos += game->text->step;
		game->text->color = get_texture_color(texture, game->text->tex_x,
				game->text->tex_y);
		if (my_mlx_pixel_put(game, x, game->data.y, game->text->color))
			return ;
		game->data.y++;
	}
}

double	_calculate_perp_wall_dist(t_game *game, t_ray ray)
{
	if (ray.side == 0)
		return ((ray.mapx - game->player.pos.x + (1 - ray.stepx) / 2)
			/ ray.raydir.x);
	return ((ray.mapy - game->player.pos.y + (1 - ray.stepy) / 2)
		/ ray.raydir.y);
}

int get_wall_color(t_ray ray) 
{
    int color;
	color = 0;
    if (ray.side == 0) 
    {
        if (ray.raydir.x < 0)
            color = 0xFF0000;    // Rouge // Mur à ouest
        else if (ray.raydir.x > 0)
            color = 0x00FF00;    // Vert // Mur à est
    }
    else
    {
        if (ray.raydir.y < 0)
            color = 0x0000FF;    // Bleu // Mur au Nord
        else
            color = 0xFFFFFF;    // Blanc // Mur au Sud
    }
    return (color);
}

void draw_vert_line(t_game *game, int x, int start, int end, int color) {
    int y;

    if (start < 0)
        start = 0;
    if (end >= WIN_HEIGHT)
        end = WIN_HEIGHT - 1;
    y = start;
    while (y <= end) {
        my_mlx_pixel_put(game, x, y, color);
        y++;
    }
}

void	_render(t_game *game)
{
	int		x;
	t_ray	ray;
	int	color;

	x = 0;
	draw_floor_ceiling(game);
	while (x < WIN_WIDTH)
	{
		calcul_ray(game, &ray, x);
		_calculate_step(game, &ray);
		dda(game, &ray);
		ray.perp_walldist = _calculate_perp_wall_dist(game, ray);
		ray.lineheight = (int)(WIN_HEIGHT / ray.perp_walldist);
		ray.start = -ray.lineheight / 2 + WIN_HEIGHT / 2;
		ray.end = ray.lineheight / 2 + WIN_HEIGHT / 2;
		// draw_walls(x, ray, game);
		color = get_wall_color(game->ray);
		draw_vert_line(game, x, ray.start, ray.end, color);
		x++;
	}
}

