#include "get_next_line.h"

int	ft_check_line(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_new_line(char *str)
{
	int	i;

	i = 0;
	while (str && str[i] != '\n')
		i++;
	return (i);
}

char	*get_next_line(int fd)
{
	char		*buf;
	char		*tmp;
	static	char	*stock;
	int		reader = 1;
	char		*ret;

	if (BUFFER_SIZE < 1 || fd > 1024 || fd < 0)
		return (NULL);
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while (ft_check_line(buf, '\n') == 0 && reader > 0)
	{	
		reader = read(fd, buf, BUFFER_SIZE);
		if (reader == -1)
			return (free(buf), NULL);
		tmp = stock;
		buf[reader] = '\0';
		stock = ft_strjoin(tmp, buf);
	}
	ret = ft_substr(stock, 0, ft_new_line(stock) + 1);
	tmp = stock;
	stock = ft_substr(tmp, ft_new_line(tmp) + 1, (ft_strlen(tmp) - ft_new_line(tmp)));
	return (free(tmp), free(buf), ret);
}

/*int main ()
{
 	int	fd = open("fd.txt", O_RDONLY);
	char *str = NULL; 
	get_next_line(fd);

 	while ((str = get_next_line(fd)))
 	{
 		printf("%s" , str);
 		free(str);
 	}
 	free(str);	
}*/
