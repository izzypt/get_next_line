#include <stdio.h>
#include <fcntl.h> 
#include <unistd.h>
#include <stdlib.h>

int BUFFER_SIZE = 5;

size_t	ft_strlen(const char *s)
{
	int	counter;

	counter = 0;
	if (!s)
		return (0);
	while (s[counter])
	{
		counter++;
	}
	return (counter);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	len_src;
	size_t	i;

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

char	*ft_strjoin(char *prefix, char *suffix)
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

int	new_line_in_stash(char *stash)
{
	int	i;

	i = 0;
	while (stash[i])
	{
		if (stash[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*stash_leftovers(char *stash, int nl_pos)
{
	int		i;
	char	*temp;

	i = 0;
	temp = malloc(sizeof(char) * (ft_strlen(stash) - nl_pos + 1));
	while (stash[nl_pos])
	{
		temp[i] = stash[nl_pos];
		i++;
		nl_pos++;
	}
	ft_strlcpy(stash, temp, ft_strlen(temp) + 1);
	free(temp);
	return (stash);
}

char	*return_line_from_stash(char *stash)
{
	char	*line;
	int		i;
	int		toggle;

	i = 0;
	toggle = 0;
	while (stash[i])
	{
		if (stash[i] == '\n' && !toggle)
		{
			line = malloc(sizeof(char) * i + 1);
			toggle = 1;
			i = 0;
		}
		if (stash[i] != '\n' && toggle)
			line[i] = stash[i];
		if (stash[i] == '\n' && toggle)
		{
			line[i] = stash[i];
			line[i + 1] = '\0';
			stash_leftovers(stash, i + 1);
			return (line);
		}
		i++;
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	char			buffer[BUFFER_SIZE + 1];
	static char		*stash;
	static int		file_end;
	int				char_read;

	char_read = 1;
	if (char_read > 0)
		char_read = read(fd, buffer, BUFFER_SIZE);
	stash = ft_strjoin(stash, buffer);
	if (new_line_in_stash(stash))
		return (return_line_from_stash(stash));
	if (char_read > 0)
		get_next_line(fd);
	else
	{
		if (file_end != 1)
		{
			file_end = 1;
			return stash;
		}
		else
			return (NULL);	
	}
}

int main()
{
    int fd;
    //char texto[20] = "Um quebra de linha\n";

    fd = open("poema.txt", O_RDONLY);
    /*get_next_line(fd);
    get_next_line(fd);*/
    printf("LINE: %s", get_next_line(fd));
    printf("LINE: %s", get_next_line(fd));
    printf("LINE: %s", get_next_line(fd));
    printf("LINE: %s", get_next_line(fd));
    printf("LINE: %s", get_next_line(fd));
    printf("LINE: %s", get_next_line(fd));
    printf("LINE: %s", get_next_line(fd));
    printf("LINE: %s", get_next_line(fd));
    printf("LINE: %s", get_next_line(fd));
	printf("LINE: %s", get_next_line(fd));
	printf("LINE: %s", get_next_line(fd));
    /*printf("LINE: %s", get_next_line(fd));
    printf("LINE: %s", get_next_line(fd));
    printf("LINE: %s", get_next_line(fd));
    if (new_line_in_stash(texto))
        printf("tem quebra de linha");
    else
        printf("Nao tem quebra de linha");*/
    return 0;
}
