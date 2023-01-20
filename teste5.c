#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int BUFFER_SIZE = 10000;

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
	if(!prefix)
	    1;
	else
	    free(prefix);
	return ((char *)buffer);
}

int get_nl_pos(char *stash)
{
    int i;
    
    i = 0;
    while (stash[i])
    {
        if (stash[i] == '\n')
            return (i);
        i++;
    }
    printf("Couldn't find new line in the string provided.");
    return (-1);
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

void    clean_stash(char *stash, char c, int n)
{
    while (n > 0)
    {
		*stash = c;
		stash++;
		n--;
	}
	
	//printf("Current stash status at clean_stash : %s\n", stash);
}

void    save_leftovers(char *stash, int nl_pos)
{
    char    *temp;
    int     stash_len;
    int     i;
    
    stash_len = ft_strlen(stash);
    if (nl_pos >= stash_len)
        printf("Something wrong with nl_pos, it is equal or greate than stash length");
    temp = malloc((stash_len - nl_pos + 2) * sizeof(char));
    i = 0;
    while (stash[nl_pos])
    {
        nl_pos++;
        temp[i] = stash[nl_pos];
        i++;
    }
    clean_stash(stash, '\0', stash_len);
    ft_memcpy(stash, temp, ft_strlen(temp));
    //printf("Current stash status at save_leftovers : %s\n", stash);
    free(temp);
    
}

char    *line_from_stash(char *stash, int nl_pos)
{
    char    *line;
    int     i;
    
    i = 0;
    line = malloc(sizeof(char) * (nl_pos + 2));
    while(i <= nl_pos)
    {
        line[i] = stash[i];
        i++;
    }
    line[i] = '\0';
    save_leftovers(stash, nl_pos);
    return (line);
    
}

char	*get_next_line(int fd)
{
	char			buffer[BUFFER_SIZE + 1];
	static char		*stash;
	int				chars_read;
	

	chars_read = read(fd, buffer, BUFFER_SIZE);
	stash = ft_strjoin(stash, buffer);
	while (!new_line_in_stash(stash))
	{
	    if (chars_read < 1)
	        break;
		read(fd, buffer, BUFFER_SIZE);
		stash = ft_strjoin(stash, buffer);
	}
	return (line_from_stash(stash, get_nl_pos(stash)));
}

int	main(void)
{
	int		fd;
	fd = open("poema.txt", O_RDONLY);
	//printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	/*get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);*/
	return (0);
}
