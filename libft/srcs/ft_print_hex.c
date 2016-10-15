/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/08 13:40:03 by cdeniau           #+#    #+#             */
/*   Updated: 2016/10/15 16:04:37 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					ft_print_hex(void *ptr)
{
	unsigned long long	address;
	char				str[10];
	char				*base;
	int					i;

	ft_memset(str, 0, 10);
	i = 8;
	base = "0123456789ABCDEF";
	address = (unsigned long long)ptr;
	if (!address)
		return;
	while (address)
	{
		str[i] = base[address % 16];
		address = address / 16;
		i--;
	}
	if (ft_strlen(str) != 0)
	{
		ft_putstr("0000000");
		ft_putstr(str);
	}
	write (1, " ", 1);
}
