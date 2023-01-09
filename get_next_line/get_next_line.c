/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewolfghe <ewolfghe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 23:03:11 by ewolfghe          #+#    #+#             */
/*   Updated: 2022/12/10 18:34:02 by ewolfghe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line_extras(char **str);
void	ft_free_gnl(char **s);

char	*get_next_line(int fd)
{
	static char	*s;
	char		*str;
	char		*aux;
	size_t		rd;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0))
		return (NULL);
	str = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	rd = read(fd, str, BUFFER_SIZE);
	while (rd > 0)
	{
		str[rd] = '\0';
		if (s != NULL)
		{
			aux = ft_strjoin_gnl(s, str);
			ft_free_gnl(&s);
			s = aux;
		}
		else
			s = ft_strdup_gnl(str);
		if (ft_strchr_gnl(s, '\n'))
			break ;
		rd = read(fd, str, BUFFER_SIZE);
	}
	return (ft_free_gnl(&str), get_line_extras(&s));
}

char	*get_line_extras(char **s)
{
	char	*str;
	char	*aux;
	size_t	i;

	if (s[0] == NULL)
		return (NULL);
	i = 0;
	while (s[0][i] != '\n' && s[0][i] != '\0')
		i++;
	aux = ft_strdup_gnl(s[0]);
	str = ft_substr_gnl(s[0], 0, i + 1);
	ft_free_gnl(s);
	s[0] = ft_substr_gnl(aux, i + 1, ft_strlen_gnl(aux));
	ft_free_gnl(&aux);
	if (!(ft_strchr_gnl(str, '\n')))
	{
		ft_free_gnl(s);
		if (!ft_strlen_gnl(str))
			ft_free_gnl(&str);
	}
	return (str);
}

void	ft_free_gnl(char **s)
{
	if (s[0])
	{
		free(s[0]);
		s[0] = NULL;
	}
}
