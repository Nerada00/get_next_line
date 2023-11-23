#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_list
{
	void	*content;
	struct s_list	*next;
}t_list;

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char    *ft_substr(char const *s, unsigned int start, size_t len);
int	ft_strlen(char *str);
char	*ft_strdup(char *str);

#endif
