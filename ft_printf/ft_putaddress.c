/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewolfghe <ewolfghe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 17:15:05 by ewolfghe          #+#    #+#             */
/*   Updated: 2022/10/12 17:22:27 by ewolfghe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putaddress(unsigned long int n)
{
	int	len;

	if (n == 0)
		len = ft_putstr("(nil)");
	else
	{
		len = ft_putstr("0x");
		len = len + ft_puthex(n, 'x');
	}
	return (len);
}
