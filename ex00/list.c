/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mharribe <mharribe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 12:05:43 by arsaulni          #+#    #+#             */
/*   Updated: 2026/08/30 17:45:17 by mharribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdlib.h>

void	free_list(t_list *elem)
{
	free(elem->key);
	free(elem->value);
	if (elem->next)
		free_list(elem->next);
	if (elem->previous)
		elem->previous->next = 0;
	free(elem);
}

t_list	*add_elem(t_list *elem, char *key, char *value)
{
	t_list	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return (0);
	new->previous = elem;
	new->next = 0;
	new->key = key;
	new->value = value;
	return (new);
}
