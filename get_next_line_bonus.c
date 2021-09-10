/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorgin <tgeorgin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 17:35:53 by tgeorgin          #+#    #+#             */
/*   Updated: 2021/09/10 18:20:02 by tgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*line_to_ret(char *save)
{
	char	*line;
	int		i;

	i = 0;
	if (!save)
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	if (save[i] == '\n')
		i++;
	line = (char *)ft_calloc((i + 1), sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		line[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
		line[i] = save[i];
	return (line);
}

char	*after_nl(char *save)
{
	char	*next_lines;
	int		i;
	int		j;

	i = 0;
	if (!save)
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	next_lines = (char *)ft_calloc((ft_strlen(save) - i), sizeof(char));
	if (!next_lines)
		return (NULL);
	i++;
	j = 0;
	while (save[i] != '\0')
		next_lines[j++] = save[i++];
	free(save);
	return (next_lines);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	str = (char *)ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	free(s1);
	return (str);
}

char	*eof(char *save, ssize_t ret, char *line)
{
	if (!save && ret == 0 && ft_strlen(line) == 0)
	{
		free(line);
		return (NULL);
	}
	else
		return (line);
}

char	*get_next_line(int fd)
{
	static char	*save[1024];
	char		*buffer;
	ssize_t		ret;
	char		*line;

	buffer = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
		return (NULL);
	ret = 1;
	while (ret != 0 && !ft_strchr(save[fd], '\n'))
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[ret] = '\0';
		save[fd] = ft_strjoin(save[fd], buffer);
	}
	free(buffer);
	line = line_to_ret(save[fd]);
	save[fd] = after_nl(save[fd]);
	line = eof(save[fd], ret, line);
	return (line);
}
