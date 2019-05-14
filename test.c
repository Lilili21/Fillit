#include <stdlib.h>
#include <stdio.h>

static void	ft_move(int *coo)
{
	int		i;
	int		check;

	i = -1;
	check = 0;
	while (++i != 4)
		if (coo[i] % 5 > 0)
			check++;
	if (check == 4)
	{
		i = 0;
		while (i != 4)
			coo[i++] -= 1;
		ft_move(coo);
	}
}

int			*ft_tetri_to_coo(char *buffer)
{
	int		i;
	int		g;
	int		level;
	int		*coo;
	int		step;

	i = -1;
	level = 0;
	g = 0;
	coo = (int *)malloc(4 * sizeof(int));
	while (buffer[++i] != '\0' && g != 4)
	{
		if (buffer[i] == '#')
		{
			if (g == 0)
				coo[g++] = i % 5;
			else
				coo[g++] = (i / 5 > level) ? i % 5 + 5 *
						(++step) : i % 5 + 5 * step;
			level = i / 5;
		}
	}
	ft_move(coo);
	free(buffer);
	return (coo);
}
