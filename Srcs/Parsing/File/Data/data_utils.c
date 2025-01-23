/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:12:43 by acarpent          #+#    #+#             */
/*   Updated: 2024/12/11 13:12:56 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	*_new_alloc(int start, char *line)
{
	int		i;
	int		end;
	char	*tmp;

	i = start;
	while (line[i] && (line[i] != ' ' && line[i] != '\t'))
		i++;
	end = i - start;
	tmp = malloc(sizeof(char) * (end + 1));
	if (!tmp)
		return (NULL);
	return (tmp);
}
