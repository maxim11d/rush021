/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mharribe <mharribe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 17:58:50 by mharribe          #+#    #+#             */
/*   Updated: 2026/08/30 19:05:51 by mharribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int		ft_strlen(char *str);

// enlever les espaces
char	*del_space(char *str)
{
	while (*str == ' ')
		str++;
	return (str);
}

int	check_nbr(char *nbr)
{
	if (*nbr == '0' && ft_strlen(nbr) > 1)
		return (0);
	while (*nbr)
	{
		if (*nbr < '0' || *nbr > '9')
			return (0);
		nbr++;
	}
	return (1);
}

int	check_overflow(char *nbr, t_list *dict)
{
	int	key_len;
	int	nb_len;

	nb_len = ft_strlen(nbr);
	key_len = 0;
	while (dict->next)
	{
		if (ft_strlen(dict->key) > key_len)
			key_len = ft_strlen(dict->key);
		dict = dict->next;
	}
	if (ft_strlen(dict->key) > key_len)
		key_len = ft_strlen(dict->key);
	if (nb_len > key_len + 2)
		return (0);
	return (1);
}
