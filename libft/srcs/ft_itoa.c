/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/05 15:33:15 by cdeniau           #+#    #+#             */
/*   Updated: 2015/01/05 16:02:25 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_itoa(int n)
{
	char	*ret;
	int		tmp;
	size_t	len;
	char	pos;

	pos = 1;
	if (n < 0)
		pos = -1;
	len = 2 + (n < 0);
	tmp = n;
	while (n /= 10)
		len++;
	n = tmp;
	if (!(ret = (char *)malloc(sizeof(char) * len--)))
		return (NULL);
	ret[len--] = '\0';
	ret[len--] = pos * (n % 10) + '0';
	while (n /= 10)
		ret[len--] = pos * (n % 10) + '0';
	if (pos < 0)
		ret[len] = '-';
	return (ret);
}
