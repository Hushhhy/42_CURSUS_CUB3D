/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:48:48 by acarpent          #+#    #+#             */
/*   Updated: 2025/01/09 15:51:00 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void    dda(t_game *game, t_ray *ray)
{
    int hit;

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