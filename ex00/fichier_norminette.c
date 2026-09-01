/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fichier_norminette.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mharribe <mharribe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 18:42:33 by mharribe          #+#    #+#             */
/*   Updated: 2026/08/30 18:45:03 by mharribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <unistd.h>

int	print_val(t_list *dict, char *key, int *first);

int	fonction_norminette(int first, t_list *dict)
{
	if (first && !print_val(dict, "0", &first))
		return (0);
	write(1, "\n", 1);
	return (1);
}
