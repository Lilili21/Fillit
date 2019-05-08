/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfoote <gfoote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 21:50:36 by swarner           #+#    #+#             */
/*   Updated: 2019/05/08 19:46:02 by gfoote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H

# define FILLIT_H

# include <fcntl.h>
# include "libft.h"

typedef struct		s_tetris
{
	void			*content;
	size_t			content_size;
	struct s_tetris	*next;
	struct s_tetris	*prev;
}					t_tetris;

int					ft_main_validation(t_tetris *val_list);
void				ft_check_spaces(char	*buffer);
void				ft_check_spaces_last(char	*buffer);
void				ft_count_and_check_symbols(char *buffer);
int					ft_open_and_validation(char *arg, t_tetris *val_list);
void				ft_error(void);
int					ft_sqrt(int nb);
void				ft_check_tetri(char *buffer);
int					*ft_tetri_to_coo(char *buffer);
char				*ft_field_for_tetri(int	count, int step);
void				ft_change_coordinates(int *coo);
void				ft_tetrhead_del(t_tetris **head);
void				ft_tetradd_end(t_tetris **val_list, t_tetris *new);
void				ft_addtetris(t_tetris **val_list, char *buffer, int size);
t_tetris			*ft_tetnew(void const *content, size_t content_size);
#endif
