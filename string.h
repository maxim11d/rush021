/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsaulni <arsaulni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 20:15:28 by arsaulni          #+#    #+#             */
/*   Updated: 2026/08/30 13:57:18 by arsaulni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_H
# define STRING_H

int	ft_strlen(char *str);
int	ft_strcmp(char *s1, char *s2);
void	ft_putstr(char *str);
char	*ft_strndup(char *src, int n);

#endif
