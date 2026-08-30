/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsaulni <arsaulni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 19:58:02 by arsaulni          #+#    #+#             */
/*   Updated: 2026/08/30 13:57:00 by arsaulni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

char	*read_full_file(char *filepath);
t_list	*parse_dict(char *str, t_list *head);
void	free_list(t_list *elem);
int	print_dict_nbr(t_list *dict, char *str);

void	print_dico(t_list *dico)
{
	while (dico->next)
	{
		printf("key: %s, value: %s\n", dico->key, dico->value);
		dico = dico->next;
	}
}

int	main(int ac, char **av)
{
	t_list	*dico;
	char	*dico_str;

	if (ac > 3)
		return (0);
	dico_str = read_full_file(av[1]);
	if (!dico_str)
		return (0);
	printf("%s\n", dico_str);
	dico = 0;
	dico = parse_dict(dico_str, dico);
	print_dico(dico);
	print_dict_nbr(dico, av[2]);
	free_list(dico);
	free(dico_str);
	return (0);
}
