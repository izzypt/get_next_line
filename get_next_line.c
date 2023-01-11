/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagalha <smagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:25:52 by smagalha          #+#    #+#             */
/*   Updated: 2023/01/11 20:02:00 by smagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h> 
#include <unistd.h>
#include <stdlib.h>

int	get_next_line(int fd)
{
	char	*buffer;
	int		i;

	i = 0;
	buffer = malloc(sizeof(char) * (10 + 1));
	if (!buffer)
		return (0);
	read(fd, buffer, 10);
	while (buffer[i] != '\0')
	{
		write(1, &buffer[i], 1);
		i++;
	}
	return (0);
}

void	main(void)
{
	int		fd;

	fd = open("poema.txt", O_RDONLY);
	get_next_line(fd);
}