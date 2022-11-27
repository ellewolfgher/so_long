/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewolfghe <ewolfghe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 18:01:46 by ewolfghe          #+#    #+#             */
/*   Updated: 2022/11/27 11:52:56 by ewolfghe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	aux;
	size_t	size;

	if (!s)
		return (NULL);
	size = ft_strlen(s);
	if (start >= size)
		aux = 1;
	else if (len >= size)
		aux = size - start + 1;
	else
		aux = len + 1;
	sub = (char *)malloc(aux);
	if (!sub)
		return (NULL);
	i = 0;
	while ((start < size) && (i < len))
	{
		sub[i] = s[start];
		start++;
		i++;
	}
	sub[i] = 0;
	return (sub);
}

/* char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
	{
		len = 0;
		start = ft_strlen(s);
	}
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	sub = (char *)malloc(len + 1);
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, (s + start), len + 1);
	return (sub);
} */

/* Another version of substr but without the use of ft_strlcpy that I redid to use in my get_next_line function before adding it to my libft */

/* char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	aux;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		aux = 1;
	else if (len >= ft_strlen(s))
		aux = ft_strlen(s) - start + 1;
	else
		aux = len + 1;
	sub = (char *)malloc(aux);
	if (!sub)
		return (NULL);
	i = 0;
	while ((start < ft_strlen(s)) && (i < len))
	{
		sub[i] = s[start];
		start++;
		i++;
	}
	sub[i] = 0;
	return (sub);
} */
