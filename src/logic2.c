/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfoote <gfoote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 17:57:22 by gfoote            #+#    #+#             */
/*   Updated: 2019/05/08 20:16:25 by gfoote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

static int		ft_add_tetri(char *map, t_tetris *current, int step)
{
	int			i;
	int			*a;

	i = step;
	while (map[i] != '.')
		i++;
	a = (int *)current->content;
	if ((i + a[0] < ft_strlen(map)) && (i + a[1] < ft_strlen(map))
		&& (i + a[2] < ft_strlen(map)) && (map[i + a[0]] == '.')
		&& (map[i + a[1]] == '.') && map[i + a[2] == '.'])
	{
		map[i] = current->content_size;
		map[i + a[0]] = current->content_size;
		map[i + a[1]] = current->content_size;
		map[i + a[2]] = current->content_size;
		return (i);
	}
	else
	{
		if (map[i + 1] == '\0')
			return (-1);
		else
			return (ft_add_tetri(map, current, i + 1));
	}
	return (-1);
} //проверить на segfault узнать где z

static int		ft_del_tetri(char *map, int letter)
{
	int			pos;
	int			i;
	int			check;

	i = 0;
	check = 0;
	while (map[i])
	{
		if (map[i] == letter)
		{
			if (check == 0)
				pos = i;
			check = 1;
			map[i] = '.';
		}
		i++;
	}
	return (pos);
}

int				ft_count(int len)
{
	while (ft_sqrt(len) == 0)
		len--;
	return (ft_sqrt(len));
}

int				ft_solve(char *map, t_tetris *current, int step)
{
	while (current)
	{
		step = ft_add_tetri(map, current, step);
		if (step != -1)
		{
			if (current->next)
				current = current->next;
			else
				return (1);
		}
		else
		{
			if (current->prev)
			{
				current = current->prev;
				step = (ft_del_tetri(map, current->content_size) + 1);
			}
			else
			{
				map = ft_field_for_tetri(ft_count(ft_strlen(map)), 1); //почистить map прежде
				return (ft_solve(map, current, 0));
			}
		}
	}
	return (0);
}
