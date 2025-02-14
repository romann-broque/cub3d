/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 07:44:26 by rbroque           #+#    #+#             */
/*   Updated: 2023/11/09 14:36:47 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	display_player_on_map(t_win *const window)
{
	const t_pos *const	player_pos = &(window->map->player.pos);

	draw_square_on_map(window, player_pos, PLAYER_SIZE, RED);
}

static void	display_player_on_minimap(t_win *const window)
{
	const t_pos *const	player_pos = &(window->map->player.pos);

	draw_square_on_minimap(window, player_pos, PLAYER_SIZE, RED);
}

void	display_player(t_win *const window)
{
	if (window->mod == E_STD)
		display_player_on_minimap(window);
	else if (window->mod == E_MAP)
		display_player_on_map(window);
}
