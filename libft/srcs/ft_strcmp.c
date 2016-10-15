/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/04 18:16:49 by cdeniau           #+#    #+#             */
/*   Updated: 2015/06/07 14:07:43 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	len1;
	unsigned int	len2;

	if (!s1)
		return (-1);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (len1 <= len2)
		return (ft_memcmp(s1, s2, len1 + 1));
	else
		return (ft_memcmp(s1, s2, len2 + 1));
}
