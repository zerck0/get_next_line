#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>

char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *str);
void	*ft_calloc(size_t count, size_t size);
char	*get_next_line(int fd);
char	*ft_strchr(const char *str, int c);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);

#endif
