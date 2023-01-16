/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testando.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:25:52 by smagalha          #+#    #+#             */
/*   Updated: 2023/01/16 00:07:25 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	counter;

	counter = 0;
	while (s[counter])
		counter++;

	return (counter);
}

int	new_line(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	new_line_pos(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
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

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*p;
	unsigned char	*d;

	if (!dest && !src)
		return (NULL);
	p = (unsigned char *) src;
	d = (unsigned char *) dest;
	while (n > 0)
	{
		*d = *p;
		p++;
		d++;
		n--;
	}
	return (dest);
}

char	*ft_strjoin(char const *prefix, char const *suffix)
{
	size_t	len_prefix;
	size_t	len_suffix;
	char	*buffer;

	len_prefix = ft_strlen(prefix);
	len_suffix = ft_strlen(suffix);
	buffer = (char *)malloc(len_prefix + len_suffix + 1);
	if (!buffer)
		return (NULL);
	ft_memcpy(buffer, (const void *)prefix, len_prefix);
	ft_memcpy(&buffer[len_prefix], (const void *)suffix, len_suffix);
	buffer[len_prefix + len_suffix] = '\0';
	return ((char *)buffer);
}

char	*handle_line(char *buffer, int nl_pos)
{
	char	*stash;
	char	*line;
	int		counter;
	int		counter2;

	counter = 0;
	counter2 = 0;
	line = malloc(sizeof(char) * nl_pos);
	if (stash)
	{
		free(line);
		line = malloc(sizeof(char) * (strlen(stash) + strlen(nl_pos)));
	}
	while (buffer <= nl_pos)
	{
		line[counter] = buffer[counter];
		counter++;
	}
	if (BUFFER_SIZE - nl_pos > 0)
	{
		stash = malloc(sizeof(char) * BUFFER_SIZE - nl_pos);
		while (buffer[counter] != '\n' || buffer[counter])
			stash[counter2++] = buffer[counter++];
	}
	free(buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	char	*buffer;
	char	*stash;

	buffer = malloc(sizeof(char) * BUFFER_SIZE);
	read(fd, buffer, BUFFER_SIZE);
	if (new_line(buffer))
		*handle_line(buffer, new_line_pos(buffer));
	else
		printf("there is no new line\n");
	return (buffer);
}

void	main(void)
{
	int		fd;

	fd = open("poema.txt", O_RDONLY);
	//printf("%s", get_next_line(fd));
	//printf("%s", get_next_line(fd));
	get_next_line(fd);
	get_next_line(fd);
}