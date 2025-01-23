/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:48:48 by acarpent          #+#    #+#             */
/*   Updated: 2025/01/23 16:10:06 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
	// ray->mapx = (int)game->player.pos.x;
	// ray->mapy = (int)game->player.pos.y;
	// if (ray->raydir.x == 0)
	// 	ray->deltaDist.x = 1e30;
	// else
	// 	ray->deltaDist.x = fabs(1 / ray->raydir.x);
	// if (ray->raydir.y == 0)
	// 	ray->deltaDist.y = 1e30;
	// else
	// 	ray->deltaDist.y = fabs(1 / ray->raydir.y);
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

void	calcul_ray(t_game *game, t_ray *ray, int x)
{
	double	camera;

	camera = 2 * x / (double)WIN_WIDTH - 1;
	ray->raydir.x = game->player.dir.x + game->player.plane.x * camera;
	// printf("raydir.x: %f\n", ray->raydir.x);
	ray->raydir.y = game->player.dir.y + game->player.plane.y * camera;
	// printf("raydir.y: %f\n", ray->raydir.y);
}

void	dda(t_game *game, t_ray *ray)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (ray->sidedist.x < ray->sidedist.y)
		{
			ray->sidedist.x += ray->deltaDist.x;
			ray->mapx += ray->stepx;
			ray->side = 0;
		}
		else
		{
			ray->sidedist.y += ray->deltaDist.y;
			ray->mapy += ray->stepy;
			ray->side = 1;
		}
		if (game->data.map_int[ray->mapx][ray->mapy] == 1)
		{
			hit = 1;
			break ;
		}
	}
}
