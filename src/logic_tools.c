/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 16:56:01 by swarner           #+#    #+#             */
/*   Updated: 2019/04/25 16:56:02 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

static char		*ft_fill_map(char *map, int field_n, int field)
{
	int i;

	i = 0;
	while (i < field_n)
		map[i++] = '.';
	i = 0;
	while (i < field_n)
	{
		if (((i + 1) % (ft_sqrt(field) + 1) == 0))
			map[i] = '\n';
		i++;
	}
	return (map);
}

static int 		ft_field_check(t_dlist *val_list, int count)
{
	int *coo;
	t_dlist *listik;

	listik = val_list;
	while(listik)
	{
		coo = (int *) listik->content;
		if ((coo[1] == 1 && coo[2] == 2 && coo[3] == 3) || (coo[1] == 5 && coo[2] == 10 && coo[3] == 15))
			return (16);
		else if (coo[0] == 0 && coo[1] == 1 && coo[2] == 5 && coo[3] == 6 && count == 1)
			return (4);
		listik = listik->next;
	}
	return (9);
}

char			*ft_field_for_tetri(int count, int step, t_dlist *val_list) //a mojno prosto zavesti stati4eskyu peremennyu i yveli4ivat ee +1
{
	int		i;
	int		field;
	int		field_n;
	char	*tetri_field;

	field = 0;
	if (count < 3 && step == 0)
		field = ft_field_check(val_list, count);
	if(step == 0) {
		if (field == 0) {
			i = (count == 1) ? 1 : 0;
			while (ft_sqrt((count + step) * 4 + i) == 0)
				i++;
			field = ((count + step) * 4) + i;
		}
		field_n = field + ft_sqrt(field);
		tetri_field = ft_strnew(field_n);
	}
	else
	{
		field = (step * step);
		field_n = field + step;
		tetri_field = ft_strnew(field_n);
	}
	if (step == 0)
	{
		//printf("field = %i, step = %i\n", ft_sqrt(field), step);
		ft_change_coordinates(val_list, ft_sqrt(field), 4);
	}
	else {
		//printf("field = %i, step = %i\n", ft_sqrt(field), step);
		ft_change_coordinates(val_list, ft_sqrt(field), ft_sqrt(field) - 1);
	}return (ft_fill_map(tetri_field, field_n, field));
}

void ft_change_coordinates(t_dlist *val_list, int cur_size, int prev_size)
{
	int		i;
	int		*coo;
	t_dlist *current;
	int diff;

	i = 0;
	current = val_list;
	diff = cur_size - prev_size;
		while (current != NULL) {
			coo = (int *) current->content;
			if (diff == 2) {
				coo[2] = 3; //квадрат
				coo[3] = 4;
			} else if (diff > 0 ){
				i = 0;
				//printf("1 cur_size = %i, coo[0] = %i, coo[1] = %i, coo[2] = %i, coo[3] = %i\n", cur_size, coo[0],
				//	   coo[1], coo[2], coo[3]);
				while (i != 4) {
					if (coo[i] / cur_size == 1)
						coo[i] += diff;
					else if (coo[i] / cur_size == 2)
						coo[i] += 2 * diff;
					else if (coo[i] / cur_size == 3)
						coo[i] += 3 * diff;
					i++;
				}
				//printf("1 cur_size = %i, coo[0] = %i, coo[1] = %i, coo[2] = %i, coo[3] = %i\n", cur_size, coo[0],
				//	   coo[1], coo[2], coo[3]);
				current = current->next;
			}
			else {
				i = 0;
				//printf("1 cur_size = %i, coo[0] = %i, coo[1] = %i, coo[2] = %i, coo[3] = %i\n", cur_size, coo[0],
				//	   coo[1], coo[2], coo[3]);
				while (i != 4) {
					if (coo[i] / prev_size == 1)
						coo[i] += diff;
					else if (coo[i] / prev_size == 2)
						coo[i] += 2 * diff;
					else if (coo[i] / prev_size == 3)
						coo[i] += 3 * diff;
					i++;
				}
			//printf("1 cur_size = %i, coo[0] = %i, coo[1] = %i, coo[2] = %i, coo[3] = %i\n", cur_size, coo[0],
			//		   coo[1], coo[2], coo[3]);
				current = current->next;
			}
		}
	}