/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdutruel <mdutruel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 20:18:02 by arsaulni          #+#    #+#             */
/*   Updated: 2026/08/30 15:41:39 by mdutruel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "list.h"

int	print_val(t_list *dict, char *key, int *first)
{
	int	i;

	while (dict)
	{
		i = 0;
		while (dict->key[i] && key[i] && dict->key[i] == key[i])
			i++;
		if (dict->key[i] == '\0' && key[i] == '\0')
			break ;
		dict = dict->next;
	}
	if (!dict)
		return (0);
	if (!*first)
		write(1, " ", 1);
	*first = 0;
	i = 0;
	while (dict->value[i])
		write(1, &dict->value[i++], 1);
	return (1);
}

int	print_tens(t_list *dict, int n, int *first)
{
	char	k[4];

	if (n >= 20)
	{
		k[0] = (n / 10) + '0';
		k[1] = '0';
		k[2] = '\0';
		if (!print_val(dict, k, first))
			return (0);
		n %= 10;
	}
	else if (n >= 10)
	{
		k[0] = '1';
		k[1] = (n - 10) + '0';
		k[2] = '\0';
		return (print_val(dict, k, first));
	}
	if (n > 0)
	{
		k[0] = n + '0';
		k[1] = '\0';
		return (print_val(dict, k, first));
	}
	return (1);
}

int	print_under_1000(t_list *dict, int n, int *first)
{
	char	k[2];

	if (n >= 100)
	{
		k[0] = (n / 100) + '0';
		k[1] = '\0';
		if (!print_val(dict, k, first) || !print_val(dict, "100", first))
			return (0);
		n %= 100;
	}
	return (print_tens(dict, n, first));
}

int	print_scale(t_list *dict, int zeros, int *first)
{
	char	*scale;
	int		i;
	int		res;

	if (zeros == 0)
		return (1);
	scale = (char *)malloc(sizeof(char) * (zeros + 2));
	if (!scale)
		return (0);
	scale[0] = '1';
	i = 1;
	while (i <= zeros)
		scale[i++] = '0';
	scale[i] = '\0';
	res = print_val(dict, scale, first);
	free(scale);
	return (res);
}

int	print_dict_nbr(t_list *dict, char *str)
{
	int	len;
	int	g_len;
	int	g_val;
	int	first;

	first = 1;
	len = 0;
	while (str[len])
		len++;
	while (len > 0)
	{
		g_len = len % 3;
		if (g_len == 0)
			g_len = 3;
		g_val = 0;
		while (g_len--)
		{
			g_val = g_val * 10 + (*str++ - '0');
			len--;
		}
		if (g_val > 0 && (!print_under_1000(dict, g_val, &first)
				|| !print_scale(dict, len, &first)))
			return (0);
	}
	if (first && !print_val(dict, "0", &first))
		return (0);
	write(1, "\n", 1);
	return (1);
}