/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mharribe <mharribe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 11:09:14 by arsaulni          #+#    #+#             */
/*   Updated: 2026/08/30 19:25:11 by mharribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "list.h"
#include "string.h"

t_list	*add_elem(t_list *elem, char *key, char *value);
char	*ft_strndup(char *src, int n);
char	*del_space(char *str);
int		ft_strlen(char *str);

char	*extract_key(char **str)
{
	char	*start;
	char	*key;

	start = *str;
	while (**str >= '0' && **str <= '9')
		(*str)++;
	if (*str == start)
		return (0);
	key = ft_strndup(start, *str - start);
	if (!key)
	{
		free(key);
		return (0);
	}
	if (*key == '0' && ft_strlen(key) > 1)
	{
		free(key);
		return (0);
	}
	while (**str == ' ')
		(*str)++;
	return (key);
}

char	*extract_value(char **str, int *len)
{
	int	i;
	int	end;

	while (**str == ' ')
		(*str)++;
	i = 0;
	while ((*str)[i] && (*str)[i] != '\n')
	{
		if ((*str)[i] < 32 || (*str)[i] > 126)
			return (0);
		i++;
	}
	*len = i;
	if ((*str)[i] == '\n')
		*len = i + 1;
	end = i - 1;
	while (end >= 0 && (*str)[end] == ' ')
		end--;
	if (end < 0)
		return (ft_strndup("", 0));
	return (ft_strndup(*str, end + 1));
}

t_list	*parse_entry(char **str, t_list *head)
{
	char	*key;
	char	*val;
	int		v_len;
	t_list	*node;

	key = extract_key(str);
	if (!key || *((*str)++) != ':')
		return (0);
	val = extract_value(str, &v_len);
	if (!val)
	{
		free(key);
		return (0);
	}
	*str += v_len;
	node = add_elem(head, key, val);
	if (node && head)
		head->next = node;
	return (node);
}

t_list	*parse_dict(char *str, t_list *head)
{
	char	*p;

	while (str && *str)
	{
		p = str;
		if (*p == '\n')
		{
			str = p + 1;
			continue ;
		}
		head = parse_entry(&str, head);
		if (!head)
		{
			free(head);
			return (0);
		}
	}
	while (head && head->previous)
		head = head->previous;
	return (head);
}
