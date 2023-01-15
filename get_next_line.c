/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:25:52 by smagalha          #+#    #+#             */
/*   Updated: 2023/01/15 13:53:17 by simao            ###   ########.fr       */
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

char	*handle_line(char *buffer, int line_size)
{
	static char	*stash;
	char		*line;
	int			counter;
	int			counter2;

	counter = 0;
	counter2 = 0;
	line = malloc(sizeof(char) * line_size);
	if (stash)
	{
		line = malloc((sizeof(char) * line_size) + ft_strlen(stash));
		counter2 = ft_strlcpy(line, stash, ft_strlen(stash) + 1);
	}
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

char	*save_text(char	*text)
{
	static char	*temp;
	static char	line;
	int			counter;

	counter = 0;
	temp = malloc(sizeof(char) * ft_strlen(text));
	if (temp)
		ft_strjoin(temp, text);
	return (temp);
}

char	*get_next_line(int fd)
{
	char			*buffer;
	int				i;
	int				flag;

	i = 0;
	flag = 0;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	read(fd, buffer, BUFFER_SIZE);
	while (buffer[i])
	{
		if (buffer[i] == '\n')
		{
			flag = 1;
			return (handle_line(buffer, i));
		}
		i++;
	}
	if (flag == 0)
		return (save_text(buffer));
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
