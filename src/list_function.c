/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfoote <gfoote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 16:51:49 by gfoote            #+#    #+#             */
/*   Updated: 2019/05/08 19:43:13 by gfoote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	ft_tetrhead_del(t_tetris **head)
{
	t_tetris *temp;

	temp = *head;
	*head = temp->next;
	free(temp);
}

void	ft_tetradd_end(t_tetris **val_list, t_tetris *new)
{
	t_tetris *current;

	current = *val_list;
	while (current->next != NULL)
		current = current->next;
	current->next = new;
	new->prev = current;
}

void	ft_addtetris(t_tetris **val_list, char *buffer, int size)
{
	t_tetris	*new;

	new = (t_tetris *)malloc(sizeof(t_tetris));
	new->content = ft_strdup(buffer);
	new->content_size = size;
	new->next = NULL;
	ft_tetradd_end(val_list, new);
	ft_strclr(buffer);
}

t_tetris	*ft_tetnew(void const *content, size_t content_size)
{
	t_tetris	*new;

	if (!(new = (t_tetris *)malloc(sizeof(t_tetris))))
		return (NULL);
	if (!(new->content = malloc(content_size)))
	{
		free(new);
		return (NULL);
	}
	if (!content || !content_size)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else
	{
		ft_memcpy(new->content, content, content_size);
		new->content_size = content_size;
	}
	new->next = NULL;
	new->prev = NULL;
	return (new);
}
