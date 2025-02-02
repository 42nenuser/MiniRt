/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhihi <fhihi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:05:39 by fhihi             #+#    #+#             */
/*   Updated: 2023/09/11 21:07:18 by fhihi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*return_line(char *line)
{
	int		i;
	char	*s;

	i = 0;
	if (!line[i])
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	s = (char *)malloc(i * sizeof(char ) + 2);
	if (!s)
		return (NULL);
	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
		{
			s[i] = line[i];
			i++;
			break ;
		}
		s[i] = line[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*left(char *line)
{
	char	*s;
	int		i;
	int		j;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i] || (line[i] == '\n' && line [i + 1] == '\0'))
	{
		free(line);
		return (NULL);
	}
	s = (char *)malloc((ft_strlen2(line) - i) * sizeof(char ));
	if (!s)
	{
		free(line);
		return (NULL);
	}
	i++;
	j = 0;
	while (line[i])
		s[j++] = line[i++];
	s[j] = '\0';
	free(line);
	return (s);
}

char	*was_read(int fd, char *lft)
{
	char		buf[BUFFER_SIZE + 1];
	int			red;

	red = 1;
	while (red != 0)
	{
		red = read(fd, buf, BUFFER_SIZE);
		if (red <= 0)
		{
			break ;
		}
		buf[red] = '\0';
		lft = ft_strjoin2(lft, buf);
		if (ft_strchr2(buf, '\n'))
			break ;
	}
	return (lft);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*lft;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd == 1 || fd == 2)
		return (NULL);
	lft = was_read(fd, lft);
	if (!lft)
		return (NULL);
	line = return_line(lft);
	lft = left(lft);
	return (line);
}

// int	main(void)
// {
// 	int		fd;

// 	fd = open("test.txt", O_RDONLY);
// 	printf(":%s:", get_next_line(fd));
// 	// check_leaks();
// 	return (0);
// }
