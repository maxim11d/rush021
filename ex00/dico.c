/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dico.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mharribe <mharribe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 17:44:52 by mharribe          #+#    #+#             */
/*   Updated: 2026/08/30 17:46:24 by mharribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int		file_size(char *str);
char	*return_str(char *str);

// int	main(int argc, char **argv)
// {
// 	char	*buff;

// 	if (argc == 2)
// 		buff = return_str("numbers.dict");
// 	else if (argc == 3)
// 		buff = return_str(argv[1]);
// 	else
// 	{
// 		write(1, "Error", 5);
// 		return (0);
// 	}
// 	if (!buff)
// 		return (0);
// 	printf("%s", buff);
// 	free(buff);
// 	return (0);
// }

int	file_size(char *str)
{
	int		file;
	char	buffer[512];
	int		bytes;
	int		count;

	count = 0;
	file = open(str, O_RDONLY);
	if (file == -1)
		return (-1);
	bytes = read(file, buffer, 512);
	while (bytes > 0)
	{
		count += bytes;
		bytes = read(file, buffer, 512);
	}
	close(file);
	if (bytes == -1)
		return (-1);
	return (count);
}

char	*return_str(char *str)
{
	int		file;
	int		count;
	char	*buff;

	count = file_size(str);
	if (count == -1)
		return (NULL);
	buff = malloc((count + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	file = open(str, O_RDONLY);
	if (file == -1)
	{
		free(buff);
		return (NULL);
	}
	if (read(file, buff, count) == -1)
		return (close(file), free(buff), NULL);
	buff[count] = '\0';
	close(file);
	return (buff);
}
