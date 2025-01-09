/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 15:21:03 by acarpent          #+#    #+#             */
/*   Updated: 2025/01/09 16:00:03 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	_render(t_game *game)
{
	int		x;
	t_ray	ray;

	x = 0;
	draw_floor_ceiling(game);
	while (x < WIN_WIDTH)
	{
		_init_ray(game, &ray, x);
		_calculate_step(game, &ray);
		dda(game, &ray);
		ray.perp_walldist = _calculate_perp_wall_dist(game, ray);
		ray.lineheight = (int)(WIN_HEIGHT / ray.perp_walldist);
		ray.start = -ray.lineheight / 2 + WIN_HEIGHT / 2;
		ray.end = ray.lineheight / 2 + WIN_HEIGHT / 2;
		_draw_wall(game, ray, x);
		x++;
	}
}

void	draw_wall(t_game *game, t_ray ray, int x)
{
	if (ray.start < 0)
		ray.start = 0;
	if (ray.end >= WIN_HEIGHT)
		ray.end = WIN_HEIGHT - 1;
}

double	_calculate_perp_wall_dist(t_game *game, t_ray ray)
{
	if (ray.side == 0)
		return ((ray.mapx - game->player.pos.x + (1 - ray.stepx) / 2)
			/ ray.raydir.x);
	return ((ray.mapy - game->player.pos.y + (1 - ray.stepy) / 2)
		/ ray.raydir.y);
}

void	init_ray_delta(t_ray *ray, t_game *game)
{
	ray->mapx = (int)game->player.pos.x;
	ray->mapy = (int)game->player.pos.y;
	if (ray->raydir.y == 0)
		ray->deltaDist.x = 1e30;
	else
		ray->deltaDist.x = fabs(1 / ray->raydir.x);
	if (ray->raydir.x == 0)
		ray->deltaDist.y = 1e30;
	else
		ray->deltaDist.y = fabs(1 / ray->raydir.y);
	ray->mapx = (int)game->player.pos.x;
	ray->mapy = (int)game->player.pos.y;
	if (ray->raydir.x == 0)
		ray->deltaDist.x = 1e30;
	else
		ray->deltaDist.x = fabs(1 / ray->raydir.x);
	if (ray->raydir.y == 0)
		ray->deltaDist.y = 1e30;
	else
		ray->deltaDist.y = fabs(1 / ray->raydir.y);
}

void	_calculate_step(t_game *game, t_ray *ray)
{
	init_ray_delta(ray, game);
	if (ray->raydir.x < 0)
	{
		ray->stepx = -1;
		ray->sidedist.x = (game->player.pos.x - ray->mapx) * ray->deltaDist.x;
	}
	else
	{
		ray->stepx = 1;
		ray->sidedist.x = (ray->mapx + 1.0 - game->player.pos.x)
			* ray->deltaDist.x;
	}
	if (ray->raydir.y < 0)
	{
		ray->stepy = -1;
		ray->sidedist.y = (game->player.pos.y - ray->mapy) * ray->deltaDist.y;
	}
	else
	{
		ray->stepy = 1;
		ray->sidedist.y = (ray->mapy + 1.0 - game->player.pos.y)
			* ray->deltaDist.y;
	}
}

void	draw_floor_ceiling(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			if (y < WIN_HEIGHT / 2)
				my_mlx_pixel_put(game, x, y, game->data.ceiling_rgb);
			else
				my_mlx_pixel_put(game, x, y, game->data.floor_rgb);
			x++;
		}
	}
}

void	_init_ray(t_game *game, t_ray *ray, int x)
{
	double	camera;

	camera = 2 * x / (double)WIN_WIDTH - 1;
	ray->raydir.x = game->player.dir.x + game->player.plane.x * camera;
	ray->raydir.y = game->player.dir.y + game->player.plane.y * camera;
}

