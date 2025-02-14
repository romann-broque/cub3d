/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 13:50:14 by rbroque           #+#    #+#             */
/*   Updated: 2023/11/17 12:22:30 by jrouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	start_game(const char *const filename)
{
	char **const	content = get_file(filename);
	int				ret_val;
	t_win			window;

	if (content == NULL)
		return (EXIT_FAILURE);
	if (content != NULL && content[0] == NULL)
	{
		free_strs(content);
		print_format_error(EMPTY_FILE);
		return (EXIT_FAILURE);
	}
	ret_val = EXIT_FAILURE;
	init_window(&window, content);
	if (is_window_complete(&window) == true)
	{
		display_window(&window);
		ret_val = EXIT_SUCCESS;
	}
	free_window(&window);
	free_strs(content);
	return (ret_val);
}

int	main(int ac, char **av)
{
	int	ret_val;

	ret_val = EXIT_FAILURE;
	if (ac == EXPECTED_ARG_COUNT)
	{
		if (streq(av[1], HELP_KEYWORD1) || streq(av[1], HELP_KEYWORD2))
		{
			print_help();
			ret_val = EXIT_SUCCESS;
		}
		else
			ret_val = start_game(av[1]);
	}
	else
		print_format_error(ERROR_USAGE);
	return (ret_val);
}
