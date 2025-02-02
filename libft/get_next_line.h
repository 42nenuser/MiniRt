/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhihi <fhihi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:05:27 by fhihi             #+#    #+#             */
/*   Updated: 2023/09/11 21:07:36 by fhihi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# define BUFFER_SIZE 5

char	*ft_strjoin2(char *s1, char *s2);
size_t	ft_strlen2(char *s);
char	*ft_strchr2(char *s, int c);
char	*get_next_line(int fd);
char	*return_line(char *line);
char	*left(char *line);

#endif