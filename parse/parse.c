/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-oul <yait-oul@student.1337.ma >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 15:18:09 by fhihi             #+#    #+#             */
/*   Updated: 2023/09/12 23:29:02 by yait-oul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vectors.h"

void	ft_error(t_units *un)
{
	ft_printf("Error\n");
	ft_printf("Make sure that u passed the file and it exits ");
	ft_printf("and has the right format [ *.rt ]\n");
	ft_printf("How to set up the file you ask?\n");
	ft_printf("Here is guide to help you with it\n");
	ft_printf("An identifier followed by specific info about each object\n");
	free_un(un);
	exit(EXIT_FAILURE);
}

void	check_str(char *s, t_units **un)
{
	char	**tmp;
	int		id;
	int		i;

	if (!s || !s[0] || s[0] == '\n')
		return ;
	s = ft_strtrim(s, "\n");
	tmp = ft_split(s, ' ');
	id = check_id(tmp[0]);
	if (!id)
		ft_error(*un);
	i = 0;
	while (tmp[i])
		i++;
	ft_set(tmp, i, un);
	free_arr(tmp);
	free(s);
}

void	init_units(t_units **un)
{
	(*un)->obj.cy = NULL;
	(*un)->obj.sp = NULL;
	(*un)->obj.pl = NULL;
}

t_units	*parse_file(char *file)
{
	int		fd;
	t_units	*un;
	char	*s;

	un = NULL;
	if (!file)
		ft_error(un);
	un = (t_units *)malloc(sizeof(t_units));
	if (!un)
		return (NULL);
	init_units(&un);
	fd = check_open(file, un);
	s = get_next_line(fd);
	while (s)
	{
		check_str(s, &un);
		free(s);
		s = get_next_line(fd);
	}
	return (un);
}
