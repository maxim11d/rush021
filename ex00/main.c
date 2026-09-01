/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mharribe <mharribe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 17:34:10 by mharribe          #+#    #+#             */
/*   Updated: 2026/08/30 19:24:18 by mharribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include <unistd.h>

char	*return_str(char *str);
t_list	*parse_dict(char *str, t_list *head);
void	free_list(t_list *elem);
int		print_dict_nbr(t_list *dict, char *str);
int		check_nbr(char *nbr);
int		check_overflow(char *nbr, t_list *dict);

// void	print_dico(t_list *dico)
// {
// 	while (dico->next)
// 	{
// 		printf("key: %s, value: %s\n", dico->key, dico->value);
// 		dico = dico->next;
// 	}
// }

int	do_stuff(char *dico_str, char *input_nbr)
{
	t_list	*dico;

	dico = 0;
	dico = parse_dict(dico_str, dico);
	if (!dico)
	{
		write(1, "Dict Error\n", 11);
		return (0);
	}
	if (!check_nbr(input_nbr))
	{
		write(1, "Error\n", 6);
		free(dico);
		return (0);
	}
	if (!check_overflow(input_nbr, dico))
	{
		write(1, "Dict Error\n", 11);
		free(dico);
		return (0);
	}
	print_dict_nbr(dico, input_nbr);
	free_list(dico);
	return (0);
}

int	main(int ac, char **av)
{
	char	*dico_str;

	if (ac > 3)
		return (0);
	if (ac == 2)
		dico_str = return_str("numbers.dict");
	else
		dico_str = return_str(av[1]);
	if (!dico_str)
	{
		write(1, "Dict Error\n", 11);
		return (0);
	}
	do_stuff(dico_str, av[ac - 1]);
	free(dico_str);
	return (0);
}
