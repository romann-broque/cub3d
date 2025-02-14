/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:56:34 by rbroque           #+#    #+#             */
/*   Updated: 2023/11/16 12:14:08 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	square_dist(const t_pos *const pos1, const t_pos *const pos2)
{
	const double	dx = pos1->x - pos2->x;
	const double	dy = pos1->y - pos2->y;

	return (dx * dx + dy * dy);
}
