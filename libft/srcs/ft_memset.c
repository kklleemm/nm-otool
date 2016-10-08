/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/08 13:45:47 by cdeniau           #+#    #+#             */
/*   Updated: 2016/10/08 16:46:26 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned long	ul;
	unsigned long	*pul;
	char			*s;

	ul = (char)c;
	ul = ul | (ul << 8);
	ul = ul | (ul << 16);
	ul = ul | (ul << 32);
	pul = (unsigned long *)b;
	while (len > 8)
	{
		*pul = ul;
		pul++;
		len -= 8;
	}
	s = (char *)pul;
	while (len)
	{
		*s = (char)c;
		s++;
		len--;
	}
	return (b);
}
