/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfoote <gfoote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 16:55:19 by swarner           #+#    #+#             */
/*   Updated: 2019/05/08 19:09:57 by gfoote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		main(int argc, char **argv)
{
	int		valid_tetri;
	t_tetris	*val_list;

	if (argc == 2)
	{
		val_list = ft_tetnew(NULL, 0);
		valid_tetri = ft_open_and_validation(argv[1], val_list);
		ft_putstr(ft_field_for_tetri(valid_tetri, 0));
	}
	else
		ft_putendl("usage: ./fillit [file]");
}
