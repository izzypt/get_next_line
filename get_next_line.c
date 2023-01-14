/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:25:52 by smagalha          #+#    #+#             */
/*   Updated: 2023/01/14 20:36:16 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	counter;

	counter = 0;
	while (s[counter])
	{
		counter++;
	}
	return (counter);
}

int	ft_strlcpy(char *dst, const char *src, int dstsize)
{
	int	len_src;
	int	i;

	len_src = ft_strlen(src);
	i = 0;
	if (dstsize != 0)
	{
		while (i < dstsize - 1 && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (len_src);
}

char	*handle_line(char *buffer, int line_size)
{
	static char	*stash;
	static char	*line;
	int			counter;
	int			counter2;

	counter = 0;
	counter2 = 0;
	if (stash)
	{
		line = malloc((sizeof(char) * line_size) + ft_strlen(stash));
		counter2 = ft_strlcpy(line, stash, ft_strlen(stash) + 1);
	}
	else
		line = malloc(sizeof(char) * line_size);
	while (counter <= line_size)
		line[counter2++] = buffer[counter++];
	if (BUFFER_SIZE > line_size)
	{
		stash = malloc(sizeof(char) * BUFFER_SIZE - line_size);
		counter2 = 0;
		while (buffer[counter])
			stash[counter2++] = buffer[counter++];
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char			*buffer;
	int				i;

	i = 0;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	read(fd, buffer, BUFFER_SIZE);
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (handle_line(buffer, i));
		i++;
	}
	return (buffer);
}

void	main(void)
{
	int		fd;

	fd = open("poema.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
}
