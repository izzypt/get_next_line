/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 18:29:21 by simao             #+#    #+#             */
/*   Updated: 2023/01/16 00:08:12 by simao            ###   ########.fr       */
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

int	find_new_line(char *buffer)
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

char	*teste(int fd)
{
	char		*buffer;
	char		*buffer2;
	int			nl_present;
	int			updated_buffer;
	int			position;
	static char	*stash;

	stash = malloc(sizeof(char) * BUFFER_SIZE);
	updated_buffer = BUFFER_SIZE;
	buffer = malloc(sizeof(char) * BUFFER_SIZE);
	read(fd, buffer, BUFFER_SIZE);
	nl_present = find_new_line(buffer);
	while (!nl_present)
	{
		updated_buffer++;
		buffer2 = malloc(sizeof(char) * updated_buffer);
		read(fd, buffer2, updated_buffer);
		stash = ft_strjoin(buffer, buffer2);
		buffer = stash;
		nl_present = find_new_line(stash);
	}
	return (buffer);
}

int	main(void)
{
	int		fd;

	fd = open("poema.txt", O_RDONLY);
	printf("%s", teste(fd));
	printf("%s", teste(fd));
	printf("%s", teste(fd));
	return (0);
}