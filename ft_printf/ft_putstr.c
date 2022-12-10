/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewolfghe <ewolfghe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 17:13:41 by ewolfghe          #+#    #+#             */
/*   Updated: 2022/10/12 17:13:52 by ewolfghe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	len;

	len = 0;
	if (str)
	{
		while (str[len])
		{
			write(1, &str[len], 1);
			len++;
		}
	}
	else
		len = len + ft_putstr("(null)");
	return (len);
}
