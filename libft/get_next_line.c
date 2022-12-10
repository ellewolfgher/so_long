/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewolfghe <ewolfghe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 22:07:55 by ewolfghe          #+#    #+#             */
/*   Updated: 2022/11/27 11:57:11 by ewolfghe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_line_extras(char **str);
void	ft_free(char **s);

char	*get_next_line(int fd)
{
	static char	*s[1024];
	char		*str;
	char		*aux;
	size_t		rd;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE < 1 || read(fd, 0, 0))
		return (NULL);
	str = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	rd = read(fd, str, BUFFER_SIZE);
	while (rd > 0)
	{
		str[rd] = '\0';
		if (s[fd] != NULL)
		{
			aux = ft_strjoin(s[fd], str);
			ft_free(&s[fd]);
			s[fd] = aux;
		}
		else
			s[fd] = ft_strdup(str);
		if (ft_strchr(s[fd], '\n'))
			break ;
		rd = read(fd, str, BUFFER_SIZE);
	}
	return (ft_free(&str), get_line_extras(&s[fd]));
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
	aux = ft_strdup(s[0]);
	str = ft_substr(s[0], 0, i + 1);
	ft_free(s);
	s[0] = ft_substr(aux, i + 1, ft_strlen(aux));
	ft_free(&aux);
	if (!(ft_strchr(str, '\n')))
	{
		ft_free(s);
		if (!ft_strlen(str))
			ft_free(&str);
	}
	return (str);
}

void	ft_free(char **s)
{
	if (s[0])
	{
		free(s[0]);
		s[0] = NULL;
	}
}
