/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfoote <gfoote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 16:56:01 by swarner           #+#    #+#             */
/*   Updated: 2019/05/08 19:42:35 by gfoote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

static void		ft_strset(char *field, int c, int size)
{
	int i;
	int vertical;

	i = 0;
	vertical = 1;
	while (vertical <= (size+1)*size)
	{
		while (i < size * vertical)
			field[i++] = c;
		field[i++] = '\n';
		vertical++;
	}
}

char			*ft_field_for_tetri(int count, int step)
{
	int		i;
	int		field;
	char	*tetri_field;

	i = 0;
	i = count * 4;
	while(ft_sqrt(i)!=0)
		i++;
	field = ft_sqrt(i)+step;
	tetri_field = ft_strnew((field + 1)*field); //если шаг не один нужно стирать map
	ft_strset(tetri_field, '.', field);
	return (tetri_field);
}

void			ft_change_coordinates(int *coo)
{
	int	i;

	i = 0;
	while (i != 2)
	{
		if (coo[i] / 4 == 1)
			coo[i] += 1;
		if (coo[i] / 4 == 2)
			coo[i] += 2;
		if (coo[i] / 4 == 3)
			coo[i] += 3;
		i++;
	}
}
