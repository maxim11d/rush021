/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsaulni <arsaulni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 20:07:42 by arsaulni          #+#    #+#             */
/*   Updated: 2026/08/30 13:56:53 by arsaulni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

typedef struct t_list
{
	struct t_list	*previous;
	struct t_list	*next;
	char			*key;
	char			*value;
}	t_list;

void	free_list(t_list *elem);
t_list	*add_elem(t_list *elem, char *key, char *value);

#endif
