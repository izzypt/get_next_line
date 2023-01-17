/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagalha <smagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:25:52 by smagalha          #+#    #+#             */
/*   Updated: 2023/01/17 18:24:53 by smagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	theres_no_nl(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

int	ft_strlen(const char *s)
{
	int	counter;

	counter = 0;
	while (s[counter])
		counter++;

	return (counter);
}

char	*save_leftovers(char *buffer, int pos)
{
	char	*leftovers;
	int		i;

	i = 0;
	if (ft_strlen(buffer) > pos)
		leftovers = malloc(sizeof(char) * (ft_strlen(buffer) - pos));
	while (buffer[pos])
		leftovers[i++] = buffer[pos++];
	return (leftovers);
}

char	*ft_strjoin(char *prefix, char *suffix)
{
	char		*new_str;
	int			i;
	int			j;
	char		*stash;

	if (stash == NULL)
		printf("stash n exist\n");
	else
		stash = ft_strjoin(stash, prefix);

	printf("stash : %s\n", stash);
	i = 0;
	j = 0;
	new_str = (char *)malloc(ft_strlen(prefix) + ft_strlen(suffix) + 1);
	if (!new_str)
		return (NULL);
	while (prefix[i])
	{
		new_str[i] = prefix[i];
		i++;
	}
	free(prefix);
	while (suffix[j])
	{
		new_str[i++] = suffix[j++];
		if (suffix[j - 1] == '\n')
			break ;
	}
	stash = save_leftovers(suffix, i);
	return (new_str);
}


char	*copy_line()
{
	
}

char	*get_next_line(int fd)
{
	char			*buffer;
	char			*line;
	int				chars_read;
	static char		*stash;

	read(fd, buffer, BUFFER_SIZE);
	while (theres_no_nl(buffer))
	{
		read(fd, buffer, BUFFER_SIZE);
		line = ft_strjoin(line, buffer);
	}
	return (line);
}

int	main(void)
{
	int		fd;
	fd = open("poema.txt", O_RDONLY);
	//printf("%s", get_next_line(fd));
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	return (0);
}